set terminal pngcairo size 1200,900 enhanced font "Arial,10"
set output "../results/graficas/Gnuplot/datos_pendulo.png"

set datafile separator whitespace
set key left top
set grid

set multiplot layout 4,3 rowsfirst title "Gráficas de datos_pendulo.dat"

# t vs x
set title "t vs x"
set xlabel "t"
set ylabel "x"
plot "../results/datos_pendulo.dat" using 1:2 with lines lw 2 title "x(t)"

# t vs y
set title "t vs y"
set xlabel "t"
set ylabel "y"
plot "../results/datos_pendulo.dat" using 1:3 with lines lw 2 title "y(t)"

# x vs y
set title "x vs y"
set xlabel "x"
set ylabel "y"
plot "../results/datos_pendulo.dat" using 2:3 with lines lw 2 title "y(x)"

# t vs z
set title "t vs z"
set xlabel "t"
set ylabel "z"
plot "../results/datos_pendulo.dat" using 1:4 with lines lw 2 title "z(t)"

# t vs z_dot
set title "t vs z_dot"
set xlabel "t"
set ylabel "z_dot"
plot "../results/datos_pendulo.dat" using 1:5 with lines lw 2 title "z_dot(t)"

# t vs theta
set title "t vs theta"
set xlabel "t"
set ylabel "theta"
plot "../results/datos_pendulo.dat" using 1:6 with lines lw 2 title "theta(t)"

# t vs theta_dot
set title "t vs theta_dot"
set xlabel "t"
set ylabel "theta_dot"
plot "../results/datos_pendulo.dat" using 1:7 with lines lw 2 title "theta_dot(t)"

# z vs z_dot
set title "z vs z_dot"
set xlabel "z"
set ylabel "z_dot"
plot "../results/datos_pendulo.dat" using 4:5 with lines lw 2 title "z_dot(z)"

# theta vs theta_dot
set title "theta vs theta_dot"
set xlabel "theta"
set ylabel "theta_dot"
plot "../results/datos_pendulo.dat" using 6:7 with lines lw 2 title "theta_dot(theta)"

# t vs energy
set title "t vs energy"
set xlabel "t"
set ylabel "energy"
plot "../results/datos_pendulo.dat" using 1:8 with lines lw 2 title "energy(t)"

unset multiplot
```// filepath: c:\Users\juanp\Downloads\Programación\Trabajos\Física Computacional\Parcial2_FisicaComputacional1\punto1_pendulo_elastico\scripts\graficar_gnuplot.gp
set terminal pngcairo size 1200,900 enhanced font "Arial,10"
set output "../results/graficas/Gnuplot/datos_pendulo.png"

set datafile separator whitespace
set key left top
set grid

set multiplot layout 4,3 rowsfirst title "Gráficas de datos_pendulo.dat"

# t vs x
set title "t vs x"
set xlabel "t"
set ylabel "x"
plot "../results/datos_pendulo.dat" using 1:2 with lines lw 2 title "x(t)"

# t vs y
set title "t vs y"
set xlabel "t"
set ylabel "y"
plot "../results/datos_pendulo.dat" using 1:3 with lines lw 2 title "y(t)"

# x vs y
set title "x vs y"
set xlabel "x"
set ylabel "y"
plot "../results/datos_pendulo.dat" using 2:3 with lines lw 2 title "y(x)"

# t vs z
set title "t vs z"
set xlabel "t"
set ylabel "z"
plot "../results/datos_pendulo.dat" using 1:4 with lines lw 2 title "z(t)"

# t vs z_dot
set title "t vs z_dot"
set xlabel "t"
set ylabel "z_dot"
plot "../results/datos_pendulo.dat" using 1:5 with lines lw 2 title "z_dot(t)"

# t vs theta
set title "t vs theta"
set xlabel "t"
set ylabel "theta"
plot "../results/datos_pendulo.dat" using 1:6 with lines lw 2 title "theta(t)"

# t vs theta_dot
set title "t vs theta_dot"
set xlabel "t"
set ylabel "theta_dot"
plot "../results/datos_pendulo.dat" using 1:7 with lines lw 2 title "theta_dot(t)"

# z vs z_dot
set title "z vs z_dot"
set xlabel "z"
set ylabel "z_dot"
plot "../results/datos_pendulo.dat" using 4:5 with lines lw 2 title "z_dot(z)"

# theta vs theta_dot
set title "theta vs theta_dot"
set xlabel "theta"
set ylabel "theta_dot"
plot "../results/datos_pendulo.dat" using 6:7 with lines lw 2 title "theta_dot(theta)"

# t vs energy
set title "t vs energy"
set xlabel "t"
set ylabel "energy"
plot "../results/datos_pendulo.dat" using 1:8 with lines lw 2 title "energy(t)"

unset multiplot