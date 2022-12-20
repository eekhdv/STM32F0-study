//
// Created by khadiev on 11/16/22.
//

#ifndef ALT_MAIN_H
#define ALT_MAIN_H

#include "main.h"

void init_GPIO();
void init_TIM2();
uint8_t decode();
void IRsend_sendLG (const uint32_t data, unsigned int nbits);
void IRsend_mark (unsigned int time);
void IRsend_space (unsigned int time);
void init_IR_send(uint8_t khz);

#ifdef __cplusplus
extern "C"
{
#endif

int alt_main();

#ifdef __cplusplus
}
#endif

#endif
