#ifndef HANDLERS_NOTAS_H
#define HANDLERS_NOTAS_H

#include "handlers.h"
#include "H/notas.h"

// Enumeração para as ações das notas musicais
typedef enum {
    NOTA_OFF = 0,
    NOTA_DO1,
    NOTA_RE1,
    NOTA_MI1,
    NOTA_FA1,
    NOTA_SOL1,
    NOTA_LA1,
    NOTA_SI1,
    NOTA_DO2
} NotaAction;

// Função para manipular ações das notas musicais
void handle_nota_action(const char *request);

#endif // HANDLERS_NOTAS_H