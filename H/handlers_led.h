#ifndef HANDLERS_LED_H
#define HANDLERS_LED_H

#include "handlers.h"

// Enumeração para as ações dos LEDs
typedef enum {
    LED_OFF = 0,
    LED_RED,
    LED_GREEN,
    LED_BLUE,
    LED_YELLOW,
    LED_CIANO,
    LED_PURPLE,
    LED_BRANCO
} LedAction;

// Função para manipular ações dos LEDs
void handle_led_action(const char *request);

#endif // HANDLERS_LED_H