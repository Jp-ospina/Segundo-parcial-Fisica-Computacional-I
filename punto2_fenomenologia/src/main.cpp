#include "../include/fenomenologia.h"

// using namespace std;

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

    // cout << endl;
    // cout << "Simulaciones completadas correctamente." << endl;

    return 0;
}
