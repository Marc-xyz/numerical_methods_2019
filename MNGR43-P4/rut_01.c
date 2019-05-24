
/****************************DATE************************************
i *FECHA ULTIMA MODIFICACIÓN:19/05/2019                              *
 *NOMBRE FICHERO:rut_01.c                                           *
 *DESCRIPCIÓN: Programa para calcular numéricamente la integral     * 
 *                                                                  *
 *     / 1                                                          *
 *     |   -x*x                                                     *
 *     | e      dx  mediante cuadratura de Gauss-Legendre.          *
 *     |            con precisión máxima de 15 decimales correctos. *
 *     / -1                                                         *
 ********************************************************************/
               
                 /***********************COMPILE**********************
                 *  Compilar con  nivel de optimización 3            *
                 *  gcc -g -Wall -O3 -o rut_01 rut_01.c -lm          * 
                 *  Compilar con  sintaxis standard ANSI C del 1990  *
                 *  gcc -g -Wall -pedantic -o rut_01 rut_01.c -lm    *
                 * ***************************************************/

//Librerías y definiciones 
#include<stdio.h>
#include<math.h>
#define N 20 //GRADO POLINOMIO MÁXIMO
#define TOL 1000  //NUMERO DE INTERVALOS A CONSIDERAR
#define F(x) (exp(-x*x)) //FUNCION A INTEGRAR f(x):=e^(-x^2)
 


//Función que implementan el algoritmo del Método de Newton en precisión doble.
 double metNewd(double n, double x);
//Función que evalúa el polinomio de Legendre enésimo para x.
 double polin_Legndr(double n,double x);
//Función que evalúa la derivada del polinomio de Legendre enésimo para x.
 double d_polin_Legndr(double n,double x);
//Función que calcula los coeficientes de P(x) de Legendre.
 double coefi_Legndr(double n,double ro);


/*************************THEORETICAL COMMENTS************************************
 * Lema polinomio ortogonal --> todas raíces simples, reales, y en (a,b).        *
 * Conocemos número de soluciones y por tanto el número de intervalos (multip=1) * 
 * Localizar intervalos de cambio de sign .                                      *
 *********************************************************************************/

//Función principal
int main(void)
{
 /*********************Vectores:*********************** 
  *         *Delimitadores intervalos,                *
  *         *Intervalos con al menos una raíz         *
  *         *Raíces                                   *
  *****************************************************/
  double points[TOL+1],
           I_roots[2*TOL], //mo
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
 /************************Contadores********************
  *          *Contadores para for's.                   * 
  *          *Contador de número de raíces y intervalos*
  *           con raíces.                              *
  ******************************************************/
  unsigned int j, i, 
		  m=0, I=0; 
 /*cabezera del progrma*/
// Iprimir nombre 
  for(o=2;o<=N;o+=2)
  {
   //Inicializamos los contadores a cero 
    sum=0.0; m=0; I=0;  
   /*Generamos puntos intervalos*/   
     for(j=0;j<=TOL;j++)
     {points[j]=a+(j*(b-a)/TOL);}
   /*Buscamos intervalos con almenos una raiz*/
     for(i=1;i<TOL;i++)
 	 {
		 if(polin_Legndr(o,points[i-1])*polin_Legndr(o,points[i])<0)
		 {I++; I_roots[I-1]=points[i-1];I++; I_roots[I-1]=points[i];}
     		 if(points[i]*points[i+1]==0)
           	 {
	         if(polin_Legndr(o,points[i-1])==0){m++;roots[m-1]=points[i];}
         	 if(polin_Legndr(o,points[i])==0){m++;roots[m-1]=points[i-1];}
                  }
 	 }
   /*Comprovamos número intervalos*/
     if((I)!=(2.0*o))
             {printf("\nERROR_01:No se han hallado todas las raíces del polinomio enesimo");
	     return -1;}
   /*Aplicamos Newton para obtener raízes*/
     for(j=1;j<=I;j+=2)
     {
	  x_i=(I_roots[j-1]+I_roots[j])/2.0;
	  for(i=0;i<=100;i++)
          {x_ii=metNewd(o,x_i);
           if(fabs(x_i-x_ii)<=1.0e-12){m++;roots[m-1]=x_ii ; i=101;}
	    x_i=x_ii;}
     }
    /*Comprovamos número raices*/
     if((m)!=(o))
        {printf("\nERRORR_02:No se han hallado todas las raíces del polinomio enesimo");
       return -1;}
    /*Calculamos suma final aproximada*/
     for(j=0;j<o;j++)
     {sum+=coefi_Legndr(o,roots[j])*F(roots[j]);}
     printf("\n Para [n=%2G] la aproximacion es: %.16G",o,sum);
     printf(" y cota de error: ******************* ");
     }
    printf("\n");
    return 0;
 }

/***********************DEFINITIONS*OF*FUNCTIONS********************
 *                                                                 *
 *                                                                 *
 *                                                                 *
 *                                                                 *
 *******************************************************************/
//Función que evalúa el polinomio de Legendre enésimo para x
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
//Función que evalúa la derivada del polinomio de Legendre enésimo para x
double d_polin_Legndr(double n,double x)
{
    return 1.0/(1.0-x*x)*(-n*x*polin_Legndr(n,x)+n*polin_Legndr(n-1.0,x));
}

//Función que calcula los coeficientes de P(x) de Legendre.
  double coefi_Legndr(double n,double ro)
{
	double a= (2.0)/((1-ro*ro)*(d_polin_Legndr(n,ro)*d_polin_Legndr(n,ro))) ;
	return a;
}
//Función que implementan el algoritmo del Método de Newton en precisión doble.
double metNewd(double n, double x)
{
    return x-(polin_Legndr(n,x))/(d_polin_Legndr(n,x));
}

