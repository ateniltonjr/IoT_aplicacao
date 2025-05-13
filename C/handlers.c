#include "H/handlers.h"
  
char http_response[2048];
ssd1306_t ssd;
bool cor = true;

void display() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init(&ssd, WIDTH, HEIGHT, false, ENDERECO, I2C_PORT);
    ssd1306_config(&ssd);
    ssd1306_send_data(&ssd);

    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);
}

void escrever(ssd1306_t *display, const char *texto, uint8_t x, uint8_t y, bool cor) {
    ssd1306_draw_string(display, texto, x, y);
    ssd1306_send_data(display);
}

void handle_main_menu(const char *request) {
    if (strstr(request, "GET /matriz")) {
        handle_matriz_action(request);
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
    
snprintf(http_response, sizeof(http_response),
         "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
         "<!DOCTYPE html><html lang='pt-BR'>"
         "<head>"
         "<meta charset='UTF-8'>"
         "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
         "<title>Controle de LEDs</title>"
         "<style>"
         "body { font-family: Arial, sans-serif; background-color:rgb(26, 26, 82); color: #333; margin: 0; padding: 0; }"
         "h1 { text-align: center; color:rgb(190, 25, 20); margin-top: 20px; }"
         ".container { max-width: 800px; margin: 0 auto; padding: 20px; }"
         ".menu { display: flex; flex-wrap: wrap; justify-content: center; gap: 20px; margin-top: 30px; }"
         ".menu-row { display: flex; justify-content: center; width: 100%; gap: 20px; margin-bottom: 20px; }"
         ".menu a { text-decoration: none; background-color:rgb(190, 25, 20); color: white; padding: 15px 30px; border-radius: 5px; font-size: 18px; transition: background-color 0.3s; flex: 0 0 calc(50% - 40px); text-align: center; max-width: 300px; box-sizing: border-box; }"
         ".menu a:hover { background-color:rgb(160, 20, 15); }"
         ".footer { text-align: center; margin-top: 50px; font-size: 14px; color: #777; }"
         "</style>"
         "</head>"
         "<body>"
         "<div class='container'>"
         "<h1>Bem-vindo</h1>"
         "<div class='menu'>"
         "<div class='menu-row'>"
         "<a href='/matriz'>Exibir números</a>"
         "<a href='/cores'>Iluminação</a>"
         "<a href='/gpio'>Pinos Externos</a>"
         "</div>"
         "<div class='menu-row'>"
         "<a href='/led'>Controle dos LEDs RGB</a>"
         "<a href='/nota'>Controle de Notas Musicais</a>"
         "</div>"
         "</div>"
         "<div class='footer'>APLICAÇÃO IoT</div>"
         "<div class='footer'>Desenvolvido por ateniltonjr"
         "</div>"
         "</body></html>\r\n");
}

err_t http_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {
    if (p == NULL) {
        tcp_close(tpcb);
        return ERR_OK;
    }

    char *request = (char *)p->payload;

    if (strstr(request, "GET /matriz")) {
        handle_matriz_action(request);
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
    
    tcp_write(tpcb, http_response, strlen(http_response), TCP_WRITE_FLAG_COPY);
    pbuf_free(p);

    return ERR_OK;
}

err_t connection_callback(void *arg, struct tcp_pcb *newpcb, err_t err) {
    tcp_recv(newpcb, http_callback);
    return ERR_OK;
}

void start_http_server(void) {
    struct tcp_pcb *pcb = tcp_new();
    if (!pcb) {
        printf("Erro ao criar PCB\n");
        return;
    }

    if (tcp_bind(pcb, IP_ADDR_ANY, 80) != ERR_OK) {
        printf("Erro ao ligar o servidor na porta 80\n");
        return;
    }

    pcb = tcp_listen(pcb);
    tcp_accept(pcb, connection_callback);

    printf("Servidor HTTP rodando na porta 80...\n");
}