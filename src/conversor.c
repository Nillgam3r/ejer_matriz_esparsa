#include "conversor.h"
#include <stdio.h>
#include <stdlib.h>

void convertir_txt_a_binario(const char *archivo_txt, const char *archivo_bin) {
    FILE *txt = fopen(archivo_txt, "r");
    if (txt == NULL) {
        perror("Error al abrir el archivo de texto origen");
        return;
    }

    FILE *bin = fopen(archivo_bin, "wb");
    if (bin == NULL) {
        perror("Error al crear el archivo binario destino");
        fclose(txt);
        return;
    }

    int filas = 0, columnas = 0, elementos_no_nulos = 0;
    if (fscanf(txt, "%d %d %d", &filas, &columnas, &elementos_no_nulos) != 3) {
        fprintf(stderr, "Error al leer la cabecera del archivo: %s\n", archivo_txt);
        fclose(txt);
        fclose(bin);
        return;
    }

    fwrite(&filas, sizeof(int), 1, bin);
    fwrite(&columnas, sizeof(int), 1, bin);
    fwrite(&elementos_no_nulos, sizeof(int), 1, bin);

    ElementoEsparso elemento;
    int procesados = 0;

    for (int i = 0; i < elementos_no_nulos; i++) {
        if (fscanf(txt, "%d %d %lf", &elemento.fila, &elemento.col, &elemento.valor) == 3) {
            fwrite(&elemento, sizeof(ElementoEsparso), 1, bin);
            procesados++;
        } else {
            fprintf(stderr, "Advertencia: El archivo de texto terminó antes de lo esperado o formato inválido.\n");
            break;
        }
    }

    fclose(txt);
    fclose(bin);

    printf("Conversión exitosa: '%s' -> '%s' [%d elementos procesados]\n", 
           archivo_txt, archivo_bin, procesados);
}
