/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o rut_01 rut_01.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o rut_01 rut_01.c -lm
*/

//Librerías y definiciones 
#include<stdio.h>
#include<math.h>
#define N 16 //GRADO POLINOMIO MAXIMO
#define TOL 1000  //NUMERO DE INTERVALOS A CONSIDERAR


#define F(x) (exp(-x*x)) //FUNCION A INTEGRAR UNO
/*#define G(x)*/ 


//Funcion que implementan el algoritmo del Método de Newton en precisión doble.
 double metNewd(double n, double x);


//Función que evalua el polinomio de Legendre enésimo para x.
 double polin_Legndr(double n,double x);
//Función que evalua la derivada del polinomio de Legendre enésimo para x.
 double d_polin_Legndr(double n,double x);
//Funcion que calcula los coeficientes de P(x) de Legendre.
 double coefi_Legndr(double n,double ro);



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
      double points[TOL+1],
             I_roots[2*TOL],
	         roots[N+1];

     /***********************Valores:***********************
      *          *Intervalo [a,b]=[-1,1]                   *
      *          *Pivote 1 y 2                             *
      *          *Grado de P(x) en cada iteración          *
      *          *Suma \approx integral                    *
      *          *                                         *
      ******************************************************/
     double a=-1.0,b=1.0,
	    x_i=0, x_ii=0,
	    o ,
	    sum;
    int j, i,  m=0, I=0; 
    //contador de raices, numero de intervalos por dos
    /*cabezera del progrma*/
   for(o=2;o<=N;o+=2)
   {
    sum=0.0; m=0; I=0;
    /*Generamos puntos intervalos*/   
     for(j=0;j<=TOL;j++)
     {points[j]=a+(j*(b-a)/TOL);printf("%g", points[j]);}
     /*Buscamos intervalos con almenos una raiz*/
     for(i=1;i<TOL;i++)
 	 {
		 if(polin_Legndr(o,points[i-1])*polin_Legndr(o,points[i])<0)
		 {I++; I_roots[I-1]=points[i-1];I++; I_roots[I-1]=points[i];
			 printf("[%g,%g]", I_roots[I-1],I_roots[I-2]); }
     		 if(points[i]*points[i+1]==0)
           	 {
	         if(polin_Legndr(o,points[i-1])==0){m++;roots[m-1]=points[i];}
         	 if(polin_Legndr(o,points[i])==0){m++;roots[m-1]=points[i-1];}
             }
 	 }
     /*Comprovamos número intervalos*/
     if((I)!=(2.0*o)){printf("\nERROR"); return -1;}
     printf("Fins aqui");
     /*Aplicamos Newton para obtener raízes*/
     for(j=1;j<=I;j+=2)
     {	
	 x_i=(I_roots[j-1]+I_roots[j])/2.0;
	 for(i=0;i<=100;i++)
          {x_ii=metNewd(o,x_i); if(fabs(x_i-x_ii)<=1.0e-12){m++;roots[m-1]=x_ii ; i=101;} x_i=x_ii;}
     }
      printf("Fins aqui");
     /*Comprovamos número raices*/
     if((m)!=(o)){printf("\nERROR,m=%d]",m); return -1;}
     /*Calculamos suma final aproximada*/
     for(j=0;j<o;j++)
     {sum+=coefi_Legndr(o,roots[j])*F(roots[j]);}
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
     double i;
     double P_i=1.0,P_ii=x,P_iii=0;
     if(n==0.0)
     {
         return P_i;
     }
     if(n==1.0)
     {
         return P_ii;
     }
     for(i=2;i<=n;i++)
     {
         P_iii=(1.0/(i))*(((2.0)*i-1.0)*x*P_ii-(i-1.0)*P_i);
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

//Funcion que calcula los coeficientes de P(x) de Legendre.
  double coefi_Legndr(double n,double ro)
{
	double a= (2.0)/((1-ro*ro)*(d_polin_Legndr(n,ro)*d_polin_Legndr(n,ro))) ;
	return a;
}
//Funcion que implementan el algoritmo del Método de Newton en precisión doble.
double metNewd(double n, double x)
{
    return x-(polin_Legndr(n,x))/(d_polin_Legndr(n,x));
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
