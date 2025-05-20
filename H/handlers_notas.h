#ifndef HANDLERS_NOTAS_H
#define HANDLERS_NOTAS_H

#include "H/handlers.h"

#define BUZZER_PIN 21

#define FREQ_DO1   131
#define FREQ_RE1   147
#define FREQ_MI1   165
#define FREQ_FA1   175
#define FREQ_SOL1  196
#define FREQ_LA1   220
#define FREQ_SI1   247
#define FREQ_DO2   262

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