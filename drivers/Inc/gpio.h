#ifdef GPIO_H
#define GPIO_H

// pin definitions
#define PORT_CRUISE_SET (GPIOA)
#define PIN_CRUISE_SET (GPIO_PIN_7)

#define PORT_CRUISE_EN (GPIOC)
#define PIN_CRUISE_EN (GPIO_PIN_5)

#define PORT_IG1 (GPIOB)
#define PIN_IG1 (GPIO_PIN_1)

#define PORT_IG2 (GPIOB)
#define PIN_IG2 (GPIO_PIN_10)

#define PORT_HEARTBEAT (GPIOC)
#define PIN_HEARTBEAT (GPIO_PIN_10)

#define PORT_BPS_HAZARD (GPIOA)
#define PIN_BPS_HAZARD (GPIO_PIN_6)

#define PORT_REVERSE (GPIOB)
#define PIN_REVERSE (GPIO_PIN_15)

#define PORT_FORWARD (GPIOB)
#define PIN_FORWARD (GPIO_PIN_2)

typedef enum {
  GPIO_ERR,
  GPIO_OK = 0
} 

HAL_StatusTypeDef gpio_init(void);

#endif /* GPIO_H */

