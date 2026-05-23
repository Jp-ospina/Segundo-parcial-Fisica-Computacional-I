set terminal pngcairo size 1200,900 enhanced font "Arial,10"
set output "../results/graficas/Gnuplot/fenomenologia.png"

set datafile separator whitespace
set key left top
set grid

set multiplot layout 2,2 rowsfirst title "Fenomenologia - Lotka-Volterra"

set title "t vs Poblaciones (Condicion 1)"
set xlabel "t"
set ylabel "Poblacion"
plot "datos_condicion1.dat" using 1:2 with lines lw 2 title "Presas (x)", \
     "datos_condicion1.dat" using 1:3 with lines lw 2 title "Depredadores (y)"

set title "t vs Poblaciones (Condicion 2)"
set xlabel "t"
set ylabel "Poblacion"
plot "datos_condicion2.dat" using 1:2 with lines lw 2 title "Presas (x)", \
     "datos_condicion2.dat" using 1:3 with lines lw 2 title "Depredadores (y)"

set title "t vs Poblaciones (Condicion 3)"
set xlabel "t"
set ylabel "Poblacion"
plot "datos_condicion3.dat" using 1:2 with lines lw 2 title "Presas (x)", \
     "datos_condicion3.dat" using 1:3 with lines lw 2 title "Depredadores (y)"

set title "Espacio de Fases (x vs y)"
set xlabel "Presas (x)"
set ylabel "Depredadores (y)"
plot "datos_condicion1.dat" using 2:3 with lines lw 2 title "Condicion 1", \
     "datos_condicion2.dat" using 2:3 with lines lw 2 title "Condicion 2", \
     "datos_condicion3.dat" using 2:3 with lines lw 2 title "Condicion 3"

unset multiplot
```// filepath: c:\Users\juanp\Downloads\Programación\Trabajos\Física Computacional\Parcial2_FisicaComputacional1\punto2_fenomenologia\scripts\graficar_gnuplot.gp
set terminal pngcairo size 1200,900 enhanced font "Arial,10"
set output "../results/graficas/Gnuplot/fenomenologia.png"

set datafile separator whitespace
set key left top
set grid

set multiplot layout 2,2 rowsfirst title "Fenomenologia - Lotka-Volterra"

set title "t vs Poblaciones (Condicion 1)"
set xlabel "t"
set ylabel "Poblacion"
plot "datos_condicion1.dat" using 1:2 with lines lw 2 title "Presas (x)", \
     "datos_condicion1.dat" using 1:3 with lines lw 2 title "Depredadores (y)"

set title "t vs Poblaciones (Condicion 2)"
set xlabel "t"
set ylabel "Poblacion"
plot "datos_condicion2.dat" using 1:2 with lines lw 2 title "Presas (x)", \
     "datos_condicion2.dat" using 1:3 with lines lw 2 title "Depredadores (y)"

set title "t vs Poblaciones (Condicion 3)"
set xlabel "t"
set ylabel "Poblacion"
plot "datos_condicion3.dat" using 1:2 with lines lw 2 title "Presas (x)", \
     "datos_condicion3.dat" using 1:3 with lines lw 2 title "Depredadores (y)"

set title "Espacio de Fases (x vs y)"
set xlabel "Presas (x)"
set ylabel "Depredadores (y)"
plot "datos_condicion1.dat" using 2:3 with lines lw 2 title "Condicion 1", \
     "datos_condicion2.dat" using 2:3 with lines lw 2 title "Condicion 2", \
     "datos_condicion3.dat" using 2:3 with lines lw 2 title "Condicion 3"

unset multiplot