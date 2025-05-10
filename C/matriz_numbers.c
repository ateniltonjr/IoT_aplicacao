#include "H/matriz_numbers.h"

// Função para desenhar o número 0 na matriz de LEDs
void number0() {  
    int mat1[5][5][3] = {  // Matriz tridimensional para representar a cor de cada LED (5x5)
        {{0, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {0, 0, 0}},   // Linha 0
        {{0, 0, 0}, {BRILHO, 0, 0}, {0, 0, 0}, {BRILHO, 0, 0},  {0, 0, 0}},      // Linha 1
        {{0, 0, 0}, {BRILHO, 0, 0}, {0, 0, 0}, {BRILHO, 0, 0},  {0, 0, 0}},     // Linha 2
        {{0, 0, 0}, {BRILHO, 0, 0}, {0, 0, 0}, {BRILHO, 0, 0},  {0, 0, 0}},    // Linha 3
        {{0, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {BRILHO, 0, 0}, {0, 0, 0}}// Linha 4
    };
    desenhaMatriz(mat1);
}
void number1() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {0, 0, 0}, {0, BRILHO, 10}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, BRILHO, 10}, {0, BRILHO, 10}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, BRILHO, 10}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, BRILHO, 10}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, BRILHO, 10}, {0, BRILHO, 10}, {0, BRILHO, 10}, {0, 0, 0}}
    };
    desenhaMatriz(mat1);
}
void number2() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {0, 10, BRILHO}, {0, 10, BRILHO}, {0, 10, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 10, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 10, BRILHO}, {0, 10, BRILHO}, {0, 10, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 10, BRILHO}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 10, BRILHO}, {0, 10, BRILHO}, {0, 10, BRILHO}, {0, 0, 0}}
    };
    desenhaMatriz(mat1);
}
void number3() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {100, BRILHO, 0}, {100, BRILHO, 0}, {100, BRILHO, 0}, {0, 0, 0  }},
        {{0, 0, 0}, {0, 0, 0},     {0, 0,     0}, {100, BRILHO, 0}, {0, 0,   0}},
        {{0, 0, 0}, {100, BRILHO, 0}, {100, BRILHO, 0}, {100, BRILHO, 0}, {0, 0,   0}},
        {{0, 0, 0}, {0, 0, 0},     {0, 0,     0}, {100, BRILHO, 0}, {0, 0,   0}},
        {{0, 0, 0}, {100, BRILHO, 0}, {100, BRILHO, 0}, {100, BRILHO, 0}, {0, 0,   0}}
    };
    desenhaMatriz(mat1);
}
void number4() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}}
    };
    desenhaMatriz(mat1);
}
void number5() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, BRILHO, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, BRILHO, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, BRILHO, 0}, {0, 0, 0}}
    };
    desenhaMatriz(mat1);
}
void number6() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}, {0, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, BRILHO}, {0, 0, 0}}
    };
    desenhaMatriz(mat1);
}
void number7() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, BRILHO, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, BRILHO, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, BRILHO, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, BRILHO, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, BRILHO, BRILHO}, {0, 0, 0}}
    };
    desenhaMatriz(mat1);
}
void number8() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {BRILHO, 0, BRILHO}, {0, 0, 0}, {BRILHO, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {BRILHO, 0, BRILHO}, {0, 0, 0}, {BRILHO, 0, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {BRILHO, 0, BRILHO}, {0, 0, 0}}
    };
    desenhaMatriz(mat1);
}
void number9() {
    int mat1[5][5][3] = {
        {{0, 0, 0}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {BRILHO, BRILHO, BRILHO}, {0, 0, 0}, {BRILHO, BRILHO, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {BRILHO, BRILHO, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {BRILHO, BRILHO, BRILHO}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {BRILHO, BRILHO, BRILHO}, {0, 0, 0}}
    };
    desenhaMatriz(mat1);
}