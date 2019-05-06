/*
   Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o ex5_bc_fd ex5_bc_fd.c -lm

  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o ex5_bc_fd ex5_bc_fd.c -lm

  *Nota1: Este programa imprime directamente con las dos precisiones.
  *Nota2: Se ha organizado un poco diferente con mayor uso de funciones y se dan como output las dos precisiones.
*/
 
// Librerías 
#include<stdio.h>
#include<math.h>

//Declaramos funciones de interfaz de texto
void cabecera(void);
void error(void);

//Declaramos función input
int preg(double *ad, double *bd, double *cd, float *af, float *bf, float *cf);

//Declara funciones cálculos 
float fpf(float af, float bf, float cf);
double fpd(double ad, double bd, double cd);
float heronf(float af, float bf, float cf, float pf);
double herond(double ad, double bd, double cd,double pd);
float heronnf(float af, float bf, float cf);
double heronnd(double ad, double bd, double cd);

//Función principal 
int main (void)
{
    //Declaramos variables
    float  af, bf, cf, pf, Af, Aff;
    double ad, bd, cd, pd, Ad, Add;
    // Preguntamos y guardamos valores de los lados
    cabecera();
    if(preg(&ad,&bd,&cd,&af,&bf,&cf)==-1)
    {return -1;}
    //Calculamos valor con fórmula (6) y imprimimos
    pf=fpf(af,bf,cf);
    pd=fpd(ad,bd,cd);
    Af=heronf(af,bf,cf,pf);
    Ad=herond(ad,bd,cd,pd);
    printf("\nLos valores para la (formula (6)) y (formula alternativa) son:");
    printf("\nA(float,(6))=:%.7F",Af);
    printf("\nA(double,(6))=:%.14G",Ad);
    //Calculamos valor con fórmula alternativa y imprimimos
    Aff=heronnf(af,bf,cf);
    Add=heronnd(ad,bd,cd);
    printf("\nA(float,(alternativa))=:%.7F",Aff);
    printf("\nA(double,(alternativa))=:%.14G\n",Add);
    return 0;
}

//Definimos funciones de interfaz de texto
// Función cabezera
/* Esta función se puede ignorar solo produce la cabecera del programa, pero es agradable. */
void cabecera(void)
{
    int i, j, n=70, m=20;
    for(j=0;j<=4;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Ejercicio_5_|b,c|_");
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

//Definimos función input
// Función preguntar
int preg(double *ad, double *bd, double *cd, float *af, float *bf, float *cf)
{
    printf("\n Introduzca valores reales  para los lados del triangulo en orden decreciente \nEjemplo: \na=1.0e8 \nb=1.0e8 \nc=0.01\n");
    printf("\na= ");
    if(!scanf("%lf",ad) || *ad<=1.E-16)
    { error(); return -1;}
    printf("b= ");
    if(!scanf("%lf",bd) || *bd<=1.E-16)
    { error(); return -1;}
    printf("c= ");
    if(!scanf("%lf",cd) || *cd<=1.E-16)
    { error(); return -1;}
    if((*ad)+(*bd)<(*cd)||(*ad)+(*cd)<(*bd)||(*cd)+(*bd)<(*ad))
    {printf("\nLos valores no cumplen D.T\n"); error(); return -1;}
    if((*ad)<(*bd)||(*ad)<(*cd)||(*bd)<(*cd))
    {printf("\nLos valores no han sido ordenados correctamente \n"); error(); return -1;}
    //Aqui perdemos decimales intecionadamente 
    (*af)= (float) (*ad); 
    (*bf)= (float) (*bd);
    (*cf)= (float) (*cd);
    return 0;
}

//Definimos funciones cálculos 
// Funciones pf para doble y float
float fpf(float af, float bf, float cf)
{
  return (af+bf+cf)/2.00;
}
double fpd(double ad, double bd, double cd)
{
    return (ad+bd+cd)/2.00;
}

// Funciones herond y heronf
float heronf(float af, float bf, float cf, float pf)
{
    return sqrtf(pf*(pf-af)*(pf-bf)*(pf-cf));
}
double herond(double ad, double bd, double cd,double pd)
{
    return sqrt(pd*(pd-ad)*(pd-bd)*(pd-cd));
}
// Funciones heronnd y heronnf
float heronnf(float af, float bf, float cf)
{
    float a=(af+(bf+cf)), b=(cf-(af-bf)),c=(cf+(af-bf)), d=(af+(bf)-cf);
    return (sqrtf((a)*(b)*(c)*(d)))/4;
}
double heronnd(double ad, double bd, double cd)
{
    float a=(ad+(bd+cd)), b=(cd-(ad-bd)),c=(cd+(ad-bd)), d=(ad+(bd)-cd);
    return (sqrt((a)*(b)*(c)*(d)))/4;
}
