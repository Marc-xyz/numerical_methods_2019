/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr3_ab_d pr3_ab_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr3_ab_d pr3_ab_d.c -lm
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

//Función que evalúan la  primera y segunda derivada del polinomio en precisión doble.
double polid_d(double x);
double polid_dd(double x); // Función derivada segunda

//Función del método de Halley
double metHall(double x_i);

//Función principal
int main(void)
{
    double x_i=0.0, x_f=0.0, xs=0; //Para guardar valores de x_k y x_{k+1} y x_{k-1}
    double v[4*20];
    unsigned int i=0, j=1, m=0;
    cabecera();
    printf("\n Introduzca un valor  para el pivote x_0 en [2,10] \n Ejemplo:  6.0\n");
    if(!scanf("%lf",&x_i) || x_i<2.0 || x_i>10.0)
    { error(); return -1; }
    /*
    * Limitamos numero máximo de iteraciones por si no hubiera convergencia 
    */
    while(i<Max)
    {
    i=i+1;
    x_f=metHall(x_i);
    if(i<10) //Solo imprimimos 10 iteraciones 
    {
    printf("\n Iteracion [#%u] ------------> %.16G", i,x_f);
    }
    if(i>1)
    {
    v[j]=fabs(x_f-x_i)/fabs(x_i-xs);
    v[j+1]=fabs(x_f-x_i)/(fabs(x_i-xs)*fabs(x_i-xs));
    v[j+2]=fabs(x_f-x_i)/pow(fabs(x_i-xs),3);
    v[j+3]=fabs(x_f-x_i)/pow(fabs(x_i-xs),4);
    j=j+4;
    }
    if(fabs(x_f-x_i)<1.e-16) //precisión objetivo evitando error de redondeo  
    {
        m=1;
        break;
    }
    xs=x_i;
    x_i=x_f;
    }
    if(i<100 && m==1) //Por si no hay convergencia
    {
    printf("\n>El valores para la raiz con 15 decimales correctos es:");
    printf("\n *Con Metodo Halley logrado en %u iteraciones es:\n %.16G",i-1,x_f);
     printf("\n>Los valores para el estudio de la convergencia son:");
    printf("\n\n (e_k/e_(k_1), e_k/(e_(k-1))^2, e_k/(e_(k-1))^3, e_k/(e_(k-1))^4)");
    for(j=1;j<=i*4-8;j=j+4)
    {
    printf("\n (%.10G,  %.10G,  %.10G,  %.10G)",v[j],v[j+1],v[j+2],v[j+3]);    }
    }
    printf("\n");
    return 0;
}

// Función que devuelve un termino más de (x_k)
 double metHall(double x_i)
 {
     return (x_i)-(2*polid_n(x_i)*polid_d(x_i))/(2*pow(polid_d(x_i),2)-polid_n(x_i)*polid_dd(x_i));
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
//Función derivada segunda
double polid_dd(double x)
{
     return 6.0*x;
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
    int i, j, n=70, m=20;
    for(j=1;j<=3;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Problema_3_[a,b]__");
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
