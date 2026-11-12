#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprog_Can.h"

/**
 * @file flprog_Can_MCP2515.h
 * @brief Заготовка аппаратного транспорта CAN на контроллере MCP2515.
 *
 * ВАЖНО: SPI-драйвер в этой версии ещё не реализован. Класс
 * FLProgMCP2515CanBus содержит только объявления констант.
 * Таблицы CNF1/CNF2/CNF3 предназначены для будущего драйвера;
 * их наличие не означает поддержку передачи и приёма кадров.
 *
 * Таблица битовых времён MCP2515, кварц 8 МГц.
 * CNF1: SJW и делитель BRP; CNF2: PropSeg/PS1/режим выборки;
 * CNF3: PS2. Скорость зависит от физического кварца модуля.
 * Для 8 МГц / 1000 кбит/с исходная тройка недопустима (PS2 = 1 TQ):
 * flprogMcp2515GetBitTiming() отклоняет это сочетание.
 */
#define FLPROG_MCP_8MHz_1000kBPS_CFG1 (0x00)
#define FLPROG_MCP_8MHz_1000kBPS_CFG2 (0x80)
#define FLPROG_MCP_8MHz_1000kBPS_CFG3 (0x80)

#define FLPROG_MCP_8MHz_500kBPS_CFG1 (0x00)
#define FLPROG_MCP_8MHz_500kBPS_CFG2 (0x90)
#define FLPROG_MCP_8MHz_500kBPS_CFG3 (0x82)

#define FLPROG_MCP_8MHz_250kBPS_CFG1 (0x00)
#define FLPROG_MCP_8MHz_250kBPS_CFG2 (0xB1)
#define FLPROG_MCP_8MHz_250kBPS_CFG3 (0x85)

#define FLPROG_MCP_8MHz_200kBPS_CFG1 (0x00)
#define FLPROG_MCP_8MHz_200kBPS_CFG2 (0xB4)
#define FLPROG_MCP_8MHz_200kBPS_CFG3 (0x86)

#define FLPROG_MCP_8MHz_125kBPS_CFG1 (0x01)
#define FLPROG_MCP_8MHz_125kBPS_CFG2 (0xB1)
#define FLPROG_MCP_8MHz_125kBPS_CFG3 (0x85)

#define FLPROG_MCP_8MHz_100kBPS_CFG1 (0x01)
#define FLPROG_MCP_8MHz_100kBPS_CFG2 (0xB4)
#define FLPROG_MCP_8MHz_100kBPS_CFG3 (0x86)

#define FLPROG_MCP_8MHz_80kBPS_CFG1 (0x01)
#define FLPROG_MCP_8MHz_80kBPS_CFG2 (0xBF)
#define FLPROG_MCP_8MHz_80kBPS_CFG3 (0x87)

#define FLPROG_MCP_8MHz_50kBPS_CFG1 (0x03)
#define FLPROG_MCP_8MHz_50kBPS_CFG2 (0xB4)
#define FLPROG_MCP_8MHz_50kBPS_CFG3 (0x86)

#define FLPROG_MCP_8MHz_40kBPS_CFG1 (0x03)
#define FLPROG_MCP_8MHz_40kBPS_CFG2 (0xBF)
#define FLPROG_MCP_8MHz_40kBPS_CFG3 (0x87)

#define FLPROG_MCP_8MHz_33k3BPS_CFG1 (0x47)
#define FLPROG_MCP_8MHz_33k3BPS_CFG2 (0xE2)
#define FLPROG_MCP_8MHz_33k3BPS_CFG3 (0x85)

#define FLPROG_MCP_8MHz_31k25BPS_CFG1 (0x07)
#define FLPROG_MCP_8MHz_31k25BPS_CFG2 (0xA4)
#define FLPROG_MCP_8MHz_31k25BPS_CFG3 (0x84)

#define FLPROG_MCP_8MHz_20kBPS_CFG1 (0x07)
#define FLPROG_MCP_8MHz_20kBPS_CFG2 (0xBF)
#define FLPROG_MCP_8MHz_20kBPS_CFG3 (0x87)

#define FLPROG_MCP_8MHz_10kBPS_CFG1 (0x0F)
#define FLPROG_MCP_8MHz_10kBPS_CFG2 (0xBF)
#define FLPROG_MCP_8MHz_10kBPS_CFG3 (0x87)

#define FLPROG_MCP_8MHz_5kBPS_CFG1 (0x1F)
#define FLPROG_MCP_8MHz_5kBPS_CFG2 (0xBF)
#define FLPROG_MCP_8MHz_5kBPS_CFG3 (0x87)

/** @brief Предварительные настройки CAN для кварца 16 МГц. */
#define FLPROG_MCP_16MHz_1000kBPS_CFG1 (0x00)
#define FLPROG_MCP_16MHz_1000kBPS_CFG2 (0xD0)
#define FLPROG_MCP_16MHz_1000kBPS_CFG3 (0x82)

#define FLPROG_MCP_16MHz_500kBPS_CFG1 (0x00)
#define FLPROG_MCP_16MHz_500kBPS_CFG2 (0xF0)
#define FLPROG_MCP_16MHz_500kBPS_CFG3 (0x86)

#define FLPROG_MCP_16MHz_250kBPS_CFG1 (0x41)
#define FLPROG_MCP_16MHz_250kBPS_CFG2 (0xF1)
#define FLPROG_MCP_16MHz_250kBPS_CFG3 (0x85)

#define FLPROG_MCP_16MHz_200kBPS_CFG1 (0x01)
#define FLPROG_MCP_16MHz_200kBPS_CFG2 (0xFA)
#define FLPROG_MCP_16MHz_200kBPS_CFG3 (0x87)

#define FLPROG_MCP_16MHz_125kBPS_CFG1 (0x03)
#define FLPROG_MCP_16MHz_125kBPS_CFG2 (0xF0)
#define FLPROG_MCP_16MHz_125kBPS_CFG3 (0x86)

#define FLPROG_MCP_16MHz_100kBPS_CFG1 (0x03)
#define FLPROG_MCP_16MHz_100kBPS_CFG2 (0xFA)
#define FLPROG_MCP_16MHz_100kBPS_CFG3 (0x87)

#define FLPROG_MCP_16MHz_80kBPS_CFG1 (0x03)
#define FLPROG_MCP_16MHz_80kBPS_CFG2 (0xFF)
#define FLPROG_MCP_16MHz_80kBPS_CFG3 (0x87)

#define FLPROG_MCP_16MHz_83k3BPS_CFG1 (0x03)
#define FLPROG_MCP_16MHz_83k3BPS_CFG2 (0xBE)
#define FLPROG_MCP_16MHz_83k3BPS_CFG3 (0x07)

#define FLPROG_MCP_16MHz_50kBPS_CFG1 (0x07)
#define FLPROG_MCP_16MHz_50kBPS_CFG2 (0xFA)
#define FLPROG_MCP_16MHz_50kBPS_CFG3 (0x87)

#define FLPROG_MCP_16MHz_40kBPS_CFG1 (0x07)
#define FLPROG_MCP_16MHz_40kBPS_CFG2 (0xFF)
#define FLPROG_MCP_16MHz_40kBPS_CFG3 (0x87)

#define FLPROG_MCP_16MHz_33k3BPS_CFG1 (0x4E)
#define FLPROG_MCP_16MHz_33k3BPS_CFG2 (0xF1)
#define FLPROG_MCP_16MHz_33k3BPS_CFG3 (0x85)

#define FLPROG_MCP_16MHz_20kBPS_CFG1 (0x0F)
#define FLPROG_MCP_16MHz_20kBPS_CFG2 (0xFF)
#define FLPROG_MCP_16MHz_20kBPS_CFG3 (0x87)

#define FLPROG_MCP_16MHz_10kBPS_CFG1 (0x1F)
#define FLPROG_MCP_16MHz_10kBPS_CFG2 (0xFF)
#define FLPROG_MCP_16MHz_10kBPS_CFG3 (0x87)

#define FLPROG_MCP_16MHz_5kBPS_CFG1 (0x3F)
#define FLPROG_MCP_16MHz_5kBPS_CFG2 (0xFF)
#define FLPROG_MCP_16MHz_5kBPS_CFG3 (0x87)

/** @brief Предварительные настройки CAN для кварца 20 МГц. */
#define FLPROG_MCP_20MHz_1000kBPS_CFG1 (0x00)
#define FLPROG_MCP_20MHz_1000kBPS_CFG2 (0xD9)
#define FLPROG_MCP_20MHz_1000kBPS_CFG3 (0x82)

#define FLPROG_MCP_20MHz_500kBPS_CFG1 (0x00)
#define FLPROG_MCP_20MHz_500kBPS_CFG2 (0xFA)
#define FLPROG_MCP_20MHz_500kBPS_CFG3 (0x87)

#define FLPROG_MCP_20MHz_250kBPS_CFG1 (0x41)
#define FLPROG_MCP_20MHz_250kBPS_CFG2 (0xFB)
#define FLPROG_MCP_20MHz_250kBPS_CFG3 (0x86)

#define FLPROG_MCP_20MHz_200kBPS_CFG1 (0x01)
#define FLPROG_MCP_20MHz_200kBPS_CFG2 (0xFF)
#define FLPROG_MCP_20MHz_200kBPS_CFG3 (0x87)

#define FLPROG_MCP_20MHz_125kBPS_CFG1 (0x03)
#define FLPROG_MCP_20MHz_125kBPS_CFG2 (0xFA)
#define FLPROG_MCP_20MHz_125kBPS_CFG3 (0x87)

#define FLPROG_MCP_20MHz_100kBPS_CFG1 (0x04)
#define FLPROG_MCP_20MHz_100kBPS_CFG2 (0xFA)
#define FLPROG_MCP_20MHz_100kBPS_CFG3 (0x87)

#define FLPROG_MCP_20MHz_80kBPS_CFG1 (0x04)
#define FLPROG_MCP_20MHz_80kBPS_CFG2 (0xFF)
#define FLPROG_MCP_20MHz_80kBPS_CFG3 (0x87)

#define FLPROG_MCP_20MHz_50kBPS_CFG1 (0x09)
#define FLPROG_MCP_20MHz_50kBPS_CFG2 (0xFA)
#define FLPROG_MCP_20MHz_50kBPS_CFG3 (0x87)

#define FLPROG_MCP_20MHz_40kBPS_CFG1 (0x09)
#define FLPROG_MCP_20MHz_40kBPS_CFG2 (0xFF)
#define FLPROG_MCP_20MHz_40kBPS_CFG3 (0x87)

// Идентификаторы кварца (совпадают со значениями FLPROG_MCP_CAN_CLOCK).
// Раньше все три были равны 0, поэтому невозможно было различать частоты.
#define FLPROG_MCP_CAN_CLOCK_20MHZ 0
#define FLPROG_MCP_CAN_CLOCK_16MHZ 1
#define FLPROG_MCP_CAN_CLOCK_8MHZ 2

// Идентификаторы скоростей для выбора настроек, НЕ значения бит/сек.
// Не все сочетания частоты и скорости имеют готовые таблицы CNF.
#define FLPROG_MCP_CAN_SPEED_5KBPS 0
#define FLPROG_MCP_CAN_SPEED_10KBPS 1
#define FLPROG_MCP_CAN_SPEED_20KBPS 2
#define FLPROG_MCP_CAN_SPEED_31K25BPS 3
#define FLPROG_MCP_CAN_SPEED_33KBPS 4
#define FLPROG_MCP_CAN_SPEED_40KBPS 5
#define FLPROG_MCP_CAN_SPEED_50KBPS 6
#define FLPROG_MCP_CAN_SPEED_80KBPS 7
#define FLPROG_MCP_CAN_SPEED_83K3BPS 8
#define FLPROG_MCP_CAN_SPEED_95KBPS 9
#define FLPROG_MCP_CAN_SPEED_100KBPS 10
#define FLPROG_MCP_CAN_SPEED_125KBPS 11
#define FLPROG_MCP_CAN_SPEED_200KBPS 12
#define FLPROG_MCP_CAN_SPEED_250KBPS 13
#define FLPROG_MCP_CAN_SPEED_500KBPS 14
#define FLPROG_MCP_CAN_SPEED_1000KBPS 15

// Исторические коды ошибок будущей SPI-реализации (сейчас не используются).
#define FLPROG_MCP_CAN_ERROR_OK 0
#define FLPROG_MCP_CAN_ERROR_FAIL 1
#define FLPROG_MCP_CAN_ERROR_ALLTXBUSY 2
#define FLPROG_MCP_CAN_ERROR_FAILINIT 3
#define FLPROG_MCP_CAN_ERROR_FAILTX 4
#define FLPROG_MCP_CAN_ERROR_NOMSG 5

// Номера двух масок и шести аппаратных фильтров MCP2515.
#define FLPROG_MCP_CAN_MASK0 0
#define FLPROG_MCP_CAN_MASK1 1

#define FLPROG_MCP_CAN_RXF0 0
#define FLPROG_MCP_CAN_RXF1 1
#define FLPROG_MCP_CAN_RXF2 2
#define FLPROG_MCP_CAN_RXF3 3
#define FLPROG_MCP_CAN_RXF4 4
#define FLPROG_MCP_CAN_RXF5 5

// Индексы двух аппаратных приёмных буферов.
#define FLPROG_MCP_CAN_RXB0 0
#define FLPROG_MCP_CAN_RXB1 1

// Биты регистра CANINTF для проверки и сброса флагов прерываний.
#define FLPROG_MCP_CAN_CANINTF_RX0IF 0x01
#define FLPROG_MCP_CAN_CANINTF_RX1IF 0x02
#define FLPROG_MCP_CAN_CANINTF_TX0IF 0x04
#define FLPROG_MCP_CAN_CANINTF_TX1IF 0x08
#define FLPROG_MCP_CAN_CANINTF_TX2IF 0x10
#define FLPROG_MCP_CAN_CANINTF_ERRIF 0x20
#define FLPROG_MCP_CAN_CANINTF_WAKIF 0x40
#define FLPROG_MCP_CAN_CANINTF_MERRF 0x80

/** @brief Выбор частоты установленного на модуле кварцевого резонатора. */
enum FLPROG_MCP_CAN_CLOCK
{
    FLPROG_MCP_20MHZ,
    FLPROG_MCP_16MHZ,
    FLPROG_MCP_8MHZ
};

/** @brief Код желаемой скорости, а не значение в бодах. */
enum FLPROG_MCP_CAN_SPEED
{
    FLPROG_MCP_CAN_5KBPS,
    FLPROG_MCP_CAN_10KBPS,
    FLPROG_MCP_CAN_20KBPS,
    FLPROG_MCP_CAN_31K25BPS,
    FLPROG_MCP_CAN_33KBPS,
    FLPROG_MCP_CAN_40KBPS,
    FLPROG_MCP_CAN_50KBPS,
    FLPROG_MCP_CAN_80KBPS,
    FLPROG_MCP_CAN_83K3BPS,
    FLPROG_MCP_CAN_95KBPS,
    FLPROG_MCP_CAN_100KBPS,
    FLPROG_MCP_CAN_125KBPS,
    FLPROG_MCP_CAN_200KBPS,
    FLPROG_MCP_CAN_250KBPS,
    FLPROG_MCP_CAN_500KBPS,
    FLPROG_MCP_CAN_1000KBPS
};

/**
 * @brief Будущий аппаратный CAN-транспорт для MCP2515.
 * @warning Здесь НЕТ методов SPI-инициализации, передачи, приёма и фильтров.
 *          Наследуемая заглушка FLProgAbstractCanBus::write() возвращает false.
 *          Не используйте этот тип как рабочий CAN-драйвер.
 */
class FLProgMCP2515CanBus : public FLProgAbstractCanBus
{
public:
protected:
    // Биты управляющего регистра CANCTRL MCP2515. Сохранены для будущего драйвера.
    static const uint8_t CANCTRL_REQOP = 0xE0;
    static const uint8_t CANCTRL_ABAT = 0x10;
    static const uint8_t CANCTRL_OSM = 0x08;
    static const uint8_t CANCTRL_CLKEN = 0x04;
    static const uint8_t CANCTRL_CLKPRE = 0x03;
};

/**
 * @brief Три аппаратных регистра, определяющие битовую синхронизацию MCP2515.
 *
 * Передавать регистры в микросхему можно только в режиме Configuration.
 * Этот тип не взаимодействует со SPI и не изменяет состояние устройства.
 */
struct FLProgMCP2515BitTiming
{
    uint8_t cnf1;
    uint8_t cnf2;
    uint8_t cnf3;
};

/**
 * @brief Выбрать проверенную комбинацию CNF1, CNF2, CNF3.
 * @param clock Одна из FLPROG_MCP_CAN_CLOCK_* или FLPROG_MCP_*MHZ.
 * @param speed Одна из FLPROG_MCP_CAN_SPEED_* или FLPROG_MCP_CAN_*KBPS.
 * @param result Структура, заполняемая ТОЛЬКО при успешном выборе.
 * @return true для существующей и допустимой комбинации, иначе false.
 *
 * Отсутствующие таблицы (например, 95 кбит/с) и неприемлемое
 * сочетание 8 МГц / 1000 кбит/с не подменяются приближёнными значениями.
 * Данные не отправляются в MCP2515: здесь нет SPI-подключения.
 */
bool flprogMcp2515GetBitTiming(uint8_t clock, uint8_t speed,
                               FLProgMCP2515BitTiming &result);
