#ifndef TCHAT_COMMON_HPP
#define TCHAT_COMMON_HPP

#include <stdint.h>
#include <stddef.h>

// size
const uint32_t TCHAT_MSG_SIZE = 16;

// position
const size_t TCHAT_HEADER_POSITION = 0;
const size_t TCHAT_TYPE_POSITION = TCHAT_HEADER_POSITION + 1;
const size_t TCHAT_TARGET_POSITION = TCHAT_HEADER_POSITION + 1;
const size_t TCHAT_FOOTER_POSITION = 15;

const size_t TCHAT_POSITION_LED_PIN = TCHAT_TYPE_POSITION + 1;
const size_t TCHAT_POSITION_LED_STATUS = TCHAT_POSITION_LED_PIN + 1;

// values
const uint8_t TCHAT_HEADER = 0x55;
const uint8_t TCHAT_FOOTER = 0x66;

// mask
const uint8_t TCHAT_HEADER_MASK_TYPE = 0xF0;
const uint8_t TCHAT_HEADER_MASK_TARGET = 0x0F;

// enum
enum TCHAT_TYPE
{
    TCHAT_TYPE_CMD = 0x00,
    TCHAT_TYPE_ACK = 0x10
};

enum TCHAT_TARGET
{
    TCHAT_TARGET_NONE = 0x00,
    TCHAT_TARGET_LED = 0x01,
    TCHAT_TARGET_SERVO = 0x02
};

enum TCHAT_LED_STATUS
{
    TCHAT_LED_STATUS_OFF = 0x00,
    TCHAT_LED_STATUS_ON = 0x01
};

#endif
