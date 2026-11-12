#pragma once
#include <Arduino.h>
namespace flprog {
  bool isTimer(uint32_t startTime, uint32_t period);
  uint32_t timeBack(uint32_t value);
}
