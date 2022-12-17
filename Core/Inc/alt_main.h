//
// Created by khadiev on 11/16/22.
//

#ifndef ALT_MAIN_H
#define ALT_MAIN_H

#include "main.h"

void init_GPIO();
void init_TIM2();

#ifdef __cplusplus
extern "C"
{
#endif

int alt_main();

#ifdef __cplusplus
}
#endif

#endif
