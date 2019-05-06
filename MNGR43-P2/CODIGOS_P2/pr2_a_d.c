/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr2_a_d pr2_a_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr2_a_d pr2_a_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//Definimos una constante que limita el número máximo de iteraciones.
#define Max 100

//Función cabecera
void cabecera(void);

// Función error
void error(void);

//Funciones que evalúan el polinomio en precisión doble.
double polid_n(double x);

//Funcion que evalúan la derivada del polinomio en precisión doble.
double polid_d(double x);

//Funcion que que devuelven un termino más de (x_k) i (b_k) respectivamente.
double x_onemore(double x_i, double b_i);
double b_onemore(double x_f, double b_i);

//Función principal
int main(void)
{
    double x_i=0.0, x_f=0.0, xs=0; //Para guardar valores de x_k y x_{k+1} y x_{k-1}
    double b_i=0.0, b_f=0.0; //Para guardar valores de las b_k y b_{k+1}
    double v[4*20]; // Matriz con valores para ordenes de convergencia 
    unsigned int i=0, j=1, m=0; //Contadores
    cabecera();
     printf("\n Introduzca un valor  para el pivote x_0 en [2,10] \n Ejemplo:  6.0\n");
    if(!scanf("%lf",&x_i) || x_i<2.0 || x_i>10.0)
    { error(); return -1; }
    //Calculamos b_0
    b_i=1/(polid_d(x_i));
/*
 * Limitamos numero máximo de iteraciones por si no hubiera convergencia 
*/
    while(i<Max) //
    {
    i=i+1;
    x_f=x_onemore(x_i,b_i);
    if(i<10) //Solo imprimimos 10 iteraciones 
    {
    printf("\n Iteracion [#%u] ------------> %.16G", i,x_f);
    }
   if(i>1) //guardamos valores orden de convergencia 
    {
    v[j]=fabs(x_f-x_i)/fabs(x_i-xs);
    v[j+1]=fabs(x_f-x_i)/(fabs(x_i-xs)*fabs(x_i-xs));
    v[j+2]=fabs(x_f-x_i)/pow(fabs(x_i-xs),3);
    v[j+3]=fabs(x_f-x_i)/pow(fabs(x_i-xs),4);
    j=j+4;
    }
    if(fabs(x_f-x_i)<1.e-16) //precisión objetivo
    {
        m=1;
        break;
    }
    b_f=b_onemore(x_f,b_i);
    xs=x_i;
    b_i=b_f;
    x_i=x_f;
    }
    if(i<100 && m==1) //Por si modificamos el programa posteriormente y no hay convergencia
    {
    printf("\n>El valores para la raiz con 15 decimales correctos es:");
    printf("\n *Con Metodo Nuevo logrado en %u iteraciones:\n %.16G",i-1,x_f);
    printf("\n>Los valores para el estudio de la convergencia son:");
    printf("\n(e_k/e_(k_1), e_k/(e_(k-1))^2, e_k/(e_(k-1))^3, e_k/(e_(k-1))^4)");
    for(j=1;j<=4*i-4*3;j=j+4)
    {
    printf("\n (%.10G,  %.10G,  %.10G,  %.8G)",v[j],v[j+1],v[j+2],v[j+3]);
    }
    }
    else
    {
        printf("\n Meodo no convergente con el valor introducido, pruebe con x_0=6.0\n");
    }
    printf("\n");
    return 0;
}

// Función que devuelve un termino más de (x_k)
 double x_onemore(double x_i, double b_i)
 {
     return (x_i)-(b_i)*polid_n(x_i);
 }
 // Función que devuelve un termino más de (b_k)
 double b_onemore(double x_f, double b_i)
 {
     return (b_i)*(2-polid_d(x_f)*(b_i));
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
                 printf("_#Problema_2_[a]__");
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
