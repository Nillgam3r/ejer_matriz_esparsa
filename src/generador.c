#include "generador.h"
#include <stdio.h>
#include <stdlib.h>

void generar_matriz_esparsa_txt(const char *nombre_archivo, int filas, int columnas) {
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
        return;
    }

    long long total_celdas = (long long)filas * columnas;
    int elementos_no_nulos = (int)(total_celdas * PORCENTAJE_NO_CEROS);
    
    if (elementos_no_nulos == 0 && total_celdas > 0) {
        elementos_no_nulos = 1;
    }

    fprintf(archivo, "%d %d %d\n", filas, columnas, elementos_no_nulos);

    int creados = 0;
    while (creados < elementos_no_nulos) {
        int r_fila = rand() % filas;
        int r_col = rand() % columnas;
        
        double valor = 1.0 + ((double)rand() / RAND_MAX) * 99.0;

        fprintf(archivo, "%d %d %.2f\n", r_fila, r_col, valor);
        creados++;
    }

    fclose(archivo);
    printf("Archivo '%s' generado exitosamente (%d elementos no nulos).\n", nombre_archivo, elementos_no_nulos);
}
