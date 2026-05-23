/**
 * @file mainSinModularizar.cpp
 * @brief Simulación numérica de un sistema físico de péndulo-resorte en 2D.
 * @author Tomás A. Peñuela Z. y Juan P. Ospina G.
 * @date 25 de Mayo de 2026
 * * @details Este programa resuelve el comportamiento dinámico de una masa acoplada 
 * a un resorte que a su vez oscila como un péndulo. Para la integración temporal 
 * de las ecuaciones diferenciales ordinarias (EDO) de segundo orden acopladas, 
 * se utiliza el método numérico de Runge-Kutta de cuarto orden (RK4). 
 * Los resultados de la trayectoria y la energía se exportan a un archivo de texto.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * @brief Controla el flujo principal, solicita parámetros y ejecuta la simulación.
 * @details Esta función interactúa con el usuario para capturar las constantes 
 * físicas, las condiciones iniciales y las propiedades del tiempo de simulación. 
 * Posteriormente, inicializa el bucle temporal, calcula las coordenadas cartesianas, 
 * evalúa la conservación de la energía mecánica total y escribe los datos obtenidos 
 * en un archivo formateado de salida.
 */
void penduloResorte();

/**
 * @brief Aplica el método numérico de Runge-Kutta de 4to orden (RK4) para avanzar el estado.
 * * @details La función descompone y calcula las pendientes intermedias (k1, k2, k3, k4) 
 * basándose en las ecuaciones de movimiento del sistema mecánico. Modela tanto la 
 * aceleración lineal de la elongación del resorte como la aceleración angular del péndulo.
 * * @param t Tiempo actual de la simulación (s).
 * @param u Vector de estado actual con 4 componentes:
 * - `u[0]`: Elongación del resorte \f$z\f$ (m).
 * - `u[1]`: Velocidad de elongación \f$\dot{z}\f$ (m/s).
 * - `u[2]`: Posición angular \f$\theta\f$ (rad).
 * - `u[3]`: Velocidad angular \f$\dot{\theta}\f$ (rad/s).
 * @param m Masa del cuerpo oscilante (kg).
 * @param k Constante elástica del resorte (N/m).
 * @param l0 Longitud natural del resorte en reposo (m).
 * @param g Aceleración de la gravedad (m/s^2).
 * @param dt Tamaño del paso de integración temporal \f$\Delta t\f$ (s).
 * * @return std::vector<double> Vector con el estado del sistema en el siguiente instante \f$t + \Delta t\f$.
 */
vector<double> calcularDerivadas(double t, const vector<double> &u, double m, double k, double l0, double g, double dt);

/**
 * @brief Punto de entrada principal del programa.
 * @return int Estado de finalización de la ejecución (0 si es exitoso).
 */
int main(){
    penduloResorte();
    return 0;
}

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
    // PASO FINAL: Promedio ponderado para obtener el estado siguiente
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
