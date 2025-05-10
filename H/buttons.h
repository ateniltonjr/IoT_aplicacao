#ifndef BUTTONS_H
#define BUTTONS_H

// Trecho para o modo bootsel
#include "pico/bootrom.h"
#define botaoB 6
#define debounce_delay 300
volatile uint tempo_interrupcao = 0;

void iniciar_botoes()
{
    gpio_init(botaoB);
    gpio_set_dir(botaoB, GPIO_IN);
    gpio_pull_up(botaoB);
}

void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint tempo_atual = to_ms_since_boot(get_absolute_time());

    if(tempo_atual - tempo_interrupcao > debounce_delay)
    {
        if(gpio == botaoB)
        {
            reset_usb_boot(0, 0);
        }
    }
    tempo_atual = tempo_interrupcao;

}

#endif