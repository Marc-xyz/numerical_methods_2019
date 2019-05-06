 /*
  Compilar con  nivel de optimización 3 
  gcc -g -Wall -O3 -o ex2_b_fd ex2_b_fd.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o ex2_b_fd ex2_b_fd.c -lm
*/
 
// Librerías 
#include<stdio.h>
#include<math.h>

//Declaramos funciones de interaz de texto
void cabecera(void);
void error(void);
int preg(double *ad,double *bd, double *cd);

//Función principal 
int main (void)
{
    //Declaramos variables
    unsigned int  tip;
    float  xp,xm,af,bf,cf;
    double zp,zm,ad,bd,cd;
    
    cabecera();
    preg(&ad,&bd,&cd);
    printf("\n ¿Con que precision desea que funcione el programa? \n Escriba 1, para precision float. \n Escriba 2, para precision double. \n");
    if(!scanf(" %u",&tip))
    {  error(); return -1;}
    // case 1 : 
    if(tip==1)
    {
      printf( "\n Ha seleccionado precision float ( con 32 bits)" );
      /* cambiamos tipo perdiendo decimales a propósito
      se pierde precisión intencionadamente */
      af= (float) ad;
      bf= (float) bd;
      cf= (float) cd;
      if(bf*bf-4*af*cf<=1e-7)
      {error(); printf("\n Quizas la ecuacion no tiene soluciones reales");}
      xp=(2*cf/(-bf-sqrtf(bf*bf-4*af*cf))); //Usamos sqrtf()
      xm=(-bf-sqrtf(bf*bf-4*af*cf))/(2*af);
      printf( "\n Las soluciones obtenidas a la equacion %0.7F*x^2+%0.7F*x+%0.7F=0",af,bf,cf);
      printf("\n Son: \n x_+=%.7F  i  \n x_-=%.7F \n",xp,xm);
    }
    // case 2:
    else if(tip==2)
    {
      if(bd*bd-4*ad*cd<=1e-7)
      {error(); printf("\n Quizas la ecuacion no tiene soluciones reales");}
      zp=(2*cd/(-bd-sqrt(bd*bd-4*ad*cd)));
      zm=(-bd-sqrt(bd*bd-4*ad*cd))/(2*ad);
      printf( "\n Las soluciones obtenidas a la equacion %0.14G*x^2+%0.14G*x+%0.16G=0",ad,bd,cd);
      printf("\n Son: \n x_+=%.14G  i  \n x_-=%.14G \n",zp,zm);
      }
   else
   {
       error();
   }
    return 0;
}

//Definimos funciones de interaz de texto

// Función cabezera
/* Esta función se puede ignorar solo produce la cabecera del programa, pero es agradable. */
void cabecera(void)
{
    int i, j, n=70, m=18;
    for(j=0;j<=4;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Ejercicio_2_|b|_");
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

// Función error
void error(void)
{
   printf( "\n ERROR: Vaya alguna cosa ha salido mal. \n Prueve de introducir de nuevo los valor porfavor.\n" );
   return ;
}

// Función preguntar
int preg(double *ad,double *bd, double *cd)
{
    printf("\n Considere la ecuacion a*x^2+b*x+c=0  ¿Que valores de los coeficientes reales a, b y c? \n Ejemplo: \n a=2 \n b=-3 \n c=4 \n 2*x^2-3*x+4=0 \n");
    printf("\na= ");
    if(!scanf(" %lf",ad))
    {error(); return -1;}
    printf("\nb= ");
    if(!scanf(" %lf",bd))
    {error(); return -1;}
    printf("\nc= ");
    if(!scanf(" %lf",cd))
    {error(); return -1;}
    return 1;
}
