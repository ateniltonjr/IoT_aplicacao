#ifndef HANDLERS_MATRIZ_H
#define HANDLERS_MATRIZ_H

#include "handlers.h"

// Enumeração para as ações da matriz
typedef enum {
    MAT_OFF = 0,
    number0m,  // Função para desenhar o número 0 na matriz de LEDs
    number1m,  
    number2m,  
    number3m,  
    number4m,  
    number5m, 
    number6m, 
    number7m, 
    number8m,  
    number9m  
} matrizAction;

// Função para manipular ações da matriz
void handle_matriz_action(const char *request);

#endif // HANDLERS_MATRIZ_H