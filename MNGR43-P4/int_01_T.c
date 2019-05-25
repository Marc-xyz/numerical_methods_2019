/****************************DATE************************************
 *FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
 *NOMBRE FICHERO:int_01_T.c                                         *
 *DESCRIPCIÓN: Programa para calcular numéricamente la integral     * 
 *                                                                  *
 *                          / 1                                     *
 *                         |   -x*x                                 *
 *                         | e      dx                              *
 *                         |                                        *
 *                         / -1                                     *
 *                                                                  *
 *  Mediante regla de los Trapecios compuestos.                     *
 ********************************************************************/

                 /***********************COMPILE**********************
                 *  Compilar con  nivel de optimización 3            *
                 *  gcc -g -Wall -O3 -o int_01_T int_01_T.c -lm      * 
                 *  Compilar con  sintaxis standard ANSI C del 1990  *
                 *  gcc -g -Wall -pedantic -o int_01_T int_01_T.c -lm*
                 * ***************************************************/

// Librerías y definiciones
#include<stdio.h>
#include<math.h>
#define F(x) (exp(-x*x)) //FUNCION A INTEGRAR f(x):=e^(-x^2) en	 [-1,1]

//(02)Función métodos trapecios.
int metTrapz(double a, double b, double NI);
//(03)Función error.
void error(void);
//(04)Función cabecera.
void cabecera(void);

//(01)Función principal
int main(void)
{
    double j;
    cabecera();
    printf("\nCalculo mediante metodo compuesto de los Trapecios");    
    for(j=4.0;j<=1024.0;j=j*2.0)
    {
    if(metTrapz(-1.0,1.0,j)!=0){error(); return -1;}
    }
    printf("\n\n");
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
        s=s+F(x);
    }
    s=s*h;
    s=s+h*(F(a)+F(b))/2.0;
    printf("\n Para [n=%2d] la aproximacion es: %.16G",i,s);
    printf(" y cota de error: ******************* ");
    /*printf("\nUna cota superior para el error esperado es: %.8G\n",fabs(er));*/
    return 0;
}

//(03) Función error
void error(void)
{
   printf( "\n ERROR: Vaya alguna cosa ha salido mal. \n Prueve de introducir de nuevo los valor por favor.\n" );
   return ;
}
//(06) Función que imprime la cabecera del programa.
void cabecera(void)
{
printf("\n****************************DATE************************************");
printf("\n*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *");
printf("\n*NOMBRE FICHERO ORIGEN:int_01_T.c                                  *");
printf("\n*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *");
printf("\n*                                                                  *");
printf("\n*     / 1                                                          *");
printf("\n*     |    -x*x                                                    *");
printf("\n*     |  e       dx    mediante regla de los Trapecios compuestos. *");
printf("\n*     |                                                            *");
printf("\n*     / -1                                                         *");
printf("\n********************************************************************");
printf("\n\n");
return ;
}
