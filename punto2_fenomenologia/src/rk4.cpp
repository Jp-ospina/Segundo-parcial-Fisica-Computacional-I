#include "fenomenologia.h"
#include <vector>
#include <string>

using namespace std;

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
vector<double> rungeKutta4(
    double t,
    double dt,
    const vector<double>& estado,
    double alpha,
    double beta,
    double gamma,
    double delta
) {

    vector<double> k1(2);
    vector<double> k2(2);
    vector<double> k3(2);
    vector<double> k4(2);

    vector<double> temp(2);
    vector<double> nuevoEstado(2);

    k1 = calcularDerivadas(
        t,
        estado,
        alpha,
        beta,
        gamma,
        delta
    );

    for (int i = 0; i < 2; i++) {
        temp[i] = estado[i] + 0.5 * dt * k1[i];
    }

    k2 = calcularDerivadas(
        t + 0.5 * dt,
        temp,
        alpha,
        beta,
        gamma,
        delta
    );

    for (int i = 0; i < 2; i++) {
        temp[i] = estado[i] + 0.5 * dt * k2[i];
    }

    k3 = calcularDerivadas(
        t + 0.5 * dt,
        temp,
        alpha,
        beta,
        gamma,
        delta
    );

    for (int i = 0; i < 2; i++) {
        temp[i] = estado[i] + dt * k3[i];
    }

    k4 = calcularDerivadas(
        t + dt,
        temp,
        alpha,
        beta,
        gamma,
        delta
    );

    for (int i = 0; i < 2; i++) {

        nuevoEstado[i] =
            estado[i]
            + (dt / 6.0)
            * (
                k1[i]
                + 2.0 * k2[i]
                + 2.0 * k3[i]
                + k4[i]
            );
    }

    return nuevoEstado;
}
