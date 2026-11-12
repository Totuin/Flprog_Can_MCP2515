#include "flprog_Can_MCP2515.h"
#include <assert.h>
#include <stdint.h>
#include <type_traits>

static_assert(FLPROG_MCP_CAN_CLOCK_20MHZ == FLPROG_MCP_20MHZ, "20 MHz ID");
static_assert(FLPROG_MCP_CAN_CLOCK_16MHZ == FLPROG_MCP_16MHZ, "16 MHz ID");
static_assert(FLPROG_MCP_CAN_CLOCK_8MHZ == FLPROG_MCP_8MHZ, "8 MHz ID");
static_assert(FLPROG_MCP_CAN_CLOCK_20MHZ != FLPROG_MCP_CAN_CLOCK_16MHZ, "distinct clocks");
static_assert(FLPROG_MCP_CAN_CLOCK_16MHZ != FLPROG_MCP_CAN_CLOCK_8MHZ, "distinct clocks");
static_assert(std::is_base_of<FLProgAbstractCanBus, FLProgMCP2515CanBus>::value,
              "Compatibility with Flprog_Can transport base");

struct ExpectedConfig {
    uint8_t clock; uint8_t speed;
    uint8_t cnf1; uint8_t cnf2; uint8_t cnf3;
    uint32_t rate; bool supported;
};

static const ExpectedConfig all[] = {
    {2, 15, 0x00, 0x80, 0x80, 1000000, false}, // 8 MHz, 1000kBPS
    {2, 10, 0x01, 0xB4, 0x86, 100000, true}, // 8 MHz, 100kBPS
    {2,  1, 0x0F, 0xBF, 0x87, 10000, true}, // 8 MHz, 10kBPS
    {2, 11, 0x01, 0xB1, 0x85, 125000, true}, // 8 MHz, 125kBPS
    {2, 12, 0x00, 0xB4, 0x86, 200000, true}, // 8 MHz, 200kBPS
    {2,  2, 0x07, 0xBF, 0x87, 20000, true}, // 8 MHz, 20kBPS
    {2, 13, 0x00, 0xB1, 0x85, 250000, true}, // 8 MHz, 250kBPS
    {2,  3, 0x07, 0xA4, 0x84, 31250, true}, // 8 MHz, 31k25BPS
    {2,  4, 0x47, 0xE2, 0x85, 33333, true}, // 8 MHz, 33k3BPS
    {2,  5, 0x03, 0xBF, 0x87, 40000, true}, // 8 MHz, 40kBPS
    {2, 14, 0x00, 0x90, 0x82, 500000, true}, // 8 MHz, 500kBPS
    {2,  6, 0x03, 0xB4, 0x86, 50000, true}, // 8 MHz, 50kBPS
    {2,  0, 0x1F, 0xBF, 0x87, 5000, true}, // 8 MHz, 5kBPS
    {2,  7, 0x01, 0xBF, 0x87, 80000, true}, // 8 MHz, 80kBPS
    {1, 15, 0x00, 0xD0, 0x82, 1000000, true}, // 16 MHz, 1000kBPS
    {1, 10, 0x03, 0xFA, 0x87, 100000, true}, // 16 MHz, 100kBPS
    {1,  1, 0x1F, 0xFF, 0x87, 10000, true}, // 16 MHz, 10kBPS
    {1, 11, 0x03, 0xF0, 0x86, 125000, true}, // 16 MHz, 125kBPS
    {1, 12, 0x01, 0xFA, 0x87, 200000, true}, // 16 MHz, 200kBPS
    {1,  2, 0x0F, 0xFF, 0x87, 20000, true}, // 16 MHz, 20kBPS
    {1, 13, 0x41, 0xF1, 0x85, 250000, true}, // 16 MHz, 250kBPS
    {1,  4, 0x4E, 0xF1, 0x85, 33333, true}, // 16 MHz, 33k3BPS
    {1,  5, 0x07, 0xFF, 0x87, 40000, true}, // 16 MHz, 40kBPS
    {1, 14, 0x00, 0xF0, 0x86, 500000, true}, // 16 MHz, 500kBPS
    {1,  6, 0x07, 0xFA, 0x87, 50000, true}, // 16 MHz, 50kBPS
    {1,  0, 0x3F, 0xFF, 0x87, 5000, true}, // 16 MHz, 5kBPS
    {1,  7, 0x03, 0xFF, 0x87, 80000, true}, // 16 MHz, 80kBPS
    {1,  8, 0x03, 0xBE, 0x07, 83333, true}, // 16 MHz, 83k3BPS
    {0, 15, 0x00, 0xD9, 0x82, 1000000, true}, // 20 MHz, 1000kBPS
    {0, 10, 0x04, 0xFA, 0x87, 100000, true}, // 20 MHz, 100kBPS
    {0, 11, 0x03, 0xFA, 0x87, 125000, true}, // 20 MHz, 125kBPS
    {0, 12, 0x01, 0xFF, 0x87, 200000, true}, // 20 MHz, 200kBPS
    {0, 13, 0x41, 0xFB, 0x86, 250000, true}, // 20 MHz, 250kBPS
    {0,  5, 0x09, 0xFF, 0x87, 40000, true}, // 20 MHz, 40kBPS
    {0, 14, 0x00, 0xFA, 0x87, 500000, true}, // 20 MHz, 500kBPS
    {0,  6, 0x09, 0xFA, 0x87, 50000, true}, // 20 MHz, 50kBPS
    {0,  7, 0x04, 0xFF, 0x87, 80000, true}, // 20 MHz, 80kBPS
};

static uint32_t calculatedBitrate(uint32_t fosc, const FLProgMCP2515BitTiming &cfg) {
    const uint32_t brp = (cfg.cnf1 & 0x3F) + 1;
    const uint32_t prop = (cfg.cnf2 & 0x07) + 1;
    const uint32_t ps1 = ((cfg.cnf2 >> 3) & 0x07) + 1;
    const uint32_t ps2 = (cfg.cnf2 & 0x80) ? ((cfg.cnf3 & 0x07) + 1) : (ps1 > 2 ? ps1 : 2);
    return fosc / (2 * brp * (1 + prop + ps1 + ps2));
}

int main() {
    for (const ExpectedConfig &expect : all) {
        FLProgMCP2515BitTiming actual = {0xAA, 0xBB, 0xCC};
        const bool ok = flprogMcp2515GetBitTiming(expect.clock, expect.speed, actual);
        assert(ok == expect.supported);
        if (ok) {
            assert(actual.cnf1 == expect.cnf1);
            assert(actual.cnf2 == expect.cnf2);
            assert(actual.cnf3 == expect.cnf3);
            uint32_t fosc = expect.clock == 0 ? 20000000 : (expect.clock == 1 ? 16000000 : 8000000);
            const uint32_t rate = calculatedBitrate(fosc, actual);
            assert(rate > expect.rate - 2 && rate < expect.rate + 2);
        } else {
            assert(actual.cnf1 == 0xAA && actual.cnf2 == 0xBB && actual.cnf3 == 0xCC);
        }
    }
    FLProgMCP2515BitTiming cfg = {0xAA, 0xBB, 0xCC};
    for (uint8_t clk = 0; clk < 3; ++clk) {
        assert(!flprogMcp2515GetBitTiming(clk, FLPROG_MCP_CAN_SPEED_95KBPS, cfg));
        assert(cfg.cnf1 == 0xAA && cfg.cnf2 == 0xBB && cfg.cnf3 == 0xCC);
    }
    assert(!flprogMcp2515GetBitTiming(255, FLPROG_MCP_CAN_SPEED_500KBPS, cfg));
    assert(!flprogMcp2515GetBitTiming(0, 255, cfg));
    assert(!flprogMcp2515GetBitTiming(1, FLPROG_MCP_CAN_SPEED_31K25BPS, cfg));
    assert(!flprogMcp2515GetBitTiming(2, FLPROG_MCP_CAN_SPEED_83K3BPS, cfg));
    assert(cfg.cnf1 == 0xAA && cfg.cnf2 == 0xBB && cfg.cnf3 == 0xCC);
}
