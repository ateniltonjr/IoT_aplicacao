#include "H/handlers_matriz.h"

void handle_matriz_action(const char *request) {
    matrizAction action = MAT_OFF;

    if (strstr(request, "GET /matriz/off")) {
        action = MAT_OFF;
    } else if (strstr(request, "GET /matriz/numero0")) {
        action = number0m;
    } else if (strstr(request, "GET /matriz/numero1")) {
        action = number1m;
    } else if (strstr(request, "GET /matriz/numero2")) {
        action = number2m;
    } else if (strstr(request, "GET /matriz/numero3")) {
        action = number3m;
    } else if (strstr(request, "GET /matriz/numero4")) {
        action = number4m;
    } else if (strstr(request, "GET /matriz/numero5")) {
        action = number5m;
    } else if (strstr(request, "GET /matriz/numero6")) {
        action = number6m;
    } else if (strstr(request, "GET /matriz/numero7")) {
        action = number7m;
    } else if (strstr(request, "GET /matriz/numero8")) {
        action = number8m;
    } else if (strstr(request, "GET /matriz/numero9")) {
        action = number9m;
    } else if (strstr(request, "GET /voltar")) {
        handle_main_menu(request);
        return;
    }

    switch (action) {
        case MAT_OFF:
            desliga();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Matriz desligada", 2, 10, cor);
            break;
        case number0m:
            number0();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "0", 58, 35, cor);
            break;
        case number1m:
            number1();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "1", 58, 35, cor);
            break;
        case number2m:
            number2();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "2", 58, 35, cor);
            break;
        case number3m:
            number3();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "3", 58, 35, cor);
            break;
        case number4m:
            number4();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "4", 58, 35, cor);
            break;
        case number5m:
            number5();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "5", 58, 35, cor);
            break;
        case number6m:
            number6();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "6", 58, 35, cor);
            break;
        case number7m:
            number7();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "7", 58, 35, cor);
            break;
        case number8m:
            number8();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "8", 58, 35, cor);
            break;
        case number9m:
            number9();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "9", 58, 35, cor);
            break;
    }

    snprintf(http_response, sizeof(http_response),
             "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
             "<!DOCTYPE html><html lang='pt-BR'>"
             "<head>"
             "<meta charset='UTF-8'>"
             "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
             "<title>Exibir Números</title>"
             "<style>"
             "body { font-family: Arial, sans-serif; background-color:rgb(8, 8, 112); color: #333; margin: 0; padding: 0; }"
             "h1 { text-align: center; color:rgb(240, 220, 30); margin-top: 20px; }"
             ".container { max-width: 800px; margin: 0 auto; padding: 20px; }"
             ".grid { display: grid; grid-template-columns: repeat(5, 1fr); gap: 10px; margin-top: 30px; }"
             ".grid a { text-decoration: none; background-color:rgb(240, 220, 30); color: white; padding: 15px; border-radius: 5px; text-align: center; font-size: 18px; transition: background-color 0.3s; }"
             ".grid a:hover { background-color:rgb(240, 220, 30); }"
             ".footer { text-align: center; margin-top: 50px; font-size: 14px; color: #777; }"
             "</style>"
             "</head>"
             "<body>"
             "<div class='container'>"
             "<h1>Exibir números</h1>"
             "<div class='grid'>"
             "<a href='/matriz/numero0'>Número 0</a>"
             "<a href='/matriz/numero1'>Número 1</a>"
             "<a href='/matriz/numero2'>Número 2</a>"
             "<a href='/matriz/numero3'>Número 3</a>"
             "<a href='/matriz/numero4'>Número 4</a>"
             "<a href='/matriz/numero5'>Número 5</a>"
             "<a href='/matriz/numero6'>Número 6</a>"
             "<a href='/matriz/numero7'>Número 7</a>"
             "<a href='/matriz/numero8'>Número 8</a>"
             "<a href='/matriz/numero9'>Número 9</a>"
             "<a href='/matriz/off'>Desligar</a>"
             "<a href='/voltar'>Voltar</a>"
             "</div>"
             "<div class='footer'>Projeto Final do curso</div>"
             "</div>"
             "</body></html>\r\n");
}