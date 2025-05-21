#include "H/handlers.h"
  
char http_response[2048]; // Buffer para armazenar a resposta HTTP

void handle_main_menu(const char *request) {  // Função para exibir o menu principal
    if (strstr(request, "GET /matriz")) {    // Verifica se a requisição é para a matriz
        handle_matriz_action(request);      // Chama a função de manipulação da matriz
        return;
    } else if (strstr(request, "GET /cores")) {
        handle_cores_action(request);
        return;
    } else if (strstr(request, "GET /led")) {
        handle_led_action(request);
        return;
    } else if (strstr(request, "GET /nota")) {
        handle_nota_action(request);
        return;
    } else if (strstr(request, "GET /gpio")) {
        handle_gpios_action(request);
        return;
    }
    
snprintf(http_response, sizeof(http_response), // Cria a resposta HTTP
         "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n" // Cabeçalho HTTP
         "<!DOCTYPE html><html lang='pt-BR'>"               // Início do HTML
         "<head>" // Cabeçalho do HTML
         "<meta charset='UTF-8'>" // Define o charset
         "<meta name='viewport' content='width=device-width, initial-scale=1.0'>" // Define a viewport
         "<title>Controle de LEDs</title>" // Título da página
         "<style>" // Estilos CSS
         "body { font-family: Arial, sans-serif; background-color:rgb(26, 26, 82); color: #333; margin: 0; padding: 0; }"
         "h1 { text-align: center; color:rgb(190, 25, 20); margin-top: 20px; }" // Título
         ".container { max-width: 800px; margin: 0 auto; padding: 20px; }" // Container
         ".menu { display: flex; flex-wrap: wrap; justify-content: center; gap: 20px; margin-top: 30px; }" // Menu
         ".menu-row { display: flex; justify-content: center; width: 100%; gap: 20px; margin-bottom: 20px; }" // Linha do menu
         ".menu a { text-decoration: none; background-color:rgb(190, 25, 20); color: white; padding: 15px 30px; border-radius: 5px; font-size: 18px; transition: background-color 0.3s; flex: 0 0 calc(50% - 40px); text-align: center; max-width: 300px; box-sizing: border-box; }"
         ".menu a:hover { background-color:rgb(160, 20, 15); }"
         ".footer { text-align: center; margin-top: 50px; font-size: 14px; color: #777; }"
         "</style>"
         "</head>"
         "<body>" // Corpo do HTML
         "<div class='container'>" // Container
         "<h1>Bem-vindo</h1>" // Título
         "<div class='menu'>"// Menu
         "<div class='menu-row'>"// Linha do menu
         "<a href='/matriz'>Exibir números</a>" // Link para exibir números
         "<a href='/cores'>Iluminação</a>"
         "<a href='/gpio'>Pinos Externos</a>"
         "</div>" // Fecha a linha do menu
         "<div class='menu-row'>" // Nova linha do menu
         "<a href='/led'>Controle dos LEDs RGB</a>" // Link para controle dos LEDs
         "<a href='/nota'>Controle de Notas Musicais</a>"
         "</div>"
         "</div>"
         "<div class='footer'>APLICAÇÃO IoT</div>" // Rodapé
         "<div class='footer'>Desenvolvido por ateniltonjr"
         "</div>"
         "</body></html>\r\n"); // Fecha o HTML
}

err_t http_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) { // Função de callback para processar requisições HTTP
    if (p == NULL) { // Verifica se o pacote é nulo
        tcp_close(tpcb); // Fecha a conexão
        return ERR_OK; // Retorna erro
    }

    char *request = (char *)p->payload; // Obtém o payload do pacote

    if (strstr(request, "GET /matriz")) { // Verifica se a requisição é para a matriz
        handle_matriz_action(request); // Chama a função de manipulação da matriz
    } else if (strstr(request, "GET /cores")) {
        handle_cores_action(request);
    } else if (strstr(request, "GET /led")) {
        handle_led_action(request);
    } else if (strstr(request, "GET /nota")) {
        handle_nota_action(request);
    }  else if (strstr(request, "GET /gpio")) {
        handle_gpios_action(request);
    } else {
        handle_main_menu(request);
    }
    
    tcp_write(tpcb, http_response, strlen(http_response), TCP_WRITE_FLAG_COPY); // Envia a resposta HTTP
    pbuf_free(p); // Libera o buffer do pacote

    return ERR_OK; // Retorna erro
}

err_t connection_callback(void *arg, struct tcp_pcb *newpcb, err_t err) { // Callback de conexão
    tcp_recv(newpcb, http_callback); // Associa a função de callback à conexão
    return ERR_OK; // Retorna erro
}

void start_http_server(void) { // Função de setup do servidor TCP
    struct tcp_pcb *pcb = tcp_new(); // Cria um novo PCB (Protocol Control Block)
    if (!pcb) { // Verifica se o PCB foi criado com sucesso
        printf("Erro ao criar PCB\n");
        return;
    }

    if (tcp_bind(pcb, IP_ADDR_ANY, 80) != ERR_OK) { // Liga o PCB à porta 80
        printf("Erro ao ligar o servidor na porta 80\n");
        return;
    }

    pcb = tcp_listen(pcb); // Coloca o PCB em modo de escuta
    tcp_accept(pcb, connection_callback);

    printf("Servidor HTTP rodando na porta 80...\n");
}