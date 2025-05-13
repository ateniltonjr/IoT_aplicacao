![Capa do Projeto](https://github.com/user-attachments/assets/f2a5c9b8-6208-4723-8f46-1d74be421827)

# **Tarefa de Aplicação IoT com BitDogLab e Raspberry Pi Pico W**

**Autor:** Atenilton Santos de Souza Júnior  

Este projeto é uma **tarefa prática de IoT** desenvolvida utilizando o **Raspberry Pi Pico W** e o **kit BitDogLab**. O objetivo é implementar um sistema de controle remoto via Wi-Fi com funcionalidades básicas de IoT, incluindo uma nova função de **ILUMINAÇÃO** para controle de LEDs.

---

## **Sumário**
1. [Objetivo da Tarefa](#objetivo-da-tarefa)  
2. [Funcionalidades Implementadas](#funcionalidades-implementadas)  
3. [Hardware Utilizado](#hardware-utilizado)  
4. [Software e Bibliotecas](#software-e-bibliotecas)  
5. [Configuração e Uso](#configuração-e-uso)  
6. [Vídeo de Demonstração](#vídeo-de-demonstração)  
7. [Contribuições](#contribuições)  

---

## **Objetivo da Tarefa**
Esta atividade visa aplicar conceitos de **Internet das Coisas (IoT)** utilizando:
- **Raspberry Pi Pico W** (com Wi-Fi integrado)
- **Kit BitDogLab** (LEDs RGB, matriz WS2812, buzzer e display SSD1306)
- **Protocolo HTTP** para comunicação via Wi-Fi

O sistema permite:
✅ Controle remoto de LEDs RGB  
✅ Função de **ILUMINAÇÃO** (novo recurso)  
✅ Exibição de informações no display  
✅ Reprodução de notas musicais  

---

## **Funcionalidades Implementadas**

### **1. Controle de LEDs RGB**
- Ajuste de **cores** (R, G, B)
- Controle de **intensidade**

### **2. ILUMINAÇÃO (Nova Função)**
- Ativação/desativação de LEDs
- Modos pré-configurados (ex.: piscar, fade)

### **3. Matriz de LEDs WS2812**
- Exibição de padrões e animações

### **4. Buzzer**
- Reprodução de notas musicais

### **5. Display SSD1306**
- Mostra **endereço IP** para conexão

### **6. Interface Web**
- Página HTML com botões para controle

---

## **Hardware Utilizado**
- **Raspberry Pi Pico W** (com Wi-Fi)
- **Kit BitDogLab**
  - LEDs RGB
  - Matriz de LEDs WS2812
  - Buzzer
  - Display OLED SSD1306

---

## **Software e Bibliotecas**
- **Linguagem:** C (com Raspberry Pi Pico SDK)
- **Bibliotecas:**
  - `pico/stdlib.h`
  - `pico/cyw43_arch.h` (Wi-Fi)
  - `hardware/i2c.h` (display)
  - `ws2812.pio.h` (matriz de LEDs)

---

## **Configuração e Uso**

### **1. Clone o Repositório**
```bash```
git clone https://github.com/ateniltonjr/proj_wifi.git
cd proj_wifi
2. Configure a Rede Wi-Fi
Edite config.h e insira:

c
#define WIFI_SSID "SUA_REDE"
#define WIFI_PASSWORD "SENHA"
3. Compile e Carregue
bash
mkdir build && cd build
cmake ..
make
→ Transfira o .uf2 para o Pico.

Alternativa (VS Code + Extensão Pico)
Importe a pasta no VS Code

Compile usando a extensão Raspberry Pi Pico

Vídeo de Demonstração
▶ Assista ao teste aqui

Contribuições
Contribuições são bem-vindas! Siga os passos:

Faça um fork do repositório

Crie uma branch:

bash
git checkout -b feature/nova-funcionalidade
Envie as alterações:

bash
git push origin feature/nova-funcionalidade
Abra um Pull Request

Nota: Este projeto é uma tarefa de IoT e não o produto final. Foi desenvolvido para aplicação prática com o BitDogLab.

🔗 Repositório: github.com/ateniltonjr/proj_wifi


Você pode copiar este texto diretamente para o arquivo README.md do seu repositório no GitHub. O formato está otimizado para:
- Visualização correta no GitHub
- Links funcionais
- Seções bem organizadas
- Destaque para as novas funcionalidades
- Compatibilidade com markdown do GitHub

Recomendo verificar a URL da imagem de capa para garantir que esteja acessível publicamente.
