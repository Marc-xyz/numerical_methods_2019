*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+[     README.txt     ]+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*

>#CONTENIDO DE LA SUBCARPETA:
nodos_chev_02.dat  nodos_equi_02.dat  plot_01  pr1_ab_d.c  pr3_abc_d.c
nodos_equi_01.dat  out.txt            plot_02  pr2_ab_d.c  README.txt

>#NOMENCLATURA DE LOS ARCHIVOS:
pr#_##_fd.c

# Indica numero del ejercicio
## Indica apartado del ejercicio
pr abreviatura de problema 
fd indica que el programa incluye precisión float o double.
d  indica que el programa incluye precisión unicamente double.
Ejemplo: pr2_a_d.c 
(hace referencia al Ejercicio número "2" apartado "a" con precisión double.)

   
>#INSTRUCCIONES DE USO:
1.Abrir terminal en el subdirectorio de la carpeta.

2.Compilar con  nivel de optimización 3 
   gcc -g -Wall -O3 -o nombre_de_archivo nombre_de_archivo.c -lm
   (hay un comentario con esto escrito al inicio de cada
   documento .c) . 
3.Ejecutar en terminal.
   ./nombre_de_archivo

>#COMENTARIOS:
1. El documento out.txt es unicamente un registro de los resultados imprimidos por pantalla al compilar los programas (algunos con valores concretos)

2.Las carpetas plot_02 y plot_01 :
contiene las lineas de código (archivos .gp) para generar los gráficos adjuntados en la memoria así como una copia en PDF ya impresa para los problemas 1 y 2.

3.Los archivos .dat se generan en ejecutar los dos primeros programas aunque ya existan. Estos han sido utilizados para generar los gráficos .
