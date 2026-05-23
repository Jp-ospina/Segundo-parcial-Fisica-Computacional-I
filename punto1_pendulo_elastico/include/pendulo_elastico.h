/**
 * @file pendulo_elastico.h
 * @brief Definición de la interfaz del módulo de simulación del péndulo elástico.
 * @author Tomás A. Peñuela Z. y Juan P. Ospina G.
 * @date 25 de Mayo de 2026
 * @details Este archivo actúa como interfaz pública exponiendo los prototipos de 
 * las funciones requeridas para ejecutar el simulador numérico del péndulo-resorte.
 */

#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

/**
 * @brief Gestiona el flujo de entrada de datos, el ciclo de cómputo y la salida a disco.
 * @note Implementada en pendulo_elastico.cpp
 */
void penduloResorte();

/**
 * @brief Aplica el método numérico de Runge-Kutta de 4to orden (RK4) para avanzar el vector de estado.
 * @param t Tiempo actual de la simulación (s).
 * @param u Vector de estado actual [z, z_dot, theta, theta_dot].
 * @param m Masa del cuerpo oscilante (kg).
 * @param k Constante de elasticidad del resorte (N/m).
 * @param l0 Longitud natural del resorte en reposo (m).
 * @param g Magnitud de la aceleración de la gravedad (m/s^2).
 * @param dt Paso de integración temporal \f$\Delta t\f$ (s).
 * @return std::vector<double> Vector con el estado calculado en el instante \f$t + \Delta t\f$.
 * @note Implementada en pendulo_elastico.cpp
 */
std::vector<double> calcularDerivadas(double t, const std::vector<double> &u, double m, double k, double l0, double g, double dt);