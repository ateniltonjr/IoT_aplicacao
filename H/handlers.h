#ifndef HANDLERS_H
#define HANDLERS_H

#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>
#include "H/rgb.h"
#include "H/matrixws.h"
#include "hardware/i2c.h"
#include "H/ssd1306.h"
#include "H/font.h"
#include "H/notas.h"
#include "H/handlers_matriz.h"
#include "H/handlers_cores.h"
#include "H/handlers_led.h"
#include "H/handlers_notas.h"
#include "H/matriz_numbers.h"
#include "H/pinos_externos.h"
#include "H/handlers_gpios.h"

// Definições dos pinos para comunicação I2C
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define ENDERECO 0x3C

#define BUZZER_PIN 21

extern char http_response[2048];
extern ssd1306_t ssd;
extern bool cor;

// Inicialização e configuração do I2C e do display OLED SSD1306
void display();

// Função para exibir uma mensagem em uma linha do display OLED
void escrever(ssd1306_t *display, const char *texto, uint8_t x, uint8_t y, bool cor);

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