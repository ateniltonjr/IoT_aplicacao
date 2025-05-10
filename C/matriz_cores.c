#include "H/matriz_cores.h"

// Função para desenhar uma matriz com cor vermelha
void matriz_vermelha() {
    int mat[5][5][3] = {
        {{0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}},
        {{0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}},
        {{0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}},
        {{0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}},
        {{0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor verde
void matriz_verde() {
    int mat[5][5][3] = {
        {{BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}},
        {{BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}},
        {{BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}},
        {{BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}},
        {{BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor azul
void matriz_azul() {
    int mat[5][5][3] = {
        {{0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}},
        {{0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}},
        {{0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}},
        {{0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}},
        {{0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor amarela
void matriz_amarela() {
    int mat[5][5][3] = {
        {{BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}},
        {{BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}},
        {{BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}},
        {{BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}},
        {{BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}, {BRILHO, BRILHO, 0}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor ciano
void matriz_roxa() {
    int mat[5][5][3] = {
        {{0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}},
        {{0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}},
        {{0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}},
        {{0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}},
        {{0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor roxa
void matriz_ciano() {
    int mat[5][5][3] = {
        {{BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}},
        {{BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}},
        {{BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}},
        {{BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}},
        {{BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor laranja
void matriz_laranja() {
    int mat[5][5][3] = {
        {{BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}},
        {{BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}},
        {{BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}},
        {{BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}},
        {{BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}, {BRILHO / 2, BRILHO, 0}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor rosa
void matriz_turquesa() {
    int mat[5][5][3] = {
        {{BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}},
        {{BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}},
        {{BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}},
        {{BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}},
        {{BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}, {BRILHO, 0, BRILHO / 2}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor branca
void matriz_branca() {
    int mat[5][5][3] = {
        {{BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}},
        {{BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}},
        {{BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}},
        {{BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}},
        {{BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}}
    };
    desenhaMatriz(mat);
}

// Função para desenhar uma matriz com cor turquesa
void matriz_rosa() {
    int mat[5][5][3] = {
        {{0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}},
        {{0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}},
        {{0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}},
        {{0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}},
        {{0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}, {0, BRILHO, BRILHO / 2}}
    };
    desenhaMatriz(mat);
}