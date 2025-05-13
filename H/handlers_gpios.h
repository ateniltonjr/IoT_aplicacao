#ifndef HANDLERS_LED_H
#define HANDLERS_LED_H

#include "H/handlers.h"

// Enumeração para as ações dos LEDs
typedef enum {
    GPIO_OFF = 0,
    GPIO4,
    GPIO8,
    GPIO9,
    GPIO16,
    GPIO17,
    GPIO18,
    GPIO19,
    GPIO20,
    GPIO28
} GpioAction;

// Função para manipular ações dos LEDs
void handle_gpios_action(const char *request);

#endif