/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o rut_01 rut_01.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o rut_01 rut_01.c -lm
*/

//Librerías 
#include<stdio.h>
#include<math.h>
 
 
//Funcion que implementan el algoritmo del Método de Newton en precisión doble.
double metNewd(double x);

//Lema polinomio ortogonal --> todas raices simples, reales, y en (a,b).
//Conocemos número de soluciones y por tanto el número de intervalos (multip=1)
//Primero c
//localizar intervalos de cambio de signo 
#define N 10

double prova(double x);
int roots(double a, double b, double n, double I[], double (*func)( double ));
int main(void)
 {
     double I[N];
     if(roots(-1.0,1.0,3.0,I,prova)!=0){printf("ERROR"); return -1;}
     return 0;
 }
     

 
//Función que evalua el polinomio de Legendre enésimo para x
double polin_Legndr(double n,double x);
//Función que evalua el polinomio de Chebyshev enésimo para x
double polin_Cheby(double n,double x);
//Función que da lista de intervalos de cambios de signo de polinomio
int roots(double n, double a[], double b[]);
//Función que evalua la derivada del polinomio de Legendre enésimo para x
double d_polin_Legndr(double n,double x);
//Función que evalua la derivada del polinomio de Chebyshev enésimo para x
 //Función que evalua el polinomio de Legendre enésimo para x
 double polin_Legndr(double n,double x)
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
         P_iii=(1.0/(n+1.0))*(((2.0)*n+1.0)*x*P_ii-n*P_i);
         P_i=P_ii;
         P_ii=P_iii;
     }
     return P_iii;
 }
//Función que evalua la derivada del polinomio de Legendre enésimo para x
double d_polin_Legndr(double n,double x)
{
    return 1.0/(1.0-x*x)*(-n*x*polin_Legndr(n,x)+n*polin_Legndr(n-1.0,x));
}

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
