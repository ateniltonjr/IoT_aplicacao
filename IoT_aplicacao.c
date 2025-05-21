/**************************************
 
     Arquivo principal onde você digitará 
    O nome e a senha da sua rede Wi-FI
  
 ***************************************/

#include "H/handlers.h" // Inclui o arquivo de cabeçalho com as funções de manipulação de requisições
#include "H/buttons.h" // Inclui o arquivo de cabeçalho com as funções de manipulação de botões

// Defina o SSID e a senha do Wi-Fi aqui:
const char *WIFI_SSID = "KLAZ";     // Nome da rede Wi-Fi
const char *WIFI_PASS = "10213250";// Senha da rede Wi-Fi

int depuracao_e_wifi()
{   
    printf("Iniciando servidor HTTP\n"); // Mensagem inicial
    ssd1306_fill(&ssd, !cor); //Atualiza o display
    escrever(&ssd, "Iniciando", 25, 10, cor); // Escreve uma mensagem
    escrever(&ssd, "servidor HTTP", 10, 30, cor);

    if (cyw43_arch_init()) {// Inicializa o Wi-Fi
        printf("Erro ao inicializar o Wi-Fi\n"); // Mensagem de erro
        return 1;
    }

    cyw43_arch_enable_sta_mode(); // Função para conectar-se ao WI-FI
    printf("Conectando ao Wi-Fi...\n"); // Mensagem de conexão
    ssd1306_fill(&ssd, !cor); // Atualiza o display
    escrever(&ssd, "Conectando", 25, 10, cor);// Escreve uma mensagem
    escrever(&ssd, "WI-FI", 49, 30, cor);// Escreve uma mensagem

    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASS, CYW43_AUTH_WPA2_AES_PSK, 10000)) {// Conecta-se ao WI-FI
        printf("Falha ao conectar ao Wi-Fi\n");
        ssd1306_fill(&ssd, !cor);// Atualiza o display
        escrever(&ssd, "Falha ao ", 8, 10, cor);
        escrever(&ssd, "conectar no", 8, 30, cor);
        escrever(&ssd, "servidor!", 8, 50, cor);
        return 1;
    } else {// Se a conexão for bem-sucedida
        ssd1306_fill(&ssd, !cor);
        escrever(&ssd, "Pesquise", 15, 10, cor);
        escrever(&ssd, "no GOOGLE o", 10, 30, cor);
        escrever(&ssd, "endereco IP ", 10, 50, cor);
        sleep_ms(3000);

        printf("Conectado.\n");
        uint8_t *ip_address = (uint8_t*)&(cyw43_state.netif[0].ip_addr.addr);// Obtém o endereço IP
        printf("Endereço IP: %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);// Imprime o endereço IP

        char ip_str[20];// Converte o endereço IP para string
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

    // Para ser utilizado o modo BOOTSEL com botão B
    iniciar_botoes();
    gpio_set_irq_enabled_with_callback(botaoB, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    // Fim do trecho para modo BOOTSEL com botão B

    iniciar_rgb(); // Inicialização dos leds RGB
    iniciar_gpios_externos();
    controle(PINO_MATRIZ); // Inicialização da matriz de leds
    gpio_init(BUZZER_PIN); // Inicialização do BUZZER
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Buzzer iniciado como saída

    depuracao_e_wifi(); // Mensagens de depuração

    start_http_server(); // Inicia o servidor HTTP
    
    while (true) { // LOOP inifinito 
        cyw43_arch_poll();// Mantém o Wi-Fi ativo
        sleep_ms(100);
    }

    cyw43_arch_deinit(); // Desliga o wi-fi | Este ponto nunca é alcansado
    return 0;
}