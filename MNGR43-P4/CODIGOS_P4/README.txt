*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+[     README.txt     ]+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*

>#CONTENIDO DE LA SUBCARPETA:
int_01_C.c  int_01_T.c  int_02_L.c  int_03_L.c
int_01_L.c  int_02_C.c  int_02_T.c  README.txt
out.md
>#NOMENCLATURA DE LOS ARCHIVOS:
int_##_#.c

## Indica a que integral hace referencia: 
Integral 01:

     / 1
     |    -x*x
     |  e       dx
     |
     / -1
Integral 02:

     / 1
     |     e^(-x^2)
     | ------------- dx
     |  (1-x^2)^(1/3)
     / 0
Integral 03:
             ______________
     / 1     |            |
     |       |  64-15x^2
     |       |  ---------    dx
     |      \|  64-16x^2
     / -1

# Indica el método utilizado para hacer el cálculo.
L----> Cuadratura Gauss-Legendre.
C----> Cuadratura Gauss-Chebyshev.
T----> Trapecios compuestos
Ejemplo: int_01_C.c 
(hace referencia a la integral número "01" con método "C" Cuadratura Gauss-Chebyshev.)

>#INSTRUCCIONES DE USO:
1.Abrir terminal en el subdirectorio de la carpeta.
2.Compilar con  nivel de optimización 3 
   gcc -g -Wall -O3 -o nombre_de_archivo nombre_de_archivo.c -lm
   (hay un comentario con esto escrito al inicio de cada
   documento .c) . 
3.Ejecutar en terminal.
   ./nombre_de_archivo

>#COMENTARIOS:
1. El documento out.md es unicamente un registro de los resultados imprimidos por pantalla al compilar los programas (algunos con valores concretos)

