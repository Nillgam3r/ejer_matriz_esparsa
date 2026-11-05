#ifndef GENERADOR_H
#define GENERADOR_H

#define MAX_DIM 1000
#define PORCENTAJE_NO_CEROS 0.05

/*@brief Genera un archivo de texto con una matriz esparsa aleatoria en formato COO. 
 * @param nombre_archivo Nombre del archivo a crear (ej. "matriz_a.txt")
 * @param filas Número de filas (M o N)
 * @param columnas Número de columnas (N o P)
 */
void generar_matriz_esparsa_txt(const char *nombre_archivo, int filas, int columnas);

#endif // GENERADOR_H
