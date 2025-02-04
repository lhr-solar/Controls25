#ifndef CONTACTORS_H
#define CONTACTORS_H

#include <stdbool.h>

typedef enum {
    CONTACTOR_PCHG_MOTOR,
    CONTACTOR_PCHG_ARRAY,
    CONTACTOR_MOTOR,
    NUM_CONTACTORS
} contactor_t;

void contactors_init();
void contactors_set(contactor_t contactor, bool state);

#endif