/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr1_c_d pr1_c_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr1_c_d pr1_c_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//Definimos una constante que limita el número máximo de iteraciones.
#define Max 100

//Función cabecera
void cabecera(void);

//Funciones que evalúan el polinomio en precisión doble.
double polid_n(double x);

//Funcion que calculan alfa  (de formulas de Cardano) en precisión doble.
void avald(double *x);

//Funcion que evalúan la derivada del polinomio en precisión doble.
double polid_d(double x);

//Funcion que implementan el algoritmo del Método de Newton en precisión doble.
double metNewd(double x);

//Función que implementan el algoritmo Método de la bisección en precisión  doble.
void metBisecd(double *a, double *b, double*z_f);

//Función que implementan el algoritmo Método de la secante en precisión  doble.
void metSecntd(double *a, double *b);

//Función principal
int main(void)
{
    double z_i=2.0,z_f, zs;
    double a=2.0,b=8.0,c=2.0;
    unsigned int j=0, jp=0;
    cabecera();
    //Calculamos valores  directamente por fórmulas de Cardano 
    avald(&zs);
    printf("\n>El valor aproximado de la solucion por formulas de Cardano:");
    printf("\n *Para precision double es %.16G,\n con un error absoluto de aproximadamente %.6G,\n",zs,polid_n(zs));
/*
 *Calculamos valores  directamente por Método de la bisección
*/
    printf("\n>Los valores para la raiz con 15 decimales correctos son:\n\n");
    while(j<Max)
    {
       j=j+1;
       metBisecd(&a,&b,&z_f);
       if(j<10)
       {
       printf("\n Iteracion [#%u] (Biseccion,double) ------------> %.16G", j,z_f);
       }
       if(j==10)
       {
        for(j=10;j<=13;j++)
        {
        printf("\n           :");
        }
        j=10;
        }
       if(j>50)
       {
       printf("\n Iteracion [#%u] (Biseccion,double) ------------> %.16G", j,z_f);
       }
       if((6.0*(1/c))<1.e-16)
        {
            jp=j;
            break;
        }
        c=c*2.0;
    }
    printf("\n *(c1) Con Metodo de la Biseccion logrado en %u iteraciones es:\n %.16G\n\n",jp,z_f);
/*
 * Calculamos valores  directamente por Método de la secante
 */
    j=0;
    z_f=0;
    a=2.0;
    b=8.0;
    while(j<Max)
    {
       j=j+1;
       metSecntd(&a,&b);
       z_f=b;
       if(j<10)
       {
       printf("\n Iteracion [#%u] (Secante,double) ------------> %.16G", j,z_f);
       }
       if(fabs(a-b)<1.e-16)
        {
            jp=j;
            break;
        }
     
       
    }
    printf("\n *(c2) Con Metodo de la Secante logrado en %u iteraciones es: \n %.16G\n \n\n",jp,z_f);
/*
 * Calculamos valores  directamente por Método de Newton
 */
    j=0;   
    z_i=2;
    while(j<Max)
    {
        j=j+1;
        z_f=metNewd(z_i);
        printf("\n Iteracion [#%u] (Newton,double) ------------> %.16G", j,z_f);
        if(fabs(z_f-z_i)<1.e-16)
        {
            jp=j;
            break;
        }
        z_i=z_f;
    }
    printf("\n *(c3) Con Metodo de Newton logrado en %u iteraciones es:\n %.16G\n\n",jp,z_f);
    return 0;
}
void metSecntd(double *a, double *b)
{
   double x, x_i= (*a), x_f=(*b);
   x=x_f-polid_n(x_f)*(x_f-x_i)/(polid_n(x_f)-polid_n(x_i));
   (*a)=(*b);
   (*b)=x;
}
void metBisecd(double *a, double *b, double*z_f)
{
    double p_i, a_i=(*a), b_i=(*b);
    p_i=(a_i+b_i)/2.0;
    if(polid_n(a_i)*polid_n(p_i)<=0)
    {
        (*b)=p_i;
        (*z_f)=p_i;
    }
    else
    {
        (*a)=p_i;
        (*z_f)=p_i;
    }
    return ;
}
//Método Newton
double metNewd(double x)
{
    return x-(polid_n(x))/(polid_d(x));
}

//Función normal
double polid_n(double x)
{
     return x*x*x-x-400;
}

//Función derivada 
double polid_d(double x)
{
     return 3.0*x*x-1;
}

//Función valores alfa (Cardano)
void avald(double *x)
{
    double diss=(400.0*400.0)-(4.0/27.0);
    (*x)= (double) pow((400+sqrt(diss))/2.0,1/3.0)+pow((400-sqrt(diss))/2.0,1/3.0);
    return ;
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
                 printf("_#Problema_1_[c]__");
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
