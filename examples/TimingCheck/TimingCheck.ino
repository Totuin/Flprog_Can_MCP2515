// Пример для проверки компиляции и выбора таблицы битовых времён MCP2515.
// НЕ управляет SPI и НЕ отправляет CAN-кадры: драйвер пока не реализован.
#include <flprog_Can_MCP2515.h>

FLProgMCP2515BitTiming mcp2515Timing = {0, 0, 0};
bool mcp2515TimingReady = false;

void setup()
{
    // Пример для модуля с кварцем 16 МГц и CAN 500 кбит/с.
    mcp2515TimingReady = flprogMcp2515GetBitTiming(
        FLPROG_MCP_CAN_CLOCK_16MHZ,
        FLPROG_MCP_CAN_SPEED_500KBPS,
        mcp2515Timing);
}

void loop()
{
    // Данные CNF1/CNF2/CNF3 рассчитаны, но не записываются в микросхему.
}
