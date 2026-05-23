import matplotlib.pyplot as plt
import numpy as np

# t    x    y    z    z_dot    theta    theta_dot    Energia

t = []
x = []
y = []
z_coords = [] # Renamed z to z_coords to avoid conflict and correctly store all z values
z_dot = []
theta = []
theta_dot = []
energy = []

with open('..\results\datos_pendulo.dat', 'r') as f:
  for line in f:
    parts = line.strip().split() # Split by whitespace

    t.append(float(parts[0]))
    x.append(float(parts[1]))
    y.append(float(parts[2]))
    z_coords.append(float(parts[3]))
    z_dot.append(float(parts[4]))
    theta.append(float(parts[5]))
    theta_dot.append(float(parts[6]))
    energy.append(float(parts[7]))


plt.figure(figsize=(5, 5))

# plt.plot(t, x, linestyle='-')
# plt.plot(t, y, linestyle='-')
# plt.plot(x, y, linestyle='-')
# plt.plot(t, z_coords, linestyle='-')
# plt.plot(t, z_dot, linestyle='-')
# plt.plot(t, theta, linestyle='-')
# plt.plot(t, theta_dot, linestyle='-')
# plt.plot(z_coords, z_dot, linestyle='-')
# plt.plot(theta, theta_dot, linestyle='-')
# plt.plot(t, energy, linestyle='-')

plt.grid(True)
plt.title('Grafica t vs energy')
plt.xlabel('t')
plt.ylabel('energy')
plt.show()