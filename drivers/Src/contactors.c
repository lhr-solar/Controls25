#include "contactors.h"
#include "stm32xx_hal.h"
#include "CAN.h"

#define CAN_PCHG_CONTACTOR_SET_ID 0x1A5
#define CAN_PCHG_CONTACTOR_GET_ID 0x1A6

#define GPIO_MOTOR_CONTACTOR_PORT GPIOA
#define GPIO_MOTOR_CONTACTOR_PIN GPIO_PIN_9
#define GPIO_MOTOR_CONTACTOR_SENSE_PIN GPIO_PIN_10

inline static bool contactors_set_gpio(GPIO_TypeDef *port, uint16_t pin, uint16_t sense_pin, bool state) {
    GPIO_PinState pin_state = (state)?GPIO_PIN_SET:GPIO_PIN_RESET;
    HAL_GPIO_WritePin(port, pin, pin_state);
    HAL_Delay(10); // 10ms
    
    // return success based on sense pin
    return (HAL_GPIO_ReadPin(port, sense_pin) == pin_state);
}

inline static bool contactors_get_gpio(GPIO_TypeDef *port, uint16_t sense_pin) {
    return (HAL_GPIO_ReadPin(port, sense_pin) == GPIO_PIN_SET);
}

static uint8_t pchg_contactors = 0b00;
inline static bool contactor_set_can(contactor_t contactor, bool state) {
    CAN_TxHeaderTypeDef tx_header = {
        .StdId = CAN_PCHG_CONTACTOR_SET_ID,
        .ExtId = 0,
        .IDE = CAN_ID_STD,
        .RTR = CAN_RTR_DATA,
        .DLC = 8
    };

    uint8_t data[8] = {pchg_contactors, 0, 0, 0, 0, 0, 0, 0};
    if (state) {
        data[0] |= (1 << contactor);
    } else {
        data[0] &= ~(1 << contactor);
    }
    
    // nonblocking send to update contactor values
    can_send(hcan1, &tx_header, data, false);

    // wait for response
    CAN_RxHeaderTypeDef rx_header;
    can_recv(hcan1, CAN_PCHG_CONTACTOR_GET_ID, &rx_header, data, true);
    pchg_contactors = data[0];

    return (pchg_contactors & (1 << contactor));
}

void contactors_init(){
    __HAL_RCC_GPIOA_CLK_ENABLE();

    HAL_GPIO_Init(GPIO_MOTOR_CONTACTOR_PORT, &(GPIO_InitTypeDef){
        .Pin = GPIO_MOTOR_CONTACTOR_PIN,
        .Mode = GPIO_MODE_OUTPUT_PP,
        .Pull = GPIO_NOPULL,
        .Speed = GPIO_SPEED_FREQ_LOW
    });

    HAL_GPIO_Init(GPIO_MOTOR_CONTACTOR_PORT, &(GPIO_InitTypeDef){
        .Pin = GPIO_MOTOR_CONTACTOR_SENSE_PIN,
        .Mode = GPIO_MODE_INPUT,
        .Pull = GPIO_NOPULL,
        .Speed = GPIO_SPEED_FREQ_LOW
    });
}

bool contactors_set(contactor_t contactor, bool state) {
    switch (contactor) {
        case CONTACTOR_MOTOR:
            return contactors_set_gpio(
                GPIO_MOTOR_CONTACTOR_PORT, 
                GPIO_MOTOR_CONTACTOR_PIN,
                GPIO_MOTOR_CONTACTOR_SENSE_PIN,
                state
            );
        case CONTACTOR_PCHG_MOTOR:
            return contactor_set_can(CONTACTOR_PCHG_MOTOR, state);
        case CONTACTOR_PCHG_ARRAY:
            return contactor_set_can(CONTACTOR_PCHG_ARRAY, state);
        default:
            return false;
    }
}

bool contactors_get(contactor_t contactor){
    switch(contactor) {
        case CONTACTOR_MOTOR: 
            return contactors_get_gpio(
                GPIO_MOTOR_CONTACTOR_PORT, 
                GPIO_MOTOR_CONTACTOR_SENSE_PIN
            ); 
        case CONTACTOR_PCHG_MOTOR:
        case CONTACTOR_PCHG_ARRAY:
            return (pchg_contactors & (1 << contactor));
        default:
            return false;
    }
}
