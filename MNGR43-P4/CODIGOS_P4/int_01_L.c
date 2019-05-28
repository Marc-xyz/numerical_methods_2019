/****************************DATE************************************
 *FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
 *NOMBRE FICHERO:int_01_L.c                                         *
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
                 *  gcc -g -Wall -O3 -o int_01_L int_01_L.c -lm      * 
                 *  Compilar con  sintaxis standard ANSI C del 1990  *
                 *  gcc -g -Wall -pedantic -o rut_01_L rut_01_L.c -lm*
                 * ***************************************************/

//Librerías y definiciones 
#include<stdio.h>
#include<math.h>
#define N 20 //GRADO POLINOMIO MÁXIMO
#define TOL 1000  //NÚMERO DE INTERVALOS A CONSIDERAR
#define F(x) (exp(-x*x)) //FUNCIÓN A INTEGRAR f(x):=e^(-x^2)
 


//(02)Función que implementan el algoritmo del Método de Newton en precisión doble.
 double metNewd(double n, double x);
//(03)Función que evalúa el polinomio de Legendre enésimo para x.
 double polin_Legndr(double n,double x);
//(04)Función que evalúa la derivada del polinomio de Legendre enésimo para x.
 double d_polin_Legndr(double n,double x);
//(05)Función que calcula los coeficientes de P(x) de Legendre.
 double coefi_Legndr(double n,double ro);
//(06) Función que imprime la cabecera del programa.
 void cabecera(void);


/*************************THEORETICAL COMMENTS************************************
 * Lema polinomio ortogonal --> todas raíces simples, reales, y en (a,b).        *
 * Conocemos número de soluciones y por tanto el número de intervalos (multip=1) * 
 *********************************************************************************/

//(01)Función principal
int main(void)
{
 /*********************Vectores:*********************** 
  *         *Delimitadores intervalos,                *
  *         *Intervalos con al menos una raíz         *
  *         *Raíces                                   *
  *****************************************************/
  double points[TOL+1],
         I_roots[2*N], 
	 roots[N];

 /***********************Valores:***********************
  *          *Intervalo [a,b]=[-1,1]                   *
  *          *Pivote 1 y 2                             *
  *          *Grado de P(x) en cada iteración          *
  *          *Suma \approx integral                    *                                       ******************************************************/
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
  
/*Imprimimos cabecera*/
  cabecera();
//Imprimir datos programa 
  for(o=2;o<=N;o+=2)
  {
   //Inicializamos los contadores a cero 
    sum=0.0; m=0; I=0;  
   /*Generamos puntos intervalos*/   
     for(j=0;j<=TOL;j++)
     {points[j]=a+(j*(b-a)/TOL);}
   /*Buscamos intervalos con al menos una raíz*/
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
   /*Comprobamos número intervalos*/
     if((I)!=(2.0*o))
             {printf("\nERROR_01:No se han hallado todos losintervalos de raíces del polinomio enesimo");
	     return -1;}
   /*Aplicamos Newton para obtener raíces*/
     for(j=1;j<=I;j+=2)
     {
	  x_i=(I_roots[j-1]+I_roots[j])/2.0;
	  for(i=0;i<=100;i++)
          {x_ii=metNewd(o,x_i);
           if(fabs(x_i-x_ii)<=1.0e-12){m++;roots[m-1]=x_ii ; i=101;}
	    x_i=x_ii;}
     }
    /*Comprobamos número raices*/
     if((m)!=(o))
        {printf("\nERRORR_02:No se han hallado todas las raíces del polinomio enesimo");
       return -1;}
    /*Calculamos suma final aproximada*/
     for(j=0;j<o;j++)
     {sum+=coefi_Legndr(o,roots[j])*F(roots[j]);}
     printf("\n Para [n=%2G] la aproximación es: %.16G",o,sum);
     }
    printf("\n\n");
    return 0;
 }

/***********************DEFINITIONS*OF*FUNCTIONS********************
 *          (02) double metNewd(double n, double x)                *
 *          (03) double polin_Legndr(double n,double x)            *
 *          (04) double d_polin_Legndr(double n, double x)         *
 *          (05) double coefi_Legndr(double n,double ro)           *
 *          (06) void cabecera(void)                               *
 *******************************************************************/
 //(02)Función que implementan el algoritmo del Método de Newton en precisión doble.
double metNewd(double n, double x)
{
    return x-(polin_Legndr(n,x))/(d_polin_Legndr(n,x));
}

 //(03)Función que evalúa el polinomio de Legendre enésimo para x
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
 //(04)Función que evalúa la derivada del polinomio de Legendre enésimo para x
double d_polin_Legndr(double n,double x)
{
    return 1.0/(1.0-x*x)*(-n*x*polin_Legndr(n,x)+n*polin_Legndr(n-1.0,x));
}

 //(05)Función que calcula los coeficientes de P(x) de Legendre.
  double coefi_Legndr(double n,double ro)
{
	double a= (2.0)/((1-ro*ro)*(d_polin_Legndr(n,ro)*d_polin_Legndr(n,ro))) ;
	return a;
}
//(06) Función que imprime la cabecera del programa.
void cabecera(void)
{
printf("\n****************************DATE************************************");
printf("\n*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *");
printf("\n*NOMBRE FICHERO ORIGEN:int_01_L.c                                  *");
printf("\n*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *");
printf("\n*                                                                  *");
printf("\n*     / 1                                                          *");
printf("\n*     |    -x*x                                                    *");
printf("\n*     |  e       dx    mediante cuadratura de Gauss-Legendre.      *");
printf("\n*     |                                                            *");
printf("\n*     / -1                                                         *");
printf("\n********************************************************************");
printf("\n");
return ;
}
