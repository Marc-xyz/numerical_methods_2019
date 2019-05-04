/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr1_a_fd pr1_a_fd.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr1_a_fd pr1_a_fd.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//Función cabecera
void cabecera(void);

//Función principal
int main(void)
{
    cabecera();
    unsigned int i=0, j=0;
    double x[4]={0,0,1,3};
    double v[4]={0,1,3,2};
    double m[4][4]={0};
    //valores iniciales
    for(j=0;j<=3;j++)
       {
        m[j][0]=x[j];
        m[j][1]=v[j];
       }
    //generamos vvalores
    for(j=2;j<=3;j++)
    {
        for(i=j;i<=3;i++)
        {
            m[i][j]=(m[i][j-1]-m[i-1][j-1])/(m[i][0]-m[(i-1)][0]);
            if((i-j)==0 && i==3)
            {
                 m[i][j]=(m[i][j-1]-m[i-1][j-1])/(m[i][0]-m[0][0]);
            }
        }
    }
    //Imprimimos matriz de diferencias divididas
    for(i=0;i<=3;i++)
    {
        printf("\n[");
        for(j=0;j<=3;j++)
        {
            printf("%.10G," , m[i][j]);
        }
        printf("]");
    }
    printf("\n");
    return 0;
}

// Función cabezera
/* Esta función se puede ignorar solo produce la cabecera del programa, pero es agradable. */
void cabecera(void)
{
    int i, j, n=70, m=18;
    for(j=1;j<=3;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Problema_1_[a]__");
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
