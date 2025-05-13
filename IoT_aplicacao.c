/**************************************
 
     Arquivo principal onde você digitará 
    O nome e a senha da sua rede Wi-FI
  
 ***************************************/

#include "H/handlers.h"
#include "H/buttons.h"

// Defina o SSID e a senha do Wi-Fi aqui:
const char *WIFI_SSID = "KLAZ"; // Nome do WI-FI
const char *WIFI_PASS = "10213250"; // Senha do WI-FI

int depuracao_wifi()
{   
    printf("Iniciando servidor HTTP\n"); // Mensagem inicial
    ssd1306_fill(&ssd, !cor); //Atualiza o display
    escrever(&ssd, "Iniciando", 25, 10, cor); // Escreve uma mensagem
    escrever(&ssd, "servidor HTTP", 10, 30, cor);

    if (cyw43_arch_init()) {
        printf("Erro ao inicializar o Wi-Fi\n");
        return 1;
    }

    cyw43_arch_enable_sta_mode(); // Função para conectar-se ao WI-FI
    printf("Conectando ao Wi-Fi...\n");
    ssd1306_fill(&ssd, !cor);
    escrever(&ssd, "Conectando", 25, 10, cor);
    escrever(&ssd, "WIFI", 50, 30, cor);

    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASS, CYW43_AUTH_WPA2_AES_PSK, 10000)) {
        printf("Falha ao conectar ao Wi-Fi\n");
        ssd1306_fill(&ssd, !cor);
        escrever(&ssd, "Falha ao ", 8, 10, cor);
        escrever(&ssd, "conectar no", 8, 30, cor);
        escrever(&ssd, "servidor!", 8, 50, cor);
        return 1;
    } else {
        ssd1306_fill(&ssd, !cor);
        escrever(&ssd, "Pesquise", 15, 10, cor);
        escrever(&ssd, "no GOOGLE o", 10, 30, cor);
        escrever(&ssd, "endereco IP ", 10, 50, cor);
        sleep_ms(3000);

        printf("Conectado.\n");
        uint8_t *ip_address = (uint8_t*)&(cyw43_state.netif[0].ip_addr.addr);
        printf("Endereço IP: %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);

        char ip_str[20];
        ssd1306_fill(&ssd, !cor);
        escrever(&ssd, "Endereco IP:", 20, 10, cor);
        snprintf(ip_str, sizeof(ip_str), "%d.%d.%d.%d", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
        escrever(&ssd, ip_str, 15, 35, cor);
    }

        printf("Wi-Fi conectado!\n");
        printf("Para acessar as funcionalidades, acesse o Endereço IP\n");
}

int main() {
    stdio_init_all(); //Inicialização da comunicação serial
    display(); // Inicialização do display
    sleep_ms(100); // Delay de 100 ms
    
    depuracao_wifi(); // Mensagens de depuração

    // Para ser utilizado o modo BOOTSEL com botão B
    iniciar_botoes();
    gpio_set_irq_enabled_with_callback(botaoB, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    // Fim do trecho para modo BOOTSEL com botão B

    iniciar_rgb(); // Inicialização dos leds RGB
    controle(PINO_MATRIZ); // Inicialização da matriz de leds
    gpio_init(BUZZER_PIN); // Inicialização do BUZZER
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Buzzer iniciado como saída

    start_http_server(); // Inicia o servidor HTTP
    
    while (true) { // LOOP inifinito 
        cyw43_arch_poll();
        sleep_ms(100);
    }

    cyw43_arch_deinit(); // Desliga o wi-fi | Este ponto nunca é alcansado
    return 0;
}