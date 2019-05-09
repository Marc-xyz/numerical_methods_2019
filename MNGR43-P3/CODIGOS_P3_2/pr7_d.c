/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr7_d pr7_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr7_d pr7_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//(02)Función cabecera
void cabecera(void);

//(03)Función error
void error(void);

//(01)Función principal
int main(void)
{
   unsigned int j;
    double h=84.0/15.0;
    double list[16]={0,37.2,40.2,44.4,40.8,44.1,39.9,36.3,
                  32.7,29.7,25.5,23.4,26.7,31.2,34.8,36.9}; 
    /*numero par de intervalos NI , en la primera posición se guarda la longitud final.*/
    cabecera();
    for(j=2;j<15;j++)
    {
        if(j%2==0)
        {
            list[0]=list[0]+(4.0)*list[j]; //Ai=4
        }
        if(j%2==1)
        {
            list[0]=list[0]+(2.0)*list[j]; //Ai=2
        }
        
    }
    list[0]=(h/3.0)*(list[0]+list[1]+list[15]);
    printf("\nLa pista tiene una Longitud aproximada de %.8G metros\n",list[0]);
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
    int i, j, n=70, m=18;
    for(j=1;j<=3;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("__#Problema__[7]__");
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
