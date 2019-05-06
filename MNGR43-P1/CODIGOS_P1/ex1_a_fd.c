/*
  Compilar con  nivel de optimización 3 
  gcc -g -Wall -O3 -o ex1_a_fd ex1_a_fd.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o ex1_a_fd ex1_a_fd.c -lm
*/
 
// Librerías 
#include<stdio.h>
#include<math.h>

//Declaramos funciones de interaz de texto
void cabecera(void);
void error(void);
void preg(void);

//Función principal 
int main (void)
{
    //Declaramos variables
    unsigned int  tip;
    float  x,y;
    double z,t;
    
    cabecera();
    printf("\n ¿Con que precision desea que funcione el programa? \n Escriba 1, para precision float. \n Escriba 2, para precision double. \n");
    if(!scanf(" %u",&tip))
    {  error(); return -1;}
    // case 1 : 
    if(tip==1)
    {
      printf( "\n Ha seleccionado precision float ( con 32 bits)" );
      preg();
      if(!scanf("%f",&x)||x==0)
      {error(); return -1;}
      y=(1-cosf(x))/(x*x);
      printf( "\n El resultado obtenido de f(%.7f) es: \n %.7f \n",x,y);
    }
    // case 2:
    else if(tip==2)
    {
      printf( "\n Ha seleccionado precision double ( con 64 bits)" );
      preg();
      if(!scanf("%lf",&z)||z==0)
      {error(); return -1;}
      t=(1-cos(z))/(z*z);
      printf( "\n El resultado obtenido de f(%G) es: \n %.14lf \n",z,t);
   }
   else
   {
       error();
   }
    return 0;
}

//Definimos funciones de interaz de texto

// Función cabezera
/* Esta función se puede ignorar solo produce la cabecera del programa, pero es agradable. */
void cabecera(void)
{
    int i, j, n=70, m=18;
    for(j=0;j<=4;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Ejercicio_1_|a|_");
                 i=(n+m-4)/4;
             }
             else
             {
                printf(".:");
             }
         }
         printf(".\n");
       }
       else
       {
         for(i=0;i<=n/2;i++)
         {
             printf(".:");
         }
         printf(".\n");
       }
    }
return ; //Por puro formalismo
}

// Función error
void error(void)
{
   printf( "\n ERROR: Vaya alguna cosa ha salido mal. \n Prueve de introducir de nuevo los valor porfavor.\n" );
   return ;
}

// Función preguntar
void preg(void)
{
    printf("\n ¿Que valor  x_0 quiere que tome la variable x para evaluar en la funcion f ? \n Ejemplo: 1.2e-5 \n");
    return ;
}
