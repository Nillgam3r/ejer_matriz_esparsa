#ifndef CONVERSOR_H
#define CONVERSOR_H

/*
 * @brief Estructura básica que representa cada celda no nula de la matriz esparsa.
 * Almacena la fila, columna y el valor correspondiente.
 */
typedef struct {
    int fila;
    int col;
    double valor;
} ElementoEsparso;

/*
 * @brief Lee un archivo de texto en formato COO y lo convierte a un archivo binario optimizado. 
 * @param archivo_txt Ruta del archivo de texto de origen (ej. "matriz_a.txt")
 * @param archivo_bin Ruta del archivo binario de destino (ej. "matriz_a.bin")
 */
void convertir_txt_a_binario(const char *archivo_txt, const char *archivo_bin);

#endif
