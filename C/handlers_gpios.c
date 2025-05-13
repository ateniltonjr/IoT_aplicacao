#include "H/handlers_gpios.h"

// Variáveis globais para armazenar o estado de cada GPIO
static bool gpio_states[] = {
    false, // GPIO_OFF (não usado)
    false, // GPIO4
    false, // GPIO8
    false, // GPIO9
    false, // GPIO16
    false, // GPIO17
    false, // GPIO18
    false, // GPIO19
    false, // GPIO20
    false  // GPIO28
};

void handle_gpios_action(const char *request) {
    GpioAction action = GPIO_OFF;

    if (strstr(request, "GET /gpio/off")) {
        // Desliga todos os GPIOs
        for (int i = 1; i < sizeof(gpio_states)/sizeof(gpio_states[0]); i++) {
            gpio_states[i] = false;
        }
        action = GPIO_OFF;
    } else if (strstr(request, "GET /gpio/4")) {
        gpio_states[GPIO4] = !gpio_states[GPIO4]; // Alterna estado
        action = GPIO4;
    } else if (strstr(request, "GET /gpio/8")) {
        gpio_states[GPIO8] = !gpio_states[GPIO8];
        action = GPIO8;
    } else if (strstr(request, "GET /gpio/9")) {
        gpio_states[GPIO9] = !gpio_states[GPIO9];
        action = GPIO9;
    } else if (strstr(request, "GET /gpio/16")) {
        gpio_states[GPIO16] = !gpio_states[GPIO16];
        action = GPIO16;
    } else if (strstr(request, "GET /gpio/17")) {
        gpio_states[GPIO17] = !gpio_states[GPIO17];
        action = GPIO17;
    } else if (strstr(request, "GET /gpio/18")) {
        gpio_states[GPIO18] = !gpio_states[GPIO18];
        action = GPIO18;
    } else if (strstr(request, "GET /gpio/19")) {
        gpio_states[GPIO19] = !gpio_states[GPIO19];
        action = GPIO19;
    } else if (strstr(request, "GET /gpio/20")) {
        gpio_states[GPIO20] = !gpio_states[GPIO20];
        action = GPIO20;
    } else if (strstr(request, "GET /gpio/28")) {
        gpio_states[GPIO28] = !gpio_states[GPIO28];
        action = GPIO28;
    } else if (strstr(request, "GET /voltar")) {
        handle_main_menu(request);
        return;
    }

    // Aplica os estados aos GPIOs físicos
    gpio_put(gpio4, gpio_states[GPIO4]);
    gpio_put(gpio8, gpio_states[GPIO8]);
    gpio_put(gpio9, gpio_states[GPIO9]);
    gpio_put(gpio16, gpio_states[GPIO16]);
    gpio_put(gpio17, gpio_states[GPIO17]);
    gpio_put(gpio18, gpio_states[GPIO18]);
    gpio_put(gpio19, gpio_states[GPIO19]);
    gpio_put(gpio20, gpio_states[GPIO20]);
    gpio_put(gpio28, gpio_states[GPIO28]);

    // Atualiza o display OLED
    ssd1306_fill(&ssd, !cor);
    escrever(&ssd, "Estado GPIOS:", 10, 10, cor);
    char status_text[50];
    snprintf(status_text, sizeof(status_text), " 4:%d  8:%d  9:%d", 
             gpio_states[GPIO4], gpio_states[GPIO8], gpio_states[GPIO9]);
    escrever(&ssd, status_text, 5, 23, cor);
    
    snprintf(status_text, sizeof(status_text), "16:%d 17:%d 18:%d", 
             gpio_states[GPIO16], gpio_states[GPIO17], gpio_states[GPIO18]);
    escrever(&ssd, status_text, 5, 36, cor);

    snprintf(status_text, sizeof(status_text), "19:%d 20:%d 28:%d", 
             gpio_states[GPIO19], gpio_states[GPIO20], gpio_states[GPIO28]);
    escrever(&ssd, status_text, 5, 49, cor);

    // Gera a resposta HTML com botões que refletem o estado atual
    snprintf(http_response, sizeof(http_response),
             "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
             "<!DOCTYPE html><html lang='pt-BR'>"
             "<head>"
             "<meta charset='UTF-8'>"
             "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
             "<title>Controle dos GPIOs</title>"
             "<style>"
             "body { font-family: Arial, sans-serif; background-color:rgb(8, 8, 85); color: #333; margin: 0; padding: 0; }"
             "h1 { text-align: center; color:rgb(200, 107, 25); margin-top: 20px; }"
             ".container { max-width: 800px; margin: 0 auto; padding: 20px; }"
             ".grid { display: grid; grid-template-columns: repeat(4, 1fr); gap: 10px; margin-top: 30px; }"
             ".grid a { text-decoration: none; color: white; padding: 15px; border-radius: 5px; text-align: center; font-size: 18px; transition: background-color 0.3s; }"
             ".grid a.off { background-color: rgb(214, 101, 3); }"
             ".grid a.on { background-color: rgb(25, 200, 25); }"
             ".footer { text-align: center; margin-top: 50px; font-size: 14px; color: #777; }"
             "</style>"
             "</head>"
             "<body>"
             "<div class='container'>"
             "<h1>Pinos Externos</h1>"
             "<div class='grid'>"
             "<a href='/gpio/4' class='%s'>GPIO4</a>"
             "<a href='/gpio/8' class='%s'>GPIO8</a>"
             "<a href='/gpio/9' class='%s'>GPIO9</a>"
             "<a href='/gpio/16' class='%s'>GPIO16</a>"
             "<a href='/gpio/17' class='%s'>GPIO17</a>"
             "<a href='/gpio/18' class='%s'>GPIO18</a>"
             "<a href='/gpio/19' class='%s'>GPIO19</a>"
             "<a href='/gpio/20' class='%s'>GPIO20</a>"
             "<a href='/gpio/28' class='%s'>GPIO28</a>"
             "<a href='/gpio/off' class='off'>Desligar Todos</a>"
             "<a href='/voltar' class='off'>Voltar</a>"
             "</div>"
             "<div class='footer'>APLICAÇÃO IoT - Controle de GPIOs</div>"
             "<div class='footer'>Desenvolvido por ateniltonjr</div>"
             "</div>"
             "</body></html>\r\n",
             gpio_states[GPIO4] ? "on" : "off",
             gpio_states[GPIO8] ? "on" : "off",
             gpio_states[GPIO9] ? "on" : "off",
             gpio_states[GPIO16] ? "on" : "off",
             gpio_states[GPIO17] ? "on" : "off",
             gpio_states[GPIO18] ? "on" : "off",
             gpio_states[GPIO19] ? "on" : "off",
             gpio_states[GPIO20] ? "on" : "off",
             gpio_states[GPIO28] ? "on" : "off");
}