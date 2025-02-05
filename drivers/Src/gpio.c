#include "gpio.h"
#include "stm32xx_hal.h"

void gpio_init(void) {
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

  HAL_GPIO_Init(PORT_CRUISE_SET, &init);

  init.Pin = PIN_CRUISE_EN;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(PORT_CRUISE_EN, &init);
  
  init.Pin = PIN_IG1;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(PORT_IG1, &init);

  init.Pin = PIN_IG2;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(PORT_IG2, &init);

  init.Pin = PIN_HEARTBEAT;
  init.Mode = GPIO_MODE_OUTPUT_PP;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(PORT_HEARTBEAT, &init);

  init.Pin = PIN_BPS_HAZARD;
  init.Mode = GPIO_MODE_OUTPUT_PP;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(PORT_BPS_HAZARD, &init);

  init.Pin = PIN_REVERSE;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(PORT_REVERSE, &init);

  init.Pin = PIN_FORWARD;
  init.Mode = GPIO_MODE_INPUT;
  init.Pull = GPIO_NOPULL;
  init.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(PORT_FORWARD, &init);
}
