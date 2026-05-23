# Solución de parcial de física computacional

Este proyecto resuelte dos ejercicios planteados para el segundo parcial de la materia:

1. **Sistema péndulo elástico**  
2. **Sistema depredador-presa**

Los datos resultantes se exportan a archivos de texto para su posterior visualización en formato visual como gráficas mediante Gnuplot o Python.

## Archivos generados

| Simulación      | Archivo de salida          | Contenido                                                    |
|-----------------|----------------------------|--------------------------------------------------------------|
| Péndulo         | `datos_pendulo.dat`        | `t    x    y    z    z_dot    theta    theta_dot    Energia` |
| DepredadorPresa | `datos_condicion.dat`      |                          `t x y`                             |


## Marco Teórico usado
### Péndulo elástico

Se utilizó el Lagrangiano del sistema y la ecuación de Euler-Lagrange para un sistema de dos grados de libertad y posteriormente hacer la aproximación de las ecuaciones diferenciales no lineales resultantes por el método de Runge-Kutta de cuarto orden.

### Depredador - Presa

Se utilizaron las ecuaciones diferenciales para modelar la interacción biológica de un sistema acoplado depredador-presa, resolviendo numéricamente las ecuaciones no lineales resultantes mediante el método de Runge-Kutta de cuarto orden (RK4) para tres condiciones iniciales distintas.