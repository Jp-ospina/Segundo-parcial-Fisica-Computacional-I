#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

/**
 * @brief Calcula las derivadas del sistema Lotka-Volterra.
 *
 * @param t Tiempo actual.
 * @param estado Vector de estado [x,y].
 * @param alpha Tasa de crecimiento de presas.
 * @param beta Tasa de depredacion.
 * @param gamma Tasa de muerte de depredadores.
 * @param delta Eficiencia reproductiva del depredador.
 *
 * @return Vector con derivadas [dx/dt, dy/dt].
 */
std::vector<double> calcularDerivadas(
    double t,
    const std::vector<double>& estado,
    double alpha,
    double beta,
    double gamma,
    double delta
);

/**
 * @brief Ejecuta un paso RK4.
 *
 * @param t Tiempo actual.
 * @param dt Paso temporal.
 * @param estado Estado actual.
 * @param alpha Parametro alpha.
 * @param beta Parametro beta.
 * @param gamma Parametro gamma.
 * @param delta Parametro delta.
 *
 * @return Nuevo estado.
 */
std::vector<double> rungeKutta4(
    double t,
    double dt,
    const std::vector<double>& estado,
    double alpha,
    double beta,
    double gamma,
    double delta
);

/**
 * @brief Ejecuta una simulacion completa.
 *
 * @param nombreArchivo Nombre del archivo .dat.
 * @param x0 Poblacion inicial de presas.
 * @param y0 Poblacion inicial de depredadores.
 * @param alpha Parametro alpha.
 * @param beta Parametro beta.
 * @param gamma Parametro gamma.
 * @param delta Parametro delta.
 * @param t0 Tiempo inicial.
 * @param tf Tiempo final.
 * @param dt Paso temporal.
 */
void ejecutarSimulacion(
    std::string nombreArchivo,
    double x0,
    double y0,
    double alpha,
    double beta,
    double gamma,
    double delta,
    double t0,
    double tf,
    double dt
);