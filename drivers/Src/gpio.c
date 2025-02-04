#include "stm32xx_hal.h"

HAL_StatusTypeDef gpio_init(void) {
  HAL_StatusTypeDef status = HAL_OK;

  // enable clocks
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  // init gpio
  GPIO_InitTypeDef init = {0};

  init.Pin = PIN_CRUISE_SET;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  if (status = HAL_GPIO_Init(PORT_CRUISE_SET, &init) != HAL_OK) return status;

  init.Pin = PIN_CRUISE_EN;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  if (HAL_GPIO_Init(PORT_CRUISE_EN, &init) != HAL_OK) return HAL_ERR;
  
  init.Pin = PIN_IG1;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  if (HAL_GPIO_Init(PORT_IG1, &init) != HAL_OK) return HAL_ERR;

  init.Pin = PIN_IG2;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  if (HAL_GPIO_Init(PORT_IG2, &init) != HAL_OK) return HAL_ERR;

  init.Pin = PIN_HEARTBEAT;
  init.Mode = GPIO_MODE_OUTPUT_PP;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  if (HAL_GPIO_Init(PORT_HEARBEAT, &init) != HAL_OK) return HAL_ERR;

  init.Pin = PIN_BPS_HAZARD;
  init.Mode = GPIO_MODE_OUTPUT_PP;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  if (HAL_GPIO_Init(PORT_BPS_HAZARD, &init) != HAL_OK) return HAL_ERR;

  init.Pin = PIN_REVERSE;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  if (HAL_GPIO_Init(PORT_REVERSE, &init) != HAL_OK) return HAL_ERR;

  init.Pin = PIN_FORWARD;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  if (HAL_GPIO_Init(PORT_FORWARD, &init) != HAL_OK) return HAL_ERR;
}
