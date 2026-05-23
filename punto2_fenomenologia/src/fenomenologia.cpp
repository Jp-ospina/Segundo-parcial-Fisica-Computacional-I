#include "fenomenologia.h"
#include <fstream>
#include <iostream>

using namespace std;

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

    // escribirEncabezado(archivo);

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