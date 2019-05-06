#Abrir con editor de texto ,
#seleccionar código gráfico,
#ejecutar en terminal gnuplot
#pegar código,
#enter,


# Código para generar gráfico 01 del Problema 1
set key left bottom center title 'P_f(x_k)' box 3
set key outside
set timefmt
set xlabel "Eje x"
set ylabel "Eje y"
set yrange[-3:3]
set xrange [-1:1]
plot "nodos4.txt" using 2:4 w l lw 2 
replot "nodos8.txt" using 2:4 w l lw 2 
replot "nodos16.txt" using 2:4 w l lw 2 
replot "nodos32.txt" using 2:4 w l lw 2 
replot "funcion_1.txt" using 2:1 w l lw 2 lt rgb "#000000" 

# Código para generar gráfico 02 del Problema 1
set key left bottom center title '|P_f(x_k)-f(x_k)|' box 3
set key outside
set timefmt
set xlabel "Eje x"
set ylabel "Eje y"
set yrange[-1:6]
set xrange [-1:1]
plot "nodos4.txt" using 2:5 w l lw 2 
replot "nodos8.txt" using 2:5 w l lw 2 
replot "nodos16.txt" using 2:5 w l lw 2 
replot "nodos32.txt" using 2:5 w l lw 2 
