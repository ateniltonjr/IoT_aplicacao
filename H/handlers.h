#ifndef HANDLERS_H
#define HANDLERS_H

#include "pico/cyw43_arch.h"        // Biblioteca para suporte ao chip Wi-Fi CYW43 no Raspberry Pi Pico
#include "pico/stdlib.h"            // Biblioteca padrão para funções básicas do Pico (GPIO, delays, etc)
#include "lwip/tcp.h"               // Biblioteca para manipulação de conexões TCP usando LWIP
#include <string.h>                 // Biblioteca padrão C para manipulação de strings
#include <stdio.h>                  // Biblioteca padrão C para entrada/saída (printf, sprintf, etc)
#include "H/matrixws.h"             // Header para funções relacionadas à matriz de LEDs (WebSocket)
#include "hardware/i2c.h"           // Biblioteca para comunicação I2C no Pico
#include "H/ssd1306.h"              // Header para controle do display OLED SSD1306
#include "H/font.h"                 // Header para fontes usadas no display
#include "H/handlers_matriz.h"      // Header para handlers específicos da matriz de LEDs
#include "H/handlers_cores.h"       // Header para handlers de manipulação de cores
#include "H/handlers_led.h"         // Header para handlers de controle de LEDs
#include "H/handlers_notas.h"       // Header para handlers de notas musicais
#include "H/matriz_numbers.h"       // Header para números exibidos na matriz de LEDs
#include "H/pinos_externos.h"       // Header para manipulação de pinos externos
#include "H/handlers_gpios.h"       // Header para handlers de controle de GPIOs

extern char http_response[2048]; // Buffer para armazenar a resposta HTTP

// Funções de manipulação de requisições
void handle_main_menu(const char *request);      // Manipula requisições para o menu principal
void handle_matriz_action(const char *request);  // Manipula ações relacionadas à matriz de LEDs
void handle_cores_action(const char *request);   // Manipula ações de alteração de cores
void handle_led_action(const char *request);     // Manipula ações de controle de LEDs
void handle_nota_action(const char *request);    // Manipula ações para tocar notas musicais
void handle_gpios_action(const char *request);   // Manipula ações de controle de GPIOs

// Função para tocar uma nota musical
void tocar_nota(int frequencia, int duracao); // Toca uma nota com a frequência e duração especificadas

// Função de callback para processar requisições HTTP
err_t http_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);// Processa requisições HTTP

// Callback de conexão: associa o http_callback à conexão
err_t connection_callback(void *arg, struct tcp_pcb *newpcb, err_t err); // Callback de conexão

// Função de setup do servidor TCP
void start_http_server(); // Inicia o servidor HTTP

#endif 