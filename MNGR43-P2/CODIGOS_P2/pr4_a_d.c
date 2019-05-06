/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr4_a_d pr4_a_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr4_a_d pr4_a_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//Definimos una constante que limita el número máximo de iteraciones.
#define Max 100

//Quizás hay alguna función  que no se usa

//Función cabecera
void cabecera(void);

//Funciones que calculan el termino siguiente de cada una de las succiones 
double p_onemore(double a_f, double s_f);
double a_onemore(double a_i, double b_i);
double b_onemore(double a_i, double b_i);
double c_onemore(double a_f, double b_f);
double s_onemore(unsigned int k, double s_i, double c_f);

//Función principal
int main(void)
{
    //Los valores inicializados en cero no son valores iniciales dados.
    //Para guardar valores de p_k y p_{k+1} y p_{k-1}.
    double p_i=0, p_f=0, ps=0; 
    //Para guardar valores de (a_n) y (b_n) sucesiones. 
    double a_i=1, a_f=0, b_i=pow(2.0,-(1/2.0)), b_f=0; 
    //Para guardar valores de (c_n) y (s_n) sucesiones.
    double c_f=0, s_i=(1/2.0), s_f=0; 
    double v[4*3];
    unsigned int i=0, j=1, m=1;
    cabecera();
    printf("\n>Valores en funcion de la iteracion:");
    while(i<Max)
    {
    i=i+1;
    a_f=a_onemore(a_i,b_i);
    b_f=b_onemore(a_i,b_i);
    c_f=c_onemore(a_f,b_f);
    s_f=s_onemore(i,s_i,c_f);
    p_f=p_onemore(a_f,s_f);
    //Solo imprimiremos algunos valores
    if(i<=10 || (43<=i && i<=60) || ((Max-3)<=i && i<=Max) )
    {
    printf("\n Iteracion [#%u] ------------> %.16G", i, p_f);
    }
    if(i==11 || i==61 )
       {
        for(m=1;m<=3;m++)
        {
        printf("\n           :");
        }
       }
    //Guardamos valores orden de convergencia 
    if(i>2 && i<=4)
    {
    v[j]=fabs(p_f-p_i)/fabs(p_i-ps);
    v[j+1]=fabs(p_f-p_i)/pow(fabs(p_i-ps),2);
    v[j+2]=fabs(p_f-p_i)/pow(fabs(p_i-ps),3);
    v[j+3]=fabs(p_f-p_i)/pow(fabs(p_i-ps),4);
    j=j+4;
    }
    //Guardamos variables en una posición menos 
    ps=p_i;
    p_i=p_f;
    a_i=a_f;
    b_i=b_f;
    //c_i=c_f;
    s_i=s_f;
    }
    printf("\n\n>Los valores para el estudio de la convergencia son, antes de iteracion 6:");
    printf("\n (e_k/e_(k_1), e_k/(e_(k-1))^2, e_k/(e_(k-1))^3, e_k/(e_(k-1))^4)");
    for(j=1;j<=8;j=j+4)
    {
    printf("\n (%.10G,  %.10G,  %.10G,  %.10G)",v[j],v[j+1],v[j+2],v[j+3]);
    }
    printf("\n");
    return 0;
}

//Funciones que calculan el termino siguiente de cada una de las succiones 
 double p_onemore(double a_f, double s_f)
 {
     return (2.0*(a_f)*(a_f))/(s_f);
 }
 double a_onemore(double a_i, double b_i)
 {
     return ((b_i)+(a_i))/(2.0);
 }
 double b_onemore(double a_i, double b_i)
 {
     return sqrt((a_i)*(b_i));
 }
 double c_onemore(double a_f, double b_f)
 {
     return (a_f)*(a_f)-(b_f)*(b_f);
 }
 double s_onemore(unsigned int k, double s_i, double c_f)
 {
     return (s_i)-pow(2.0,k)*(c_f);
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
                 printf("_#Problema_4_[a]__");
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
