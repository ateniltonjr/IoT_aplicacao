#ifndef HANDLERS_H
#define HANDLERS_H

#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>
#include "H/matrixws.h"
#include "hardware/i2c.h"
#include "H/ssd1306.h"
#include "H/font.h"
#include "H/handlers_matriz.h"
#include "H/handlers_cores.h"
#include "H/handlers_led.h"
#include "H/handlers_notas.h"
#include "H/matriz_numbers.h"
#include "H/pinos_externos.h"
#include "H/handlers_gpios.h"

extern char http_response[2048];

// Funções de manipulação de requisições
void handle_main_menu(const char *request);
void handle_matriz_action(const char *request);
void handle_cores_action(const char *request);
void handle_led_action(const char *request);
void handle_nota_action(const char *request);
void handle_gpios_action(const char *request);

// Função para tocar uma nota musical
void tocar_nota(int frequencia, int duracao);

// Função de callback para processar requisições HTTP
err_t http_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);

// Callback de conexão: associa o http_callback à conexão
err_t connection_callback(void *arg, struct tcp_pcb *newpcb, err_t err);

// Função de setup do servidor TCP
void start_http_server();

#endif 