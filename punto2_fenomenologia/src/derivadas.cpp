#include "fenomenologia.h"

using namespace std;

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
vector<double> calcularDerivadas(
    double t,
    const vector<double>& estado,
    double alpha,
    double beta,
    double gamma,
    double delta
) {

    double x = estado[0];
    double y = estado[1];

    double dxdt = alpha * x - beta * x * y;
    double dydt = delta * x * y - gamma * y;

    vector<double> derivadas(2);

    derivadas[0] = dxdt;
    derivadas[1] = dydt;

    return derivadas;
}