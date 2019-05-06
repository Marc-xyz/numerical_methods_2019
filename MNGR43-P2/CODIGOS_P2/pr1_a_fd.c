/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr1_a_fd pr1_a_fd.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr1_a_fd pr1_a_fd.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//Funciones que evalúan el polinomio en precisión simple y doble.
float polif( float x);
double polid(double x);

//Funciones que calculan alfa  (de formulas de Cardano) en precisión simple y doble.
void avalf(float *x);
void avald(double *x);

//Función cabecera
void cabecera(void);

//Función principal
int main(void)
{
    cabecera();
    float x;
    double z;
    avalf(&x);
    avald(&z);
    printf("\n Los valores para el polinomio evaluando  para alfa son, es decir, \n |x^3-x-40|=");
    printf("\n Para precision float: %.7F",fabsf(polif(x)));
    printf("\n Para precision double: %.14G\n",fabs(polid(z)));
    return 0;
}

//Funciones que evalúan el polinomio
float polif(float x)
{
     return x*x*x-x-40;
}
double polid(double x)
{
     return x*x*x-x-40;
}

//Funciones que calculan alfa
void avalf(float *x)
{
    (*x)= (float) powf(20+sqrtf(32397)/9.0,1/3.0)+powf(20-sqrtf(32397)/9.0,1/3.0);
    return ;
}

void avald(double *x)
{
    (*x)= (double) pow(20+sqrt(32397)/9.0,1/3.0)+pow(20-sqrt(32397)/9.0,1/3.0);
    return ;
}
// Función cabezera
/* Esta función se puede ignorar solo produce la cabecera del programa, pero es agradable. */
void cabecera(void)
{
    int i, j, n=70, m=18;
    for(j=1;j<=3;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Problema_1_[a]__");
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
