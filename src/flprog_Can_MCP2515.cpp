#include "flprog_Can_MCP2515.h"

// Только выбор регистров тайминга. SPI-обмен и CAN-транспорт здесь НЕ реализованы.
// При отсутствии настроек или недопустимом тайминге результат не изменяется.
bool flprogMcp2515GetBitTiming(uint8_t clock, uint8_t speed,
                               FLProgMCP2515BitTiming &result)
{
    FLProgMCP2515BitTiming chosen = {0, 0, 0};
    switch (clock)
    {
    case FLPROG_MCP_CAN_CLOCK_20MHZ:
        switch (speed)
        {
        case FLPROG_MCP_CAN_SPEED_1000KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_1000kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_1000kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_1000kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_500KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_500kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_500kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_500kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_250KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_250kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_250kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_250kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_200KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_200kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_200kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_200kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_125KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_125kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_125kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_125kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_100KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_100kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_100kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_100kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_80KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_80kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_80kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_80kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_50KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_50kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_50kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_50kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_40KBPS:
            chosen.cnf1 = FLPROG_MCP_20MHz_40kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_20MHz_40kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_20MHz_40kBPS_CFG3;
            break;
        default: return false; // Нет готовой таблицы для этого кварца.
        }
        break;
    case FLPROG_MCP_CAN_CLOCK_16MHZ:
        switch (speed)
        {
        case FLPROG_MCP_CAN_SPEED_1000KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_1000kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_1000kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_1000kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_500KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_500kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_500kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_500kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_250KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_250kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_250kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_250kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_200KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_200kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_200kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_200kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_125KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_125kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_125kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_125kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_100KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_100kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_100kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_100kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_80KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_80kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_80kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_80kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_83K3BPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_83k3BPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_83k3BPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_83k3BPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_50KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_50kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_50kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_50kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_40KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_40kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_40kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_40kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_33KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_33k3BPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_33k3BPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_33k3BPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_20KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_20kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_20kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_20kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_10KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_10kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_10kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_10kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_5KBPS:
            chosen.cnf1 = FLPROG_MCP_16MHz_5kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_16MHz_5kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_16MHz_5kBPS_CFG3;
            break;
        default: return false; // Нет готовой таблицы для этого кварца.
        }
        break;
    case FLPROG_MCP_CAN_CLOCK_8MHZ:
        switch (speed)
        {
        case FLPROG_MCP_CAN_SPEED_1000KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_1000kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_1000kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_1000kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_500KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_500kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_500kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_500kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_250KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_250kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_250kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_250kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_200KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_200kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_200kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_200kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_125KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_125kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_125kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_125kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_100KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_100kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_100kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_100kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_80KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_80kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_80kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_80kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_50KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_50kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_50kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_50kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_40KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_40kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_40kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_40kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_33KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_33k3BPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_33k3BPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_33k3BPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_31K25BPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_31k25BPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_31k25BPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_31k25BPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_20KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_20kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_20kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_20kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_10KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_10kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_10kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_10kBPS_CFG3;
            break;
        case FLPROG_MCP_CAN_SPEED_5KBPS:
            chosen.cnf1 = FLPROG_MCP_8MHz_5kBPS_CFG1;
            chosen.cnf2 = FLPROG_MCP_8MHz_5kBPS_CFG2;
            chosen.cnf3 = FLPROG_MCP_8MHz_5kBPS_CFG3;
            break;
        default: return false; // Нет готовой таблицы для этого кварца.
        }
        break;
    default: return false; // Неизвестная частота кварца.
    }

    // Проверка требований datasheet: PS2 >= 2 TQ, PS2 >= SJW,
    // PropSeg + PS1 >= PS2. Некорректная исходная таблица 8 МГц/1 Мбит/с
    // обнаруживается автоматически и не возвращается вызывающему коду.
    const uint8_t sjw = static_cast<uint8_t>(((chosen.cnf1 >> 6) & 0x03) + 1);
    const uint8_t propSeg = static_cast<uint8_t>((chosen.cnf2 & 0x07) + 1);
    const uint8_t ps1 = static_cast<uint8_t>(((chosen.cnf2 >> 3) & 0x07) + 1);
    const uint8_t ps2 = (chosen.cnf2 & 0x80)
                            ? static_cast<uint8_t>((chosen.cnf3 & 0x07) + 1)
                            : (ps1 > 2 ? ps1 : 2);
    if (ps2 < 2 || ps2 < sjw || static_cast<uint16_t>(propSeg + ps1) < ps2)
        return false;

    result = chosen;
    return true;
}
