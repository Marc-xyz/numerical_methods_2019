/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr1_ab_d pr1_ab_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr1_ab_d pr1_ab_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//(02)Función cabecera
void cabecera(void);

//(03)Función error
void error(void);

//(04)Evaluar función del problema 1
double eval_f(double x);

//(05)Función para generar nodos
int gen_nodos(double n,double nodos[]);

//(06)Función para calcular las diferencias divididas de Newton.
int Dif_Div_New(double n, double nodos[], double poli_coef[]);

//(07)Evaluar función del polinomio interpolador
double eval_pf(double x,double n,double nodos[], double poli_coef[]);

//(01)Función principal
int main(void)
{
    FILE *output; 
    unsigned int i=0;
    double n, k, x_k, dif, max_dif=0;
    double poli_coef[66]={0};
    double nodos[66]={0};
    output=fopen("nodos_equi_01.dat","w");
    cabecera();
//El caso n=64 lo descatramos ya que produce una violación del accesso (segmetion fault)
    for(n=4;n<=32;n=n+0)
    {
//Generamos polinomios;
        if(gen_nodos(n,nodos)!=0){error(); return -1;};
        if(Dif_Div_New(n,nodos,poli_coef)!=0){error(); return -1;}
        printf("\n Los coeficientes de las diferencias divididas de la diagonal con %g+1 nodos son\n",n);
        for(i=0;i<=n;i++)/*Con el único fin de tener una referencia de como son los coeficientes */
        {
            printf("\n[%u]------>%.16G",i,poli_coef[i]);
        }
        printf("\n");
//Guardamos los valores para las gráficas
        fprintf(output,"# Numero de nodos n+1 =%g \n", n);
        fprintf(output,"# [k],[x_k],[f(x_k)],[P_f(x_k)],[|f(x_k)-P_f(x_k)|] \n");
        for(k=0;k<=180;k++)
        {
            x_k=-0.989+(k*0.011);
	    dif=fabs(eval_f(x_k)-eval_pf(x_k,n,nodos,poli_coef)); 
	    if(dif>=max_dif)
	    {
	      max_dif=dif; /*Guardamos valor máximo*/
	    }
            fprintf(output,"%.10G %.10G %.10G %.10G %.10G\n", k,x_k,eval_f(x_k),eval_pf(x_k,n,nodos,poli_coef),dif);
        }
        fprintf(output,"\n\n");
	printf("\n El valor maximo de |f(x_k)-P_f(x_k)| para %g+1 nodos es %g\n",n,max_dif);
        n=n*2;
    }
    fclose(output);
    return 0;
}


//(04)Función para evaluar la aplicación del problema 1
double eval_f(double x)
{
    if(( (x>=-1) && (x<=-0.7) ) || ( (0.7<x) && (x<=1.0) ) )
    {
        return -1;
    }
    if((-0.7<x) && (x<=0.7))
    {
        return 1;
    }
    else
    {
        printf("\n Valor  fuera del dominio de la funcion \n");
        return 0;
        
    }
}

//(05) Función para generar nodos equidistantes
int gen_nodos(double n,double nodos[])
{
    unsigned int j=0;
    for(j=0;j<=n;j++)
    {
        nodos[j]=-1+(j*(2.0)*(1/n));
    }
    return 0;
}

//(06) Función para calcular las diferencias divididas de Newton.
int Dif_Div_New(double n, double nodos[], double poli_coef[])
{
unsigned int i=0, j=0, k=0;
double m[66][66]={{0}};
//Introducimos en la matriz los valores de los nodos y los de la función 
    for(i=1;i<=n+1;i++)
       {
        m[i][0]=nodos[i-1];
        m[i][1]=eval_f(nodos[i-1]);
       }
       poli_coef[0]=eval_f(nodos[0]);
//Generamos matriz diferencias divididas y guardamos valores de la diagonal
    for(j=2;j<=n+1;j++)
    {
        k=0;
        for(i=j;i<=n+1;i++)
        {
            m[i][j]=(m[i][j-1]-m[i-1][j-1])/(nodos[i-1]-nodos[k]);
            if(i==j)
            {
                poli_coef[j-1]=m[i][j];
            }
            k++;
           
        }
    }
/*
// Imprimimos matriz de diferencias divididas para ver si está bien. 
    for(i=0;i<=n+1;i++)
    {
        printf("\n[");
        for(j=0;j<=n+1;j++)
        {
            printf("%.10G," , m[i][j]);
        }
        printf("]");
    }
    printf("\n");
*/
    return 0;
}

//(07)Función para evaluar el polinomio interpolador para un valor dado
double eval_pf(double x,double n,double nodos[], double poli_coef[])
{
 unsigned int i,j;
 double y=0;
 double hon=1;
    for(j=0;j<=n;j++)
    {
        hon=1;
        if(j>=1)
        {
        for(i=0;i<j;i++)
        {
            hon=hon*(x-nodos[i]);
        }
        }
        y=y+(poli_coef[j])*hon;
    }
    return y;
}

//(03) Función error
void error(void)
{
   printf( "\n ERROR: Vaya alguna cosa ha salido mal. \n Prueve de introducir de nuevo los valor porfavor.\n" );
   return ;
}

//(02) Función cabezera
/* Esta función se puede ignorar solo produce la cabecera del programa, pero es agradable. */
void cabecera(void)
{
    int i, j, n=70, m=20;
    for(j=1;j<=3;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Problema_1_[a,b]__");
                 i=(n+m-4)/4;
             }
             else
             {
                printf(".:");
             }
         }
         printf(".\n");
       }
       else
       {
         for(i=0;i<=n/2;i++)
         {
             printf(".:");
         }
         printf(".\n");
       }
    }
return ; //Por puro formalismo
}

/*
 * Algunas notas relevantes:
 * Para el caso n=4
 * >Por el programa en C: -2.66667 x^4 + 0.666667 x^2 - 5.×10^-8 x + 1
 * >Por Wolfram Alpha : -2.66667 x^4 + 2.22045×10^-16 x^3 + 0.666667 x^2 - 2.22045×10^-16 x + 1
*/
