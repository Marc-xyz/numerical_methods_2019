 /*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o ex3_c_fd ex3_c_fd.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o ex3_c_fd ex3_c_fd.c -lm
*/
 
// Librerías 
#include<stdio.h>
#include<math.h>

//Declaramos funciones de interaz de texto

//Función principal 
int main (void)
{
    FILE *output, *outputt;
    unsigned int i,z=10000000;
    output=fopen("vector_2.txt","w");
    for(i=1;i<=100;i=i+1)
    {
    if(i<=50)
    {
        z=z+100;
    }
    fprintf(output,"%u\n",z);
    z=10000000;
    }
    fclose(output);
    outputt=fopen("vector_3.txt","w");
    z=1000000000;
    for(i=1;i<=1000;i=i+1)
    {
    if(i<=500)
    {
        z=z+100;
    }
    fprintf(output,"%u\n",z);
    z=1000000000;
    }
    fclose(outputt);
    return 0;
}

    
