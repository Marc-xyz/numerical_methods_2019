/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr2_ab_d pr2_ab_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr2_ab_d pr2_ab_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//(02)Función cabecera
void cabecera(void);

//(03) Función error
void error(void);

//(04) Evaluar función del problema 2
double eval_f(double x);

//(05) Función para generar nodos
int gen_nodos(double n,double nodos[]);

//(06) Función para generar nodos de Chebyshev
int gen_nodos_Chev(double n,double nodos[]);

//(07) Función para calcular las diferencias divididas de Newton.
int Dif_Div_New(double n, double nodos[], double poli_coef[]);

//(08) Evaluar función del polinomio interpolador
double eval_pf(double x,double n,double nodos[], double poli_coef[]);

//(09) Función crear nodos equidistantes y polinomio
int poli_interp_equi(double n, double nodos[], double poli_coef[]);

//(10) Función crear nodos de Chebyshev y polinomio
int poli_interp_chevy(double n, double nodos[], double poli_coef[]);

//(11) Función para generar datos de gráficas
int plot_dat(double n, double nodos[], double poli_coef[],FILE *output, char *tipo);

//(01)Función principal
int main(void)
{
    FILE *output, *outputt;
    double n;
    double poli_coef[33]={0};
    double nodos[33]={0};
    output=fopen("nodos_equi_02.dat","w");
    outputt=fopen("nodos_chev_02.dat","w");
    cabecera();
    for(n=4;n<=32;n=n+0)
    {
 //Con nodos equidistantes
       if(poli_interp_equi(n,nodos,poli_coef)!=0){error(); return -1;}
    //Guardamos valores para generar gráfico con gnuplot
       if(plot_dat(n,nodos,poli_coef,output,"equidistantes")!=0){error(); return -1;}
//Con nodos de Chevychev
       if(poli_interp_chevy(n,nodos,poli_coef)!=0){error(); return -1;}
    //Guardamos valores para generar gráfico con gnuplot
       if(plot_dat(n,nodos,poli_coef,outputt,"de Chebyshev")!=0){error(); return -1;}
        n=n*2;
    }
    fclose(output);
    return 0;
}


//(04) Función del problema 2
double eval_f(double x)
{
    if( (x>=-1.0) && (x<=1.0)  )
    {
      return (1.0)/(1.0+25.0*x*x);
    }
    else
    {
        printf("\n Valor fuera del dominio de la funcion \n");
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

//(06) Función para generar nodos de Chebyshev
int gen_nodos_Chev(double n,double nodos[])
{
  unsigned int j=0;
    for(j=0;j<=n;j++)
    {
        nodos[j]=cos((2.0*j+1.0)/(n+1)*((M_PI)/2));
    }
    return 0;
}

//(07) Función para calcular las diferencias divididas de Newton.
int Dif_Div_New(double n, double nodos[], double poli_coef[])
{
unsigned int i=0, j=0, k=0;
double m[66][66]={0};
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
//Imprimimos matriz de diferencias divididas para ver si está bien 
for(i=0;i<=n+1;i++)
{
        printf("\n[");
        for(j=0;j<=n+1;j++)
        {
            printf("%.10G," , m[i][j]);
        }
        printf("]");
        printf("\n");
}
*/
    return 0;
}

//(08) Función del polinomio interpolador
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
//(09) Función crear nodos y polinomio
int poli_interp_equi(double n, double nodos[], double poli_coef[])
{
       if(gen_nodos(n,nodos)!=0){error(); return -1;}
       if( Dif_Div_New(n,nodos,poli_coef)!=0){error(); return -1;}
        printf("\n");
        return 0;
    
}

//(10) Función crear nodos de Chebyshev y polinomio
int poli_interp_chevy(double n, double nodos[], double poli_coef[])
{
       if(gen_nodos_Chev(n,nodos)!=0){error(); return -1;}
       if( Dif_Div_New(n,nodos,poli_coef)!=0){error(); return -1;}
        return 0;
    
}

//(11) Función para generar gráficas
int plot_dat(double n, double nodos[], double poli_coef[], FILE *output, char *tipo)
{
    double k, x_k, dif, max_dif=0;
    fprintf(output,"# Numero de nodos n =%g+1 \n", n);  
    fprintf(output,"# [k],[x_k],[f(x_k)],[P_f(x_k)],[|f(x_k)-P_f(x_k)|] \n");
    for(k=0;k<=180;k++)
        {
        x_k=-0.989+(k*0.011);
	    dif=fabs(eval_f(x_k)-eval_pf(x_k,n,nodos,poli_coef));
	    if(dif>=max_dif)
	    {
	      max_dif=dif;
	    }
            fprintf(output,"%.10G %.10G %.10G %.10G %.10G\n", k,x_k,eval_f(x_k),eval_pf(x_k,n,nodos,poli_coef),dif);
        }
        fprintf(output,"\n\n");
        printf("El valor maximo de |f(x_k)-P_f(x_k)| para %g+1 nodos %s es %g\n",n,tipo,max_dif);
    return 0;
}

//(03) Función error
void error(void)
{
   printf( "\n ERROR: Vaya alguna cosa ha salido mal. \n Prueve de introducir de nuevo los valor por favor.\n" );
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
                 printf("_#Problema_2_[a,b]__");
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
