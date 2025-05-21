![Capa do Projeto](https://github.com/user-attachments/assets/f2a5c9b8-6208-4723-8f46-1d74be421827)

# **Sistema IoT Avançado para Automação Residencial**  

**Autor:** Atenilton Santos de Souza Júnior 

Este projeto é uma **solução completa de IoT** desenvolvida utilizando o **Raspberry Pi Pico W** e o **kit BitDogLab**, implementando um sistema de controle remoto multifuncional via Wi-Fi com aplicação em automação residencial. 

---

## **Sumário**
1. [Objetivo do Projeto](#objetivo-do-projeto)  
2. [Funcionalidades Implementadas](#funcionalidades-implementadas)  
3. [Hardware Utilizado](#hardware-utilizado)  
4. [Software e Bibliotecas](#software-e-bibliotecas)  
5. [Configuração e Uso](#configuração-e-uso)  
6. [Vídeo de Demonstração](#vídeo-de-demonstração)  
7. [Contribuições](#contribuições)  

---

## **Objetivo do Projeto**
Este sistema integrado visa demonstrar na prática conceitos de **Internet das Coisas (IoT)** através de:

- **Raspberry Pi Pico W** (com Wi-Fi integrado)
- **Kit BitDogLab** completo
- **Protocolos HTTP/WebSocket** para comunicação
- **Controle multimodal** de dispositivos

Principais aplicações:
🏠 Automação residencial inteligente  
🎛️ Controle remoto de iluminação e dispositivos  
🎵 Sistema de alertas sonoros personalizáveis  

---

## **Funcionalidades Implementadas**

### **1. Controle Avançado de LEDs**
- **LEDs RGB:**  
  - 16 milhões de cores via código hexadecimal  
  - Ajuste fino de intensidade  
  - Transições suaves entre cores  

- **Matriz 5x5 WS2812:**  
  - Dois modos operacionais:  
    • **Numérico:** Exibição de 0-9 com cores customizáveis  
    • **Iluminação:** Efeitos dinâmicos (respiração, pulsação)  
  - Animações de transição entre estados  

### **2. Sistema de Sonorização**
- **Buzzer Musical:**  
  - Escala diatônica completa (Dó a Si)  
  - Precisão de frequência (±1Hz)  
  - Duração controlável (100-2000ms)  
  - Alertas sonoros programáveis  

### **3. Gerenciamento de Dispositivos**
- **Controle GPIO Externo:**  
  - 4 pinos configuráveis como saída digital  
  - Proteção contra curto-circuitos  
  - Temporização programável  

### **4. Interface Intuitiva**
- **Portal Web Responsivo:**  
  - Controle unificado de todos os periféricos  
  - Modo adaptável para mobile/desktop  
  - Visualização em tempo real do status  

### **5. Recursos de Sistema**
- **Conexão Wi-Fi Resiliente:**  
  - Modo STA + AP (fallback automático)  
  - Reconexão automática  
- **Reset Seguro:**  
  - Ativação por botão físico  
  - Confirmação visual  

---

## **Hardware Utilizado**
- **Raspberry Pi Pico W** (com Wi-Fi 2.4GHz)
- **Kit BitDogLab Completo:**
  - LEDs RGB (3 canais)
  - Matriz de LEDs WS2812 (5x5)
  - Buzzer piezoelétrico
  - Display OLED SSD1306 (128x64)
  - Botões programáveis

---

## **Software e Bibliotecas**
- **Linguagem:** C (com otimizações para IoT)
- **Bibliotecas Principais:**
  - `pico/cyw43_arch.h` (Wi-Fi seguro)
  - `ws2812.pio.h` (controle matriz LED)
  - `hardware/pwm.h` (geração notas musicais)
  - `lwip/httpd.h` (servidor web leve)

---

## **Configuração e Uso**

### **1. Pré-requisitos**

- Raspberry Pi Pico W
- 
- Kit BitDogLab montado
- 
- IDE configurada (VS Code/Pico SDK)

### **2. Instalação**

bash

git clone https://github.com/ateniltonjr/IoT_aplicacao.git

cd IoT_aplicacao

### 3. Configuração Wi-Fi
   
Edite config.h com suas credenciais:

c

#define WIFI_SSID "SUA_REDE"

#define WIFI_PASSWORD "SUA_SENHA"

### 4. Compilação
   
bash

mkdir build && cd build

cmake ..

make

### 6. Upload
Conecte o Pico em modo BOOTSEL

Copie o arquivo iot_aplicacao.uf2

## Vídeo de Demonstração
▶ Assista a demonstração completa
[Video aqui](https://www.youtube.com/watch?v=uucASxBZI4Y)

## Contribuições

### Siga este fluxo para contribuir:

- Faça um fork do projeto

- Crie sua branch:

bash

git checkout -b minha-melhoria

- Envie suas alterações:

- bash

- git push origin minha-melhoria

- Abra um Pull Request

