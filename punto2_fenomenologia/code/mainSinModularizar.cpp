/**
 * @file main.cpp
 * @brief Simulacion numerica del modelo depredador-presa
 *        de Lotka-Volterra usando RK4.
 *
 * @author Peñuela Z. Tomás A. , Ospina G. Juan P.
 * @date 2026
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>

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

/**
 * @brief Guarda encabezado del archivo.
 *
 * @param archivo Archivo de salida.
 */
void escribirEncabezado(ofstream& archivo) {

    archivo
        << "# t x y\n";
}

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
    string nombreArchivo,
    double x0,
    double y0,
    double alpha,
    double beta,
    double gamma,
    double delta,
    double t0,
    double tf,
    double dt
) {

    ofstream archivo(nombreArchivo.c_str());

    if (!archivo.is_open()) {

        cout << "Error al abrir archivo: "
             << nombreArchivo
             << endl;

        return;
    }

    archivo << fixed << setprecision(8);

    escribirEncabezado(archivo);

    vector<double> estado(2);

    estado[0] = x0;
    estado[1] = y0;

    double t = t0;

    int pasos = static_cast<int>((tf - t0) / dt);

    for (int i = 0; i <= pasos; i++) {

        archivo
            << t << " "
            << estado[0] << " "
            << estado[1] << "\n";

        estado = rungeKutta4(
            t,
            dt,
            estado,
            alpha,
            beta,
            gamma,
            delta
        );

        t += dt;
    }

    archivo.close();

    cout
        << "Archivo generado: "
        << nombreArchivo
        << endl;
}

/**
 * @brief Programa principal.
 */
int main() {

    /*
    ============================================================
    PARAMETROS FISICOS
    ============================================================
    */

    double alpha = 1.1;
    double beta = 0.4;
    double gamma = 0.4;
    double delta = 0.1;

    /*
    ============================================================
    PARAMETROS NUMERICOS
    ============================================================
    */

    double t0 = 0.0;
    double tf = 100.0;
    double dt = 0.01;

    /*
    ============================================================
    CONDICIONES INICIALES 1
    ============================================================
    */

    double x01 = 10.0;
    double y01 = 5.0;

    /*
    ============================================================
    CONDICIONES INICIALES 2
    ============================================================
    */

    double x02 = 15.0;
    double y02 = 3.0;

    /*
    ============================================================
    CONDICIONES INICIALES 3
    ============================================================
    */

    double x03 = 7.0;
    double y03 = 8.0;

    /*
    ============================================================
    EJECUCION DE SIMULACIONES
    ============================================================
    */

    ejecutarSimulacion(
        "datos_condicion1.dat",
        x01,
        y01,
        alpha,
        beta,
        gamma,
        delta,
        t0,
        tf,
        dt
    );

    ejecutarSimulacion(
        "datos_condicion2.dat",
        x02,
        y02,
        alpha,
        beta,
        gamma,
        delta,
        t0,
        tf,
        dt
    );

    ejecutarSimulacion(
        "datos_condicion3.dat",
        x03,
        y03,
        alpha,
        beta,
        gamma,
        delta,
        t0,
        tf,
        dt
    );

    cout << endl;
    cout << "Simulaciones completadas correctamente." << endl;

    return 0;
}
