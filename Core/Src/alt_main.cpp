//
// Created by khadiev on 17-12-2022
//
#include "alt_main.h"

int alt_main() {
    /* Initialization */
    init_GPIO();
    init_TIM2();

    while (true) {
        /* Super loop */
    }
}

void init_GPIO() {
    GPIO_InitTypeDef GPIO_init_LED = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7, GPIO_PIN_SET);

    GPIO_init_LED.Pin       = GPIO_PIN_9 | GPIO_PIN_8| GPIO_PIN_7;
    GPIO_init_LED.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_init_LED.Pull      = GPIO_NOPULL;
    GPIO_init_LED.Speed     = GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(GPIOB, &GPIO_init_LED);
}

void init_TIM2() {
    TIM_HandleTypeDef TIM_init_button;
    TIM_IC_InitTypeDef TIM_IC_user_init;
    TIM_ClockConfigTypeDef TIM_clock_source_cfg;

    TIM_init_button.Instance = TIM2;
    TIM_init_button.Init.Prescaler = 0;
    TIM_init_button.Init.CounterMode = TIM_COUNTERMODE_UP;
    TIM_init_button.Init.Period = 0xffff;
    TIM_init_button.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    TIM_init_button.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    HAL_TIM_Base_Init(&TIM_init_button);

    TIM_clock_source_cfg.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    HAL_TIM_ConfigClockSource(&TIM_init_button, &TIM_clock_source_cfg);

    HAL_TIM_IC_Init(&TIM_init_button);

    TIM_IC_user_init.ICFilter = 0;
    TIM_IC_user_init.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
    TIM_IC_user_init.ICSelection = TIM_ICSELECTION_DIRECTTI;
    TIM_IC_user_init.ICPrescaler = TIM_ICPSC_DIV1;
    HAL_TIM_IC_ConfigChannel(&TIM_init_button, &TIM_IC_user_init, TIM_CHANNEL_3);

    HAL_TIM_IC_Start_IT(&TIM_init_button, TIM_CHANNEL_3);

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if(tim_baseHandle->Instance==TIM2)
    {
        /* TIM2 clock enable */
        __HAL_RCC_TIM2_CLK_ENABLE();

        __HAL_RCC_GPIOA_CLK_ENABLE();

        GPIO_InitStruct.Pin = GPIO_PIN_2;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.Alternate = GPIO_AF2_TIM2;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /* TIM2 interrupt Init */
        HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(TIM2_IRQn);
    }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

    if(tim_baseHandle->Instance==TIM2)
    {
        /* Peripheral clock disable */
        __HAL_RCC_TIM2_CLK_DISABLE();

        /**TIM2 GPIO Configuration
        PA2     ------> TIM2_CH3
        */
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2);

        /* TIM2 interrupt Deinit */
        HAL_NVIC_DisableIRQ(TIM2_IRQn);
    }
}


