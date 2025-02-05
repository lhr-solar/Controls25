#ifndef CONTACTORS_H
#define CONTACTORS_H

#include <stdbool.h>

typedef enum {
    CONTACTOR_PCHG_MOTOR,
    CONTACTOR_PCHG_ARRAY,
    CONTACTOR_MOTOR,
    NUM_CONTACTORS
} contactor_t;

bool contactors_set(contactor_t contactor, bool state);
bool contactors_get(contactor_t contactor);

#endif