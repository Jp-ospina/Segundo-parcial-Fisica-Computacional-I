#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void penduloResorte();

vector<double> calcularDerivadas(double t, const vector<double> &u, double m, double k, double l0, double g, double dt);

int main(){
    penduloResorte();
    return 0;
}

// Esta función ahora implementa el algoritmo RK4 completo para avanzar el vector de estado
vector<double> calcularDerivadas(double t, const vector<double> &u, double m, double k, double l0, double g, double dt) {
    
    // Vectores para almacenar las 4 pendientes del método Runge-Kutta (RK4)
    vector<double> k1(4), k2(4), k3(4), k4(4);
    // Vector auxiliar para evaluar las funciones en puntos intermedios
    vector<double> u_aux(4);

    // ------------------------------------------------------------------------
    // PASO 1: Calcular k1 (Pendientes en el punto inicial del intervalo)
    // ------------------------------------------------------------------------
    // u[0]=z, u[1]=z_dot, u[2]=theta, u[3]=theta_dot
    k1[0] = u[1]; 
    k1[1] = (l0 + u[0]) * u[3] * u[3] - (k / m) * u[0] + g * cos(u[2]); 
    k1[2] = u[3]; 
    k1[3] = -(2.0 * u[1] * u[3]) / (l0 + u[0]) - (g / (l0 + u[0])) * sin(u[2]); 

    // ------------------------------------------------------------------------
    // PASO 2: Calcular k2 (Pendientes en la mitad del intervalo usando k1)
    // ------------------------------------------------------------------------
    for(int i = 0; i < 4; i++) {
        u_aux[i] = u[i] + 0.5 * dt * k1[i]; // Avance de prueba en base a k1
    }
    k2[0] = u_aux[1]; 
    k2[1] = (l0 + u_aux[0]) * u_aux[3] * u_aux[3] - (k / m) * u_aux[0] + g * cos(u_aux[2]); 
    k2[2] = u_aux[3]; 
    k2[3] = -(2.0 * u_aux[1] * u_aux[3]) / (l0 + u_aux[0]) - (g / (l0 + u_aux[0])) * sin(u_aux[2]); 

    // ------------------------------------------------------------------------
    // PASO 3: Calcular k3 (Pendientes en la mitad del intervalo usando k2)
    // ------------------------------------------------------------------------
    for(int i = 0; i < 4; i++) {
        u_aux[i] = u[i] + 0.5 * dt * k2[i]; // Avance de prueba en base a k2
    }
    k3[0] = u_aux[1]; 
    k3[1] = (l0 + u_aux[0]) * u_aux[3] * u_aux[3] - (k / m) * u_aux[0] + g * cos(u_aux[2]); 
    k3[2] = u_aux[3]; 
    k3[3] = -(2.0 * u_aux[1] * u_aux[3]) / (l0 + u_aux[0]) - (g / (l0 + u_aux[0])) * sin(u_aux[2]); 

    // ------------------------------------------------------------------------
    // PASO 4: Calcular k4 (Pendientes al final del intervalo usando k3)
    // ------------------------------------------------------------------------
    for(int i = 0; i < 4; i++) {
        u_aux[i] = u[i] + dt * k3[i]; // Avance de prueba completo en base a k3
    }
    k4[0] = u_aux[1]; 
    k4[1] = (l0 + u_aux[0]) * u_aux[3] * u_aux[3] - (k / m) * u_aux[0] + g * cos(u_aux[2]); 
    k4[2] = u_aux[3]; 
    k4[3] = -(2.0 * u_aux[1] * u_aux[3]) / (l0 + u_aux[0]) - (g / (l0 + u_aux[0])) * sin(u_aux[2]); 

    // ------------------------------------------------------------------------
    // COMBINACIÓN FINAL: Promedio ponderado para obtener el estado siguiente
    // ------------------------------------------------------------------------
    vector<double> u_siguiente(4);
    for(int i = 0; i < 4; i++) {
        u_siguiente[i] = u[i] + (dt / 6.0) * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]);
    }

    return u_siguiente; // Retorna el nuevo vector de estado ya resuelto
}

void penduloResorte() {
    double m, k, l0, g = 9.81;
    double z0, vz0, theta0_deg, omega0;
    double t, tf, dt;
    const double PI = 3.14159265358979323846;

    cout << "--- Parametros Fisicos del Pendulo-Resorte ---\n";
    cout << "Masa (m) [kg]: "; cin >> m;
    cout << "Constante elastica (k) [N/m]: "; cin >> k;
    cout << "Longitud natural (l0) [m]: "; cin >> l0;
    cout << "Gravedad (g) [m/s^2] (ej. 9.81): "; cin >> g;
    cout << "\n";

    cout << "--- Condiciones Iniciales ---\n";
    cout << "Elongacion inicial (z0) [m]: "; cin >> z0;
    cout << "Velocidad radial inicial (z_dot0) [m/s]: "; cin >> vz0;
    cout << "Angulo inicial (theta0) [grados]: "; cin >> theta0_deg;
    cout << "Velocidad angular inicial (theta_dot0) [rad/s]: "; cin >> omega0;
    cout << "\n";

    cout << "--- Parametros de Simulacion ---\n";
    cout << "Tiempo final (tf): "; cin >> tf;
    cout << "Variacion del tiempo (dt): "; cin >> dt;
    cout << "\n";

    double theta0_rad = theta0_deg * PI / 180.0;

    vector<double> u = {z0, vz0, theta0_rad, omega0};
    
    ofstream archivo("datos_pendulo.dat");
    
    if (archivo.is_open()) {
        archivo.precision(6);
        archivo << fixed;
        
        archivo << "# t    x    y    z    z_dot    theta    theta_dot    Energia\n";
        
        t = 0.0;
        
        while (t <= tf) {
            double r = l0 + u[0];
            
            double x = r * sin(u[2]);
            double y = -r * cos(u[2]);

            double T_kin = 0.5 * m * (u[1] * u[1] + r * r * u[3] * u[3]);
            double V_pot = 0.5 * k * u[0] * u[0] - m * g * r * cos(u[2]);
            double E_total = T_kin + V_pot;

            archivo << setw(10) << t 
                    << setw(15) << x 
                    << setw(15) << y 
                    << setw(15) << u[0] 
                    << setw(15) << u[1] 
                    << setw(15) << u[2] 
                    << setw(15) << u[3] 
                    << setw(15) << E_total << endl;

            // Se llama a la función pasándole dt; el vector 'u' se actualiza directamente
            u = calcularDerivadas(t, u, m, k, l0, g, dt);

            t += dt;
        }
        
        archivo.close();
        cout << "Datos generados exitosamente en el archivo: datos_pendulo.dat\n";
    } else {
        cerr << "Error: No se pudo abrir el archivo para escritura.\n";
    }
}
