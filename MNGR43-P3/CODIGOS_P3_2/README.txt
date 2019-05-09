*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+[     README.txt     ]+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*
*+*+*+*+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+**+*+*+*+*+*+*

>#CONTENIDO DE LA SUBCARPETA:
out.txt  pr4_d.c  pr5_d.c  
pr6_d.c  pr7_d.c  README.txt

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
