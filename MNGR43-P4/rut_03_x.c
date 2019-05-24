/****************************DATE************************************
 *FECHA ULTIMA MODIFICACIÓN:19/05/2019                              *
 *NOMBRE FICHERO:rut_03_x.c                                         *
 *DESCRIPCIÓN: Programa para calcular numéricamente las integrales  * 
 *                                                                  *
 *     / 1                 / 1                                      *
 *     |   -x*x            |     e^(-x^2)                           *
 *     | e      dx   ;     |  ------------- dx                      *
 *     |                   |  (1-x^2)^(1/3)                         *
 *     / -1                / 0                                      *
 *                                                                  *
 *  Mediante regla de los Trapecios compuestos.                     *
 ********************************************************************/

                 /***********************COMPILE**********************
                 *  Compilar con  nivel de optimización 3            *
                 *  gcc -g -Wall -O3 -o rut_03_x rut_03_x.c -lm      * 
                 *  Compilar con  sintaxis standard ANSI C del 1990  *
                 *  gcc -g -Wall -pedantic -o rut_03_x rut_03_x.c -lm*
                 * ***************************************************/

// Librerías y definiciones
#include<stdio.h>
#include<math.h>
/*FUNCIÓN A INTEGRAR MODIFICADA [0,1] */
#define G(x) (exp(-x*x)*pow(1.0-x*x,-1.0/3.0))
#define F(x) (exp(-x*x)) //FUNCION A INTEGRAR f(x):=e^(-x^2) en [-1,1]

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
    printf("\nCalculo mediante metodo compuesto de los Trapecios");    
    for(j=2.0;j<=4096.0;j=j*2.0)
    {
    if(metTrapz(0.0,1.0-1.e-12,j)!=0){error(); return -1;}
    }
    printf("\n");
}


//(04)Función métodos trapecios
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

