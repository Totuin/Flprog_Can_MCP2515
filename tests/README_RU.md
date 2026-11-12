# Автономные тесты C++11

Тесты используют Arduino-заглушки и реальные заголовки `Flprog_Can 1.0.1`. Они **не заменяют** испытания на MCP2515.

Для запуска положите каталоги `Flprog_Can_MCP2515` и `Flprog_Can` рядом, затем в корне `Flprog_Can_MCP2515` выполните:

```bash
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror \
  -I tests/stubs -I src -I ../Flprog_Can/src \
  src/flprog_Can_MCP2515.cpp tests/mcp2515_timing_test.cpp \
  -o /tmp/mcp2515_timing_test
/tmp/mcp2515_timing_test

g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror \
  -I tests/stubs -I src -I ../Flprog_Can/src \
  src/flprog_Can_MCP2515.cpp ../Flprog_Can/src/base/flprog_Can_Base.cpp \
  tests/mcp2515_base_link_test.cpp -o /tmp/mcp2515_base_link_test
/tmp/mcp2515_base_link_test
```

Проверяются допустимые таблицы, битовые скорости, отсутствие повреждения output при ошибке и линковка с базовым CAN API. Для дополнительной проверки можно использовать `-fsanitize=address,undefined -fno-omit-frame-pointer`.
