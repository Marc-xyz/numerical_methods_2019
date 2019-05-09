/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr5_d pr5_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr5_d pr5_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//(02)Función cabecera
void cabecera(void);

//(03)Función error
void error(void);

//(04)Función métodos trapecios
int metTrapz(double a, double b, double NI);

//((05)Función del problema 5 (evalúa)
double f_5(double x);

//(01)Función principal
int main(void)
{
    cabecera();
    double j;
    printf("\nCalculo mediante metodo compuesto de los Trapecios");    
    for(j=4.0;j<=65.0;j=j*2.0)
    {
    if(metTrapz(1.0,5.0,j)!=0){error(); return -1;}
    }
    printf("\n");
}


//(04)Función métodos trapecios
int metTrapz(double a, double b, double NI)
{
    unsigned int i;
    double h, s, x, er;
    h=(b-a)/NI;
    er=(4.0)*(1.0/12.0)*((exp(5.0)*(5.0*5.0-2.0*5.0+2.0))/((5.0)*(5.0)*(5.0)))*h*h;
    for(i=1,s=0,x=a;i<NI;i++)
    {
        x=x+h;
        s=s+f_5(x);
    }
    s=s*h;
    s=s+h*(f_5(a)+f_5(b))/2.0;
    printf("\n Para (%g) intervalos:",NI);
    printf("\nLa integral es aproximadamente %.16G",s);
    printf("\nUna cota superior para el error esperado es: %.8G\n",fabs(er));
    return 0;
}

//((05)Función del problema 4 (evalúa )
double f_5(double x)
{
    return exp(x)/(x);
}


//(03) Función error
void error(void)
{
   printf( "\n ERROR: Vaya alguna cosa ha salido mal. \n Prueve de introducir de nuevo los valor por favor.\n" );
   return ;
}

//(02) Función cabezera
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
                 printf("_#Problema___[5]__");
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
