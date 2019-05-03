/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr3_a_d pr3_a_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr3_a_d pr3_a_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//(02)Función cabecera
void cabecera(void);

//(03) Función error
void error(void);

//(07) Función para calcular las diferencias divididas de Newton.
int Dif_Div_New(unsigned int n, double apart, double nodos[], double poli_coef[]);

//(08) Evaluar función del polinomio interpolador
double eval_pf(double x,unsigned int n,double nodos[], double poli_coef[]);

//(01)Función principal
int main(void)
{
    unsigned int n, ;
    double poli_coef[12]={0}; // mod 
    double x_s[12]={ 1.9, 2.0, 2.1, 2.2, 2.3, 2.4,
                     2.5, 2.6, 2.7, 2.8, 2.9, 3.0};
    double nodos[12]=
    {
      0.281818559374385,
      0.223890779141236,
      0.166606980331990,
      0.110362266922174,
      0.055539784445602,
      0.002507683297244,
      -0.048383776468198,
      -0.096804954397038,
      -0.142449370046012,
      -0.185036033364387,
      -0.224311545791968,
      -0.260051954901934
      };
    output=fopen("nodos.dat","w");
    cabecera();
    for(n=0;n<=3;n=2*n+1)
    {
    printf(" \n Para %g nodos:",n);
    
 //(a) Valores positivos más proximos.
    printf("(a) Para nodos positivos mas proximos a cero:");
        Dif_Div_New(2*n+1,{5,4,3,2,1,0},nodos,poli_coef);
 //(b) Valores negativos más proximos.
   printf("(b) Para nodos negativos mas proximos a cero:");        
       Dif_Div_New(2*n+1,+2,{7,8,9,10,11,12} nodos,poli_coef);
 //(c) Valores simétricos más proximos.
   printf("(c) Para nodos simétricos más proximos a cero:");
       Dif_Div_New(2*n+1,{5,6,4,7,3,9},nodos,poli_coef);
    return 0;
}

//(07) Función para calcular las diferencias divididas de Newton.
int Dif_Div_New(double n, unsigned int apart[], double nodos[], double poli_coef[])
{
unsigned int i=0, j=0, k=0;
double m[13][13]={{0}};
//Introducimos en la matriz los valores de los nodos y los de la función 
    for(i=1;i<=n+1;i++)
       {
        m[i][0]=nodos[apart[i-1]];
        m[i][1]=x_s[apart[i-1]]);
       }
       poli_coef[0]=eval_f(nodos[0]);
//Generamos matriz diferencias divididas y guardamos valores de la diagonal
    for(j=0;j<=n+2;j++)
    {
        k=0;
        for(i=j;i<=n+2;i++)
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
}
    printf("\n");
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
       //unsigned int i;
       if(Dif_Div_New(n,nodos,poli_coef)!=0){error(); return -1;}
        //printf("\n Los coeficientes de las diferencias divididas de la diagonal con %g nodos son\n",n);
        /*
        for(i=0;i<=n;i++)
        {
            printf("\n[%u]------>%.16G",i,poli_coef[i]);
        }
        */
        printf("\n");
        return 0;
    
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
    int i, j, n=74, m=14; //potser a  de ser 22
    for(j=1;j<=3;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Problema_3_[a,b,c]__");
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
