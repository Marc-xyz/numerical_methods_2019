/****************************DATE************************************
 *FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
 *NOMBRE FICHERO:int_02_T.c                                         *
 *DESCRIPCIÓN: Programa para calcular numéricamente las integrales  * 
 *                                                                  *
 *                    / 1                                           *
 *                   |     e^(-x^2)                                 *
 *                   |  ------------- dx                            *
 *                   |  (1-x^2)^(1/3)                               *
 *                   / 0                                            *
 *                                                                  *
 *  Mediante regla de los Trapecios compuestos.                     *
 ********************************************************************/

                 /***********************COMPILE**********************
                 *  Compilar con  nivel de optimización 3            *
                 *  gcc -g -Wall -O3 -o int_02_T int_02_T.c -lm      * 
                 *  Compilar con  sintaxis standard ANSI C del 1990  *
                 *  gcc -g -Wall -pedantic -o int_02_T int_02_T.c -lm*
                 * ***************************************************/

// Librerías y definiciones
#include<stdio.h>
#include<math.h>
/*FUNCIÓN A INTEGRAR MODIFICADA [0,1] */
#define G(x) (exp(-x*x)*pow(1.0-x*x,-1.0/3.0))

//(02)Función cabecera
void cabecera(void);
//(03)Función error
void error(void);
//(04)Función métodos trapecios
int metTrapz(double a, double b, double NI);

//(01)Función principal
int main(void)
{
    double j;
    cabecera();
    for(j=2.0;j<=4096.0;j=j*2.0)
    {
    if(metTrapz(0.0,1.0-1.0e-3,j)!=0){error(); return -1;}
    /*pequeña trampa:  evitamos asíntota vertical*/
    }
    printf("\n");
}
/***********************DEFINITIONS*OF*FUNCTIONS********************
 *          (02) int metTrapz(double a, double b, double NI)       *
 *          (03) void error(void)                                  *
 *          (04) void cabecera(void)                               *
 *******************************************************************/
//(02)Función métodos trapecios
int metTrapz(double a, double b, double NI)
{
    unsigned int i;
    double h, s, x;
    h=(b-a)/NI;
    for(i=1,s=0,x=a;i<NI;i++)
    {
        x=x+h;
        s=s+G(x);
    }
    s=s*h;
    s=s+h*(G(a)+G(b))/2.0;
    printf("\n Para [n=%2d] la aproximacion es: %.16G",i,s);
    return 0;
}
//(03) Función error
void error(void)
{
   printf( "\n ERROR: Vaya alguna cosa ha salido mal. \n Prueve de introducir de nuevo los valor por favor.\n" );
   return ;
}
//(04) Función que imprime la cabecera del programa.
void cabecera(void)
{
printf("\n****************************DATE************************************");
printf("\n*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *");
printf("\n*NOMBRE FICHERO ORIGEN:int_02_T.c                                  *");
printf("\n*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *");
printf("\n*                                                                  *");
printf("\n*            / 1                                                   *");
printf("\n*           |      e^(-x^2)                                        *");
printf("\n*           |  -------------- dx   (integral impropia)             *");
printf("\n*           |   (1-x^2)^(1/3)                                      *");
printf("\n*           / 0                                                    *");
printf("\n*       (por defecto) mediante regla de los Trapecios compuestos.  *");
printf("\n*                                                                  *");
printf("\n********************************************************************");
printf("\n");
return ;
}
