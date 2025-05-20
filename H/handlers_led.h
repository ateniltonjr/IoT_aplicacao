#ifndef HANDLERS_LED_H
#define HANDLERS_LED_H

#include "H/handlers.h"

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

//#include <stdbool.h>
//#include "pico/stdlib.h"  // Biblioteca necessária para GPIO no Raspberry Pi Pico

// Definições dos pinos do LED RGB
#define blue 12
#define green 11
#define red 13

// Inicializa os pinos do LED RGB
static inline void iniciar_rgb(void) {
    gpio_init(red);
    gpio_init(green);
    gpio_init(blue);

    gpio_set_dir(red, GPIO_OUT);
    gpio_set_dir(green, GPIO_OUT);
    gpio_set_dir(blue, GPIO_OUT);
}

// Define o estado dos LEDs RGB
static inline void state(bool rr, bool gg, bool bb) {
    iniciar_rgb();
    gpio_put(red, rr);
    gpio_put(green, gg);
    gpio_put(blue, bb);
}

#endif // HANDLERS_LED_H