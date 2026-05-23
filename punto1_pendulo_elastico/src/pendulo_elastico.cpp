#include "pendulo_elastico.h"

using namespace std;

void penduloResorte() {
    double m, k, l0, g = 9.81;
    double z0, vz0, theta0_deg, omega0;
    double t, tf, dt;
    const double PI = 3.14159265358979323846;

    cout << "--- Parametros Fisicos del Pendulo-Resorte ---\n";
    do {
        cout << "Masa (m) [kg]: "; cin >> m;
        if (m <= 0.0) cout << "Error: la masa debe ser mayor que cero.\n";
    } while (m <= 0.0);

    do {
        cout << "Constante elastica (k) [N/m]: "; cin >> k;
        if (k <= 0.0) cout << "Error: la constante elastica debe ser mayor que cero.\n";
    } while (k <= 0.0);

    do {
        cout << "Longitud natural (l0) [m]: "; cin >> l0;
        if (l0 <= 0.0) cout << "Error: la longitud natural debe ser mayor que cero.\n";
    } while (l0 <= 0.0);

    do {
        cout << "Gravedad (g) [m/s^2] (ej. 9.81): "; cin >> g;
        if (g <= 0.0) cout << "Error: la gravedad debe ser mayor que cero.\n";
    } while (g <= 0.0);

    cout << "\n--- Condiciones Iniciales ---\n";
    do {
        cout << "Elongacion inicial (z0) [m]: "; cin >> z0;
        if (l0 + z0 <= 0.0) cout << "Error: la distancia radial total l0 + z0 debe ser mayor que cero.\n";
    } while (l0 + z0 <= 0.0);

    cout << "Velocidad radial inicial (z_dot0) [m/s]: "; cin >> vz0;
    cout << "Angulo inicial (theta0) [grados]: "; cin >> theta0_deg;
    cout << "Velocidad angular inicial (theta_dot0) [rad/s]: "; cin >> omega0;

    cout << "\n--- Parametros de Simulacion ---\n";
    do {
        cout << "Tiempo final (tf): "; cin >> tf;
        if (tf < 0.0) cout << "Error: el tiempo final no puede ser negativo.\n";
    } while (tf < 0.0);

    do {
        cout << "Variacion del tiempo (dt): "; cin >> dt;
        if (dt <= 0.0) {
            cout << "Error: el paso temporal debe ser mayor que cero.\n";
        } else if (tf > 0.0 && dt > tf) {
            cout << "Error: el paso dt no puede ser mayor que tf.\n";
        }
    } while (dt <= 0.0 || (tf > 0.0 && dt > tf));

    double theta0_rad = theta0_deg * PI / 180.0;
    vector<double> u = {z0, vz0, theta0_rad, omega0};
    
    ofstream archivo("datos_pendulo.dat");
    
    if (archivo.is_open()) {
        archivo.precision(6);
        archivo << fixed;
        
        t = 0.0;
        
        // --- Bucle principal de integración numérica temporal ---
        while (t <= tf) {
            double r = l0 + u[0];
            
            // Transformación cinematica de coordenadas polares a cartesianas (2D)
            double x = r * sin(u[2]);
            double y = -r * cos(u[2]);

            // Cálculo del balance energético del sistema para control de estabilidad
            double T_kin = 0.5 * m * (u[1] * u[1] + r * r * u[3] * u[3]);
            double V_pot = 0.5 * k * u[0] * u[0] - m * g * r * cos(u[2]);
            double E_total = T_kin + V_pot;

            // Escritura de las variables físicas calculadas en el archivo de salida
            archivo << setw(10) << t 
                    << setw(15) << x 
                    << setw(15) << y 
                    << setw(15) << u[0] 
                    << setw(15) << u[1] 
                    << setw(15) << u[2] 
                    << setw(15) << u[3] 
                    << setw(15) << E_total << endl;

            // Integración temporal: El vector de estado se actualiza por valor retornado
            u = calcularDerivadas(t, u, m, k, l0, g, dt);

            t += dt;
        }
        
        archivo.close();
        cout << "Datos generados exitosamente en el archivo: datos_pendulo.dat\n";
    } else {
        cerr << "Error: No se pudo abrir el archivo para escritura.\n";
    }
}
