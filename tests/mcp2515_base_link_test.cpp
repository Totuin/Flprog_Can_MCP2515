// Проверка линковки с реальной базовой библиотекой Flprog_Can 1.0.1.
#include "flprog_Can_MCP2515.h"
#include <assert.h>

uint32_t millis() { return 1234; }
namespace flprog {
uint32_t timeBack(uint32_t value) { return 0U - value; }
bool isTimer(uint32_t startTime, uint32_t period) {
    return static_cast<uint32_t>(millis() - startTime) >= period;
}
}

int main() {
    FLProgMCP2515CanBus unfinished;
    CAN_message_t message;
    message.id = 0x7FF;
    // Важно не принимать компилируемую заготовку за работающий драйвер.
    assert(!unfinished.write(message));
    assert(!unfinished.hasNewReadMessage());
    assert(unfinished.getReadMessage() == nullptr);

    // С базовым CAN API тип совместим, но пока не отправляет кадры.
    FLProgCanBusMessage wrapper(&unfinished, 0x100, false, 8);
    wrapper.setMode(FLPROG_CAN_BUS_MESSAGE_CHANGE_MODE);
    wrapper.pool();
    assert(!wrapper.hasNewData());
}
