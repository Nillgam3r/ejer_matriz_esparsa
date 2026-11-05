#include "multiplicador.h"
#include "conversor.h"
#include <stdio.h>
#include <stdlib.h>

int comparar_elementos(const void *a, const void *b) {
    ElementoEsparso *elemA = (ElementoEsparso *)a;
    ElementoEsparso *elemB = (ElementoEsparso *)b;
    
    if (elemA->fila != elemB->fila) {
        return elemA->fila - elemB->fila;
    }
    return elemA->col - elemB->col;
}

void multiplicar_matrices_binarias(const char *archivo_bin_a, const char *archivo_bin_b, const char *archivo_temporal) {
    FILE *fa = fopen(archivo_bin_a, "rb");
    FILE *fb = fopen(archivo_bin_b, "rb");
    FILE *ftemp = fopen(archivo_temporal, "wb");

    if (!fa || !fb || !ftemp) {
        perror("Error al abrir archivos en la multiplicación");
        if (fa) fclose(fa);
        if (fb) fclose(fb);
        if (ftemp) fclose(ftemp);
        return;
    }

    int filasA, colA, nroA;
    int filasB, colB, nroB;
    
    if (fread(&filasA, sizeof(int), 1, fa) != 1 || fread(&colA, sizeof(int), 1, fa) != 1 || fread(&nroA, sizeof(int), 1, fa) != 1 ||
        fread(&filasB, sizeof(int), 1, fb) != 1 || fread(&colB, sizeof(int), 1, fb) != 1 || fread(&nroB, sizeof(int), 1, fb) != 1) {
        fprintf(stderr, "Error al leer las cabeceras binarias.\n");
        fclose(fa); fclose(fb); fclose(ftemp);
        return;
    }

    if (colA != filasB) {
        fprintf(stderr, "Error: Las dimensiones de las matrices no son compatibles para multiplicación.\n");
        fclose(fa); fclose(fb); fclose(ftemp);
        return;
    }

    long pos_datos_b = sizeof(int) * 3;

    ElementoEsparso elemA;
    ElementoEsparso elemB;
    int productos_parciales_escritos = 0;

    for (int i = 0; i < nroA; i++) {
        if (fread(&elemA, sizeof(ElementoEsparso), 1, fa) != 1) break;

        fseek(fb, pos_datos_b, SEEK_SET);

        for (int j = 0; j < nroB; j++) {
            if (fread(&elemB, sizeof(ElementoEsparso), 1, fb) != 1) break;
