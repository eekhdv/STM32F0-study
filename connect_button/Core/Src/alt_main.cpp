//
// Created by khadiev on 11/16/22.
//
#include "alt_main.h"
#include "gpio.h"

int alt_main() {
    /* Initialization */
    while (1) {
        if (HAL_GPIO_ReadPin(IButton_GPIO_Port, IButton_Pin) == 0) {
            HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
            HAL_Delay(500);
            HAL_GPIO_TogglePin(LED2_GPIO_Port, LED3_Pin);
            HAL_Delay(300);
            HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
            HAL_Delay(100);
        }
        /* Super loop */
    }
}
