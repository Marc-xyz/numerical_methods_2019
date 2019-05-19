  /****************************************************
  *  Compilar con  nivel de optimización 3            *
  *  gcc -g -Wall -O3 -o rut_02 rut_02.c -lm          * 
  *  Compilar con  sintaxis standard ANSI C del 1990  *
  *  gcc -g -Wall -pedantic -o rut_02 rut_02.c -lm    *
  ****************************************************/

//Librerías y definiciones 
#include<stdio.h>
#include<math.h>
#define N 16 //GRADO POLINOMIO MÁXIMO
#define TOL 1000  //NUMERO DE INTERVALOS A CONSIDERAR
#define F(x) (exp(-x*x)) //FUNCION A INTEGRAR f(x):=e^(-x^2)

//Funcion que implementan el algoritmo del Método de Newton en precisión doble.
 double metNewd(double n, double x);
//Función que evalua el polinomio de Chebyshev enésimo para x.
 double polin_Cheby(double n,double x);
//Función que evalua la derivada del polinomio de Chebyshev enésimo para x.
 double d_polin_Chevy(double n, double x);
//Funcion que calcula los coeficientes de P(x) de Chebyshev.
 double coefi_Chevy(double i);

 
 
 /*
 //Función que evalua el polinomio de Chebyshev enésimo para x
 double polin_Cheby(double n,double x)
 {
     unsigned int i;
     double P_i=1.0,P_ii=x,P_iii;
     if(n==0.0)
     {
         return P_i;
     }
     if(n=1.0)
     {
         return P_ii;
     }
     for(i=2;i<=n;i++)
     {
         P_iii=(2.0)*P_ii-P_i;
         P_i=P_ii;
         P_ii=P_iii;
     }
     return P_iii;
 }
 
//Funcion que implementan el algoritmo del Método de Newton en precisión doble.
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
*/


