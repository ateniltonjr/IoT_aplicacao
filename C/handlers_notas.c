#include "H/handlers_notas.h"

void tocar_nota(int frequencia, int duracao) {
    if (frequencia == 0) {
        gpio_put(BUZZER_PIN, 0);
        return;
    }
    
    int periodo = 1000000 / frequencia;
    int metade_periodo = periodo / 2;
    
    for (int i = 0; i < duracao * 1000L / periodo; i++) {
        gpio_put(BUZZER_PIN, 1);
        sleep_us(metade_periodo);
        gpio_put(BUZZER_PIN, 0);
        sleep_us(metade_periodo);
    }
}

void handle_nota_action(const char *request) {
    NotaAction action = NOTA_OFF;

    if (strstr(request, "GET /nota/off")) {
        action = NOTA_OFF;
    } else if (strstr(request, "GET /nota/do1")) {
        action = NOTA_DO1;
    } else if (strstr(request, "GET /nota/re1")) {
        action = NOTA_RE1;
    } else if (strstr(request, "GET /nota/mi1")) {
        action = NOTA_MI1;
    } else if (strstr(request, "GET /nota/fa1")) {
        action = NOTA_FA1;
    } else if (strstr(request, "GET /nota/sol1")) {
        action = NOTA_SOL1;
    } else if (strstr(request, "GET /nota/la1")) {
        action = NOTA_LA1;
    } else if (strstr(request, "GET /nota/si1")) {
        action = NOTA_SI1;
    } else if (strstr(request, "GET /nota/do2")) {
        action = NOTA_DO2;
    } else if (strstr(request, "GET /voltar")) {
        handle_main_menu(request);
        return;
    }

    switch (action) {
        case NOTA_OFF:
            tocar_nota(0, 0);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota desligada", 5, 10, cor);
            break;
        case NOTA_DO1:
            tocar_nota(FREQ_DO1, 500);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota Do1", 5, 10, cor);
            break;
        case NOTA_RE1:
            tocar_nota(FREQ_RE1, 500);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota Re1", 5, 10, cor);
            break;
        case NOTA_MI1:
            tocar_nota(FREQ_MI1, 500);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota Mi1", 5, 10, cor);
            break;
        case NOTA_FA1:
            tocar_nota(FREQ_FA1, 500);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota Fa1", 5, 10, cor);
            break;
        case NOTA_SOL1:
            tocar_nota(FREQ_SOL1, 500);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota Sol1", 5, 10, cor);
            break;
        case NOTA_LA1:
            tocar_nota(FREQ_LA1, 500);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota La1", 5, 10, cor);
            break;
        case NOTA_SI1:
            tocar_nota(FREQ_SI1, 500);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota Si1", 5, 10, cor);
            break;
        case NOTA_DO2:
            tocar_nota(FREQ_DO2, 500);
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Nota Do2", 5, 10, cor);
            break;
    }

    snprintf(http_response, sizeof(http_response),
             "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
             "<!DOCTYPE html><html lang='pt-BR'>"
             "<head>"
             "<meta charset='UTF-8'>"
             "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
             "<title>Controle de Notas Musicais</title>"
             "<style>"
             "body { font-family: Arial, sans-serif; background-color:rgb(26, 26, 82); color: #333; margin: 0; padding: 0; }"
             "h1 { text-align: center; color:rgb(42, 214, 29); margin-top: 20px; }"
             ".container { max-width: 800px; margin: 0 auto; padding: 20px; }"
             ".grid { display: grid; grid-template-columns: repeat(4, 1fr); gap: 10px; margin-top: 30px; }"
             ".grid a { text-decoration: none; background-color: rgb(42, 214, 29); color: white; padding: 15px; border-radius: 5px; text-align: center; font-size: 18px; transition: background-color 0.3s; }"
             ".grid a:hover { background-color: rgb(42, 214, 29); }"
             ".footer { text-align: center; margin-top: 50px; font-size: 14px; color: #777; }"
             "</style>"
             "</head>"
             "<body>"
             "<div class='container'>"
             "<h1>Controle de Notas Musicais</h1>"
             "<div class='grid'>"
             "<a href='/nota/do1'>Do1</a>"
             "<a href='/nota/re1'>Re1</a>"
             "<a href='/nota/mi1'>Mi1</a>"
             "<a href='/nota/fa1'>Fa1</a>"
             "<a href='/nota/sol1'>Sol1</a>"
             "<a href='/nota/la1'>La1</a>"
             "<a href='/nota/si1'>Si1</a>"
             "<a href='/nota/do2'>Do2</a>"
             "<a href='/nota/off'>Desligar</a>"
             "<a href='/voltar'>Voltar</a>"
             "</div>"
             "<div class='footer'>APLICAÇÃO IoT - Controle de Notas Musicais</div>"
             "</div>"
             "</body></html>\r\n");
}