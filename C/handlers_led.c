#include "H/handlers_led.h"

void handle_led_action(const char *request) {
    LedAction action = LED_OFF;

    if (strstr(request, "GET /led/off")) {
        action = LED_OFF;
    } else if (strstr(request, "GET /led/red")) {
        action = LED_RED;
    } else if (strstr(request, "GET /led/green")) {
        action = LED_GREEN;
    } else if (strstr(request, "GET /led/blue")) {
        action = LED_BLUE;
    } else if (strstr(request, "GET /led/yellow")) {
        action = LED_YELLOW;
    } else if (strstr(request, "GET /led/ciano")) {
        action = LED_CIANO;
    } else if (strstr(request, "GET /led/purple")) {
        action = LED_PURPLE;
    } else if (strstr(request, "GET /led/branco")) {
        action = LED_BRANCO;
    } else if (strstr(request, "GET /voltar")) {
        handle_main_menu(request);
        return;
    }

    switch (action) {
        case LED_OFF:
            state(0, 0, 0);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Leds desligados", 5, 10, cor);
            break;
        case LED_RED:
            state(1, 0, 0);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Led vermelho", 5, 10, cor);
            break;
        case LED_GREEN:
            state(0, 1, 0);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Led verde", 5, 10, cor);
            break;
        case LED_BLUE:
            state(0, 0, 1);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Led azul", 5, 10, cor);
            break;
        case LED_YELLOW:
            state(1, 1, 0);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Led amarelo", 5, 10, cor);
            break;
        case LED_CIANO:
            state(0, 1, 1);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Led ciano", 5, 10, cor);
            break;
        case LED_PURPLE:
            state(1, 0, 1);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Led roxo", 5, 10, cor);
            break;
        case LED_BRANCO:
            state(1, 1, 1);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Led branco", 5, 10, cor);
            break;
    }

    snprintf(http_response, sizeof(http_response),
             "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
             "<!DOCTYPE html><html lang='pt-BR'>"
             "<head>"
             "<meta charset='UTF-8'>"
             "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
             "<title>Controle dos LEDs RGB</title>"
             "<style>"
             "body { font-family: Arial, sans-serif; background-color:rgb(8, 8, 85); color: #333; margin: 0; padding: 0; }"
             "h1 { text-align: center; color:rgb(25, 150, 200); margin-top: 20px; }"
             ".container { max-width: 800px; margin: 0 auto; padding: 20px; }"
             ".grid { display: grid; grid-template-columns: repeat(4, 1fr); gap: 10px; margin-top: 30px; }"
             ".grid a { text-decoration: none; background-color:rgb(25, 150, 200); color: white; padding: 15px; border-radius: 5px; text-align: center; font-size: 18px; transition: background-color 0.3s; }"
             ".grid a:hover { background-color:rgb(25, 150, 200); }"
             ".footer { text-align: center; margin-top: 50px; font-size: 14px; color: #777; }"
             "</style>"
             "</head>"
             "<body>"
             "<div class='container'>"
             "<h1>Controle dos LEDs RGB</h1>"
             "<div class='grid'>"
             "<a href='/led/red'>Vermelho</a>"
             "<a href='/led/green'>Verde</a>"
             "<a href='/led/blue'>Azul</a>"
             "<a href='/led/yellow'>Amarelo</a>"
             "<a href='/led/ciano'>Ciano</a>"
             "<a href='/led/purple'>Roxo</a>"
             "<a href='/led/branco'>Branco</a>"
             "<a href='/led/off'>Desligar</a>"
             "<a href='/voltar'>Voltar</a>"
             "</div>"
             "<div class='footer'>APLICAÇÃO IoT - Controle de LEDs</div>"
             "<div class='footer'>Desenvolvido por ateniltonjr - 77999432631</div>"
             "</div>"
             "</body></html>\r\n");
}