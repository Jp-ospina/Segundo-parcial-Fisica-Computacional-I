import matplotlib.pyplot as plt
import math
import os

output_dir = os.path.join('..', 'results', 'graficas', 'Python')
os.makedirs(output_dir, exist_ok=True)

# =====================================================================
# PUNTO 1: Lectura manual de datos por columnas usando el estilo solicitado
# =====================================================================

# Listas para almacenar los datos de la Condición 1
t1, x1, y1 = [], [], []
with open('datos_condicion1.dat', 'r') as f:
    for line in f:
        if line.startswith('#') or not line.strip(): 
            continue  # Ignora encabezados o líneas vacías
        parts = line.strip().split()
        t1.append(float(parts[0]))
        x1.append(float(parts[1]))
        y1.append(float(parts[2]))

# Listas para almacenar los datos de la Condición 2
t2, x2, y2 = [], [], []
with open('datos_condicion2.dat', 'r') as f:
    for line in f:
        if line.startswith('#') or not line.strip(): 
            continue
        parts = line.strip().split()
        t2.append(float(parts[0]))
        x2.append(float(parts[1]))
        y2.append(float(parts[2]))

# Listas para almacenar los datos de la Condición 3
t3, x3, y3 = [], [], []
with open('datos_condicion3.dat', 'r') as f:
    for line in f:
        if line.startswith('#') or not line.strip(): 
            continue
        parts = line.strip().split()
        t3.append(float(parts[0]))
        x3.append(float(parts[1]))
        y3.append(float(parts[2]))


# =====================================================================
# PUNTO 2: Gráfica de Evolución Temporal (t vs Poblaciones) - Condición 1
# =====================================================================
plt.figure(figsize=(5, 5))
plt.plot(t1, x1, linestyle='-', color='blue', label='Presas (x)')
plt.plot(t1, y1, linestyle='-', color='red', label='Depredadores (y)')
plt.grid(True)
plt.title('Grafica t vs Poblaciones (Condicion 1)')
plt.xlabel('t')
plt.ylabel('Poblacion')
plt.legend()
plt.savefig(os.path.join(output_dir, 't_vs_poblaciones_condicion1.png'))
plt.show()


# =====================================================================
# PUNTO 3: Gráfica de Evolución Temporal (t vs Poblaciones) - Condición 2
# =====================================================================
plt.figure(figsize=(5, 5))
plt.plot(t2, x2, linestyle='-', color='blue', label='Presas (x)')
plt.plot(t2, y2, linestyle='-', color='red', label='Depredadores (y)')
plt.grid(True)
plt.title('Grafica t vs Poblaciones (Condicion 2)')
plt.xlabel('t')
plt.ylabel('Poblacion')
plt.legend()
plt.savefig(os.path.join(output_dir, 't_vs_poblaciones_condicion2.png'))
plt.show()


# =====================================================================
# PUNTO 4: Gráfica de Evolución Temporal (t vs Poblaciones) - Condición 3
# =====================================================================
plt.figure(figsize=(5, 5))
plt.plot(t3, x3, linestyle='-', color='blue', label='Presas (x)')
plt.plot(t3, y3, linestyle='-', color='red', label='Depredadores (y)')
plt.grid(True)
plt.title('Grafica t vs Poblaciones (Condicion 3)')
plt.xlabel('t')
plt.ylabel('Poblacion')
plt.legend()
plt.savefig(os.path.join(output_dir, 't_vs_poblaciones_condicion3.png'))
plt.show()


# =====================================================================
# PUNTO 5: Retrato de Fases Combinado (x vs y) para ver las órbitas
# =====================================================================
plt.figure(figsize=(5, 5))
plt.plot(x1, y1, linestyle='-', color='purple', label='Condicion 1')
plt.plot(x2, y2, linestyle='-', color='orange', label='Condicion 2')
plt.plot(x3, y3, linestyle='-', color='green', label='Condicion 3')
plt.grid(True)
plt.title('Espacio de Fases (x vs y)')
plt.xlabel('Presas (x)')
plt.ylabel('Depredadores (y)')
plt.legend()
plt.savefig(os.path.join(output_dir, 'espacio_de_fases.png'))
plt.show()