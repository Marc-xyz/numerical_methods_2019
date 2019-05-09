/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr6_d pr6_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr6_d pr6_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>


//(02)Función cabecera
void cabecera(void);

//(03)Función error
void error(void);

//(04)Función método Simpson
double metSimps(double a, double b, double NI);

//((05)Función del problema 6 (evalúa)
double f_6(double x);

//(01)Función principal
int main(void)
{
    double NI=2.0;
    cabecera();
    printf("\nCalculo mediante metodo compuesto de Simpson");   
    while(metSimps(1.0,2.0,NI)>(1.e-2))
    {
        NI=NI+2.0; // queremos NI par
    }
    printf("\nEn iteracion numero %g\n",NI/2);
    return 0;
}

//(04)Función métodos Simpson
double metSimps(double a, double b, double NI)
{
    unsigned int i;
    double  hm, h, s, x, er;
    h=(b-a)/NI;
    hm=h/(2.0);
    for(i=1,s=0,x=a;i<NI;i++)
    {
        x=x+h;
        s=s+(2.0)*f_6(x)+(4.0)*f_6(x+hm);
    }
    s=s*(h/6.0);
    s=s+h*(f_6(b)+f_6(a)+(4.0)*f_6(a+hm))/(6.0);
    er=((1.0/30.0)*h*h*h*h);
    if(er<1.e-2)
    {    
    printf("\nLa integral es aproximadamente %.16G",s);
    printf("\nEl error aproximado es de %.16G",er);
    }
    return er;
}
//((05)Función del problema 4 (evalúa )
double f_6(double x)
{
    return log(x);
}

//(03) Función error
void error(void)
{
   printf( "\n ERROR: Vaya alguna cosa ha salido mal. \n Prueve de introducir de nuevo los valor porfavor.\n" );
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
                 printf("__#Problema__[6]__");
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
