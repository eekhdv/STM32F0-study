//
// Created by khadiev on 17-12-2022
//
#include "alt_main.h"
#include "stm32f0xx_hal_conf.h"

int alt_main() {
    /* Initialization */
    init_GPIO();

    while (true) {
        /* Super loop */
    }
}

void init_GPIO() {
    GPIO_InitTypeDef GPIO_init_LED;

    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_init_LED.Pin       = GPIO_PIN_9 | GPIO_PIN_8| GPIO_PIN_7;
    GPIO_init_LED.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_init_LED.Pull      = GPIO_NOPULL;
    GPIO_init_LED.Speed     = GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(GPIOB, &GPIO_init_LED);
}

