/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o rut_01 rut_01.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o rut_01 rut_01.c -lm
*/

//Librerías y definiciones 
#include<stdio.h>
#include<math.h>
#define N 8 //GRADO POLINOMIO MAXIMO
#define TOL 100  //NUMERO DE INTERVALOS A CONSIDERAR


#define F(x) (exp(-x*x)) //FUNCION A INTEGRAR UNO
/*#define G(x)*/ 


//Funcion que implementan el algoritmo del Método de Newton en precisión doble.
 double metNewd(double n, double x);


//Función que evalua el polinomio de Legendre enésimo para x.
 double polin_Legndr(double n,double x);
//Función que evalua la derivada del polinomio de Legendre enésimo para x.
 double d_polin_Legndr(double n,double x);
//Funcion que calcula los coeficientes de P(x) de Legendre.
 double coefi_Legndr(double n,double roots[], unsigned int i);



/*
//Función que evalua el polinomio de Chebyshev enésimo para x.
 double polin_Cheby(double n,double x);
//Función que evalua la derivada del polinomio de Chebyshev enésimo para x.
 double d_polin_Chevy(double n, double x);
//Funcion que calcula los coeficientes de P(x) de Chebyshev.
 double coefi_Chevy(double i);
*/
	
/*Comentarios teoricos
 * Lema polinomio ortogonal --> todas raices simples, reales, y en (a,b).
 * Conocemos número de soluciones y por tanto el número de intervalos (multip=1)
 * Localizar intervalos de cambio de signo 
*/

/****************************DATE************************************
 *                                                                  *
 *                   ACTUALMENTE EDITANDO                           *
 *                   INCI:05/06/07                                  *
 *                   NOTES:                                         *
 *                   *USE LONG LONG FLOAT                           *
 *                   *POLINOM[L,C]                                  *
 *                   *COEFI a_i                                     *
 *                   *SUMA FINAL DECRECIENTE                        *
 *                   *PONER COTA ERROR  			    *
 ********************************************************************/

//Función principal
int main(void)
 {
     /*********************Vectores:*********************** 
      *         *Delimitadores intervalos,                *
      *         *Itervalos con almenos una raiz           *
      *         *Raices                                   *
      *****************************************************/
     double points[TOL],
             I_roots[2*(N)],
	     roots[N];

     /***********************Valores:***********************
      *          *Intervalo [a,b]=[-1,1]                   *
      *          *Pivote 1 y 2                             *
      *          *Grado de P(x) en cada iteración          *
      *          *Suma \approx integral                    *
      *          *                                         *
      ******************************************************/
     double a=-1.0,b=1,
	    x_i, x_ii,
	    o ,
	    sum;
     unsigned int j, i,  m=-1, I=-1; 
    //contador de raices, numero de intervalos por dos
    /*cabezera del progrma*/
   for(o=2;o<=N;o+=2)
   {
    sum=0.0;
    /*Generamos intervalos*/   
     for(j=0;j<=TOL;i++)
     {points[1]=a+j*(b-a)/TOL;}
     /*Buscamos intervalos con almenos una raiz*/
     for(i=0;i<=TOL;i+=2)
 	 {
		 if(polin_Legndr(o,points[i])*polin_Legendr(o,points[i+1])<0)
		 {I+=2; I_roots[I-2]=points[i]; I_roots[I-1]=points[i]; }
     		 if(points[i]*points[i+1]==0)
           	 {
	         if(polin_Legendr(o,points[i])==0){m++;roots[m]=points[i];}
         	 if(polin_Legendr(o,points[i+1])==0){m++;roots[m]=points[i+1];}
                 }
 	 }
     /*Comprovamos número intervalos*/
     if((I+1)!=(2*o)){printf("\nERROR");}
     /*Aplicamos Newton para obtener raízes*/
     for(j=0;j<=I;i+=2)
     {	
	 x_i=(I_roots[j+1]-I_roots[j])/2.0;
	 for(i=0;i<=1000;i++)
          {x_ii=metNewd(o,x_i); if(fabs(x_i-x_ii)<=1.0e-7){m++;roots[m]=x_ii;} x_i=x_ii;}
     }
     /*Comprovamos número raices*/
     if((m+1)!=(o)){printf("\nERROR");}
     /*Calculamos suma final aproximada*/
     for(j=1;j<=o;j++)
     {sum+=coefi_Legndr(o,roots,i)*F(roots[j-1]);}
     printf("\nNew  [%g], is %.16G",o,sum);
   }
    return 0;
 }

/*********************************************************************
 *
 *
 *
 *
 *******************************************************************/
//Función que evalua el polinomio de Legendre enésimo para x
 double polin_Legndr(double n,double x)
 {
     unsigned int i;
     double P_i=1.0,P_ii=x,P_iii;
     if(n==0.0)
    
         return P_i;
     }
     if(n==1.0)
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
    return 1.0/(1.0-x*x)*(-n*x*polin_Legndr(n,x)+n*d_polin_Legndr(n-1.0,x));
}

//Funcion que calcula los coeficientes de P(x) de Legendre.
  double coefi_Legndr(double n,double roots[], unsigned int i)
{
	double a= (2.0)/((1-roots[i-1])*(1-roots[i-1])\
        *(d_polin_Legndr(n,roots[i-1])*d_polin_Legndr(n,roots[i-1])));
	return a;
}
//Funcion que implementan el algoritmo del Método de Newton en precisión doble.
double metNewd(double n, double x)
{
    return x-(polin_Legndr(x))/(d_polin_Legndr(x));
}

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
