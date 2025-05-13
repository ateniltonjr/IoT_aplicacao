#ifndef HANDLERS_CORES_H
#define HANDLERS_CORES_H

#include "H/handlers.h"
#include "H/matriz_cores.h"

// Enumeração para as ações da matriz
typedef enum {
    CORES_OFF,
    CORES_VERMELHO,
    CORES_VERDE,
    CORES_AZUL,
    CORES_AMARELO,
    CORES_CIANO,
    CORES_ROXO,
    CORES_LARANJA,
    CORES_ROSA,
    CORES_BRANCO,
    CORES_TURQUESA
} coresAction;

// Função para manipular ações da matriz
void handle_cores_action(const char *request);

#endif // HANDLERS_MATRIZ_H