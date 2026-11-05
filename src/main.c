#include "generador.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Únicamente aquí para inicializar la semilla con el reloj

int main() {
    // Inicializar la semilla de números aleatorios una sola vez
    srand((unsigned int)time(NULL));

    // Definir dimensiones válidas y compatibles para la multiplicación:
    // Matriz A (M x N) y Matriz B (N x P)
    int M = 1000; 
    int N = 1000;  
    int P = 1000; 

    printf("Iniciando Paso 1: Generación de matrices en texto...\n");

    // Generar Matriz A (M x N) -> "matriz_a.txt"
    generar_matriz_esparsa_txt("matriz_a.txt", M, N);

    // Generar Matriz B (N x P) -> "matriz_b.txt"
    generar_matriz_esparsa_txt("matriz_b.txt", N, P);

    printf("Paso 1 completado con éxito.\n");
    return 0;
}
