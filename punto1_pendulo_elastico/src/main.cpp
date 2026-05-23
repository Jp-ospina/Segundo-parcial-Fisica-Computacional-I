/**
 * @file main.cpp
 * @brief Punto de entrada principal para la simulación del péndulo elástico.
 * @author Tomás A. Peñuela Z. y Juan P. Ospina G.
 * @date 25 de Mayo de 2026
 * @details Este archivo inicializa la ejecución del programa invocando el bucle 
 * principal de simulación del péndulo-resorte definido de forma modular.
 */

#include "../include/pendulo_elastico.h"

/**
 * @brief Función de entrada principal del programa.
 * @return int Estado de finalización de la ejecución (0 si es exitoso).
 */
int main() {
    penduloResorte();
    return 0;
}