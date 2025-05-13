#ifndef PINOS_EXTERNOS_H
#define PINOS_EXTERNOS_H

#include "pico/stdlib.h"
#include <stdbool.h>

#define gpio4 4
#define gpio8 8
#define gpio9 9
#define gpio16 16
#define gpio17 17
#define gpio18 18
#define gpio19 19
#define gpio20 20
#define gpio28 28

static inline void iniciar_gpios_externos()
{
    gpio_init(gpio4);
    gpio_init(gpio8);
    gpio_init(gpio9);
    gpio_init(gpio16);
    gpio_init(gpio17);
    gpio_init(gpio18);
    gpio_init(gpio19);
    gpio_init(gpio20);
    gpio_init(gpio28);

    gpio_set_dir(gpio4, GPIO_OUT);
    gpio_set_dir(gpio8, GPIO_OUT);
    gpio_set_dir(gpio9, GPIO_OUT);
    gpio_set_dir(gpio16, GPIO_OUT);
    gpio_set_dir(gpio17, GPIO_OUT);
    gpio_set_dir(gpio18, GPIO_OUT);
    gpio_set_dir(gpio19, GPIO_OUT);
    gpio_set_dir(gpio20, GPIO_OUT);
    gpio_set_dir(gpio28, GPIO_OUT);
}

static inline void gpio_state(
                bool g4, bool g8, 
                bool g9, bool g16,
                bool g17,bool g18, 
                bool g19,bool g20,
                bool g28          )
{
    gpio_put(gpio4, g4);
    gpio_put(gpio8, g8);
    gpio_put(gpio9, g9);
    gpio_put(gpio16, g16);
    gpio_put(gpio17, g17);
    gpio_put(gpio18, g18);
    gpio_put(gpio19, g19);
    gpio_put(gpio20, g20);
    gpio_put(gpio28, g28);
}

#endif