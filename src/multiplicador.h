#ifndef MULTIPLICADOR_H
#define MULTIPLICADOR_H

/*
 * @brief Realiza la multiplicación de dos matrices en formato binario esparso
 * generando un archivo intermedio con los productos parciales.
 * 
 * @param archivo_bin_a Ruta de la matriz binaria A
 * @param archivo_bin_b Ruta de la matriz binaria B
 * @param archivo_temporal Ruta del archivo binario temporal acumulado
 */
void multiplicar_matrices_binarias(const char *archivo_bin_a, const char *archivo_bin_b, const char *archivo_temporal);

/*
 * @brief Ordena y consolida las celdas repetidas sumando sus valores,
 * generando el archivo binario definitivo con el resultado final.
 * 
 * @param archivo_temporal Ruta del archivo intermedio con duplicados
 * @param archivo_final_bin Ruta del archivo binario limpio y consolidado
 */
void consolidar_acumulado(const char *archivo_temporal, const char *archivo_final_bin);

#endif
