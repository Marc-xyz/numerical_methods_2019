#include<stdio.h>
#include<math.h>
 
//Lema polinomio ortogonal --> todas raices simples, reales, y en (a,b).
//Conocemos número de soluciones y por tanto el número de intervalos (multip=1)
//Primero c
//localizar intervalos de cambio de signo 
//

//Función que evalua el polinomio de Legendre enésimo para x
double polin_Legndr(double n,double x);
//Función que evalua el polinomio de Chebyshev enésimo para x
double polin_Cheby(double n,double x);
//Función que da lista de intervalos de cambios de signo de polinomio
int roots(double n, double a[], double b[]);
//Función que evalua la derivada del polinomio de Legendre enésimo para x
double d_polin_Legndr(double n,double x);
/* */
//Función que evalua la derivada del polinomio de Chebyshev enésimo para x
/* */
 int main(void)
 {
     
 }
 //Función que da lista de intervalos de cambios de signo de polinomio
int roots(double n, double a[], double b[])
{
    
}
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
