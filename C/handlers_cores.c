#include "H/handlers_cores.h"

void handle_cores_action(const char *request) {
    coresAction action = CORES_OFF;

    if (strstr(request, "GET /cores/off")) {
        action = CORES_OFF;
    } else if (strstr(request, "GET /cores/numero0c")) {
        action = CORES_VERMELHO;
    } else if (strstr(request, "GET /cores/numero1c")) {
        action = CORES_VERDE;
    } else if (strstr(request, "GET /cores/numero2c")) {
        action = CORES_AZUL;
    } else if (strstr(request, "GET /cores/numero3c")) {
        action = CORES_AMARELO;
    } else if (strstr(request, "GET /cores/numero4c")) {
        action = CORES_CIANO;
    } else if (strstr(request, "GET /cores/numero5c")) {
        action = CORES_ROXO;
    } else if (strstr(request, "GET /cores/numero6c")) {
        action = CORES_LARANJA;
    } else if (strstr(request, "GET /cores/numero7c")) {
        action = CORES_ROSA;
    } else if (strstr(request, "GET /cores/numero8c")) {
        action = CORES_BRANCO;
    } else if (strstr(request, "GET /cores/numero9c")) {
        action = CORES_TURQUESA;
    } else if (strstr(request, "GET /voltar")) {
        handle_main_menu(request);
        return;
    }

    switch (action) {
        case CORES_OFF:
            desliga();
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "Matriz", 2, 10, cor);
            escrever(&ssd, "desligada", 2, 30, cor);
            break;
        case CORES_VERMELHO:
            matriz_vermelha(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "VERMELHO", 58, 35, cor);
            break;
        case CORES_VERDE:
            matriz_verde(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "VERDE", 58, 35, cor);
            break;
        case CORES_AZUL:
            matriz_azul(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "AZUL", 48, 35, cor);
            break;
        case CORES_AMARELO:
            matriz_amarela(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "AMARELO", 25, 35, cor);
            break;
        case CORES_CIANO:
            matriz_ciano(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "CIANO", 25, 35, cor);
            break;
        case CORES_ROXO:
            matriz_roxa(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "ROXO", 48, 35, cor);
            break;
        case CORES_LARANJA:
            matriz_laranja(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "LARANJA", 25, 35, cor);
            break;
        case CORES_ROSA:
            matriz_rosa(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "ROSA", 25, 35, cor);
            break;
        case CORES_BRANCO:
            matriz_branca(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "BRANCO", 25, 35, cor);
            break;
        case CORES_TURQUESA:
            matriz_turquesa(); 
            ssd1306_fill(&ssd, !cor);
            escrever(&ssd, "TURQUESA", 25, 35, cor);
            break;
    }

    snprintf(http_response, sizeof(http_response),
             "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
             "<!DOCTYPE html><html lang='pt-BR'>"
             "<head>"
             "<meta charset='UTF-8'>"
             "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
             "<title>Controle de Cores da Matriz de LEDs</title>"
             "<style>"
             "body { font-family: Arial, sans-serif; background-color: rgb(26, 26, 82); color: #333; margin: 0; padding: 0; }"
             "h1 { text-align: center; color:rgb(193, 12, 117); margin-top: 20px; }"
             ".container { max-width: 800px; margin: 0 auto; padding: 20px; }"
             ".grid { display: grid; grid-template-columns: repeat(5, 1fr); gap: 10px; margin-top: 30px; }"
             ".grid a { text-decoration: none; background-color: rgb(193, 12, 117); color: white; padding: 15px; border-radius: 5px; text-align: center; font-size: 18px; transition: background-color 0.3s; }"
             ".grid a:hover { background-color: rgb(193, 12, 117); }"
             ".footer { text-align: center; margin-top: 50px; font-size: 14px; color: #777; }"
             "</style>"
             "</head>"
             "<body>"
             "<div class='container'>"
             "<h1>Iluminação</h1>"
             "<div class='grid'>"
             "<a href='/cores/numero0c'>Vermelho</a>"
             "<a href='/cores/numero1c'>Verde</a>"
             "<a href='/cores/numero2c'>Azul</a>"
             "<a href='/cores/numero3c'>Amarelo</a>"
             "<a href='/cores/numero4c'>Ciano</a>"
             "<a href='/cores/numero5c'>Roxo</a>"
             "<a href='/cores/numero6c'>Laranja</a>"
             "<a href='/cores/numero7c'>Rosa</a>"
             "<a href='/cores/numero8c'>Branco</a>"
             "<a href='/cores/numero9c'>Turquesa</a>"
             "<a href='/cores/off'>Desligar</a>"
             "<a href='/voltar'>Voltar</a>"
             "</div>"
             "<div class='footer'>Projeto Final do curso</div>"
             "</div>"
             "</body></html>\r\n");
}