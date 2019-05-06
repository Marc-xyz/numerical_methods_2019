/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr1_b_fd pr1_b_fd.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr1_b_fd pr1_b_fd.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//Definimos una constante que limita el número máximo de iteraciones.
#define Max 100

//Función cabecera
void cabecera(void);

//Funciones que evalúan el polinomio en precisión simple y doble.
float polif_n( float x);
double polid_n(double x);

//Funciones que evalúan la derivada del polinomio en precisión simple y doble.
double polid_d(double x);
float polif_d( float x);

//Funciones que implementan el método de Newton en precisión simple y doble.
float metNewf(float x);
double metNewd(double x);

//Función principal
int main(void)
{
    float x_i=2.0, x_f;
    double z_i=2.0,z_f;
    unsigned int i=0,ip=0;
    unsigned int j=0, jp=0;
    cabecera();
    while(i<Max)
    {
        i=i+1;
        x_f=metNewf(x_i);
        printf("\n Iteracion [#%u] (float) ------------> %.8F", i,x_f);
        if(fabsf(x_f-x_i)<1.e-8)
        {
            ip=i;
            break;
        }
        x_i=x_f;
    }
    printf("\n");
    while(j<Max)
    {
        j=j+1;
        z_f=metNewd(z_i);
        printf("\n Iteracion [#%u] (double) ------------> %.16G", j,z_f);
        if(fabs(z_f-z_i)<1.e-9)
        {
            jp=j;
            break;
        }
        z_i=z_f;
    }
    printf("\n");
    printf("\n>Los valores para la raiz con 8 decimales correctos son:");
    printf("\n *Para precision float, logrado en %u iteraciones: %.8F",ip,x_f);
    printf("\n *Para precision double, logrado en %u iteraciones:%.9G\n",jp,z_f);
    while(j<Max)
    {
        j=j+1;
        z_f=metNewd(z_i);
        printf("\n Iteracion [#%u] (double) ------------> %.16G", j,z_f);
        if(fabs(z_f-z_i)<1.e-16)
        {
            jp=j;
            break;
        }
        z_i=z_f;
    }
    printf("\n");
    printf("\n>Los valores para la raiz con 15 decimales correctos son:");
    printf("\n *Para precision double, logrado en %u iteraciones: %.16G",jp,z_f);
    printf("\n *Para precision float no consideramos ningun resultado \n   (no esperamos mas de 8 decimales correctos).\n");
    return 0;
}

//Método Newton en precisión simple y doble.
float metNewf(float x)
{
    return x-(polif_n(x))/(polif_d(x));
}

double metNewd(double x)
{
    return x-(polid_n(x))/(polid_d(x));
}

//Función normal
float polif_n(float x)
{
     return x*x*x-x-40;
}
double polid_n(double x)
{
     return x*x*x-x-40;
}

//Función derivada 
float polif_d(float x)
{
     return 3.0*x*x-1;
}
double polid_d(double x)
{
     return 3.0*x*x-1;
}

// Función cabecera
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
                 printf("_#Problema_1_[b]__");
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
