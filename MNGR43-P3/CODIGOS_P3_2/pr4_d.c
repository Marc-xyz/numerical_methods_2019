/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr4_d pr4_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr4_d pr4_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//(02)Función cabecera
void cabecera(void);

//(03)Función error
void error(void);

//(04)Función métodos trapecios
int metTrapz(double a, double b, double NI);

//((05)Función del problema 4 (evalúa )
double f_4(double x);

//(06)Función métodos Simpson
int metSimps(double a, double b, double NI);

//(01)Función principal
int main(void)
{
    cabecera();
    if(metTrapz(0.0,1.0,4.0)!=0){error(); return -1;}
    if(metSimps(0.0,1.0,4.0)!=0){error(); return -1;}
    return 0;
}


//(04)Función métodos trapecios
int metTrapz(double a, double b, double NI)
{
    printf("\nCalculo mediante metodo compuesto de los Trapecios");    unsigned int i;
    double h, s, x;
    h=(b-a)/NI;
    for(i=1,s=0,x=a;i<NI;i++)
    {
        x=x+h;
        s=s+f_4(x);
    }
    s=s*h;
    s=s+h*(f_4(a)+f_4(b))/2.0;
    printf("\nLa integral es aproximadamente %.16G",s);
    printf("\nEl error aproximado es de %.16G\n",fabs(s-(M_PI)/4.0));
    return 0;
}

//((05)Función del problema 4 (evalúa )
double f_4(double x)
{
    return (1.0)/(1+x*x);
}

//(06)Función métodos Simpson
int metSimps(double a, double b, double NI)
{
    printf("\nCalculo mediante metodo compuesto de Simpson");    
    unsigned int i;
    double  hm, h, s, x;
    h=(b-a)/NI;
    hm=h/(2.0);
    for(i=1,s=0,x=a;i<NI;i++)
    {
        x=x+h;
        s=s+(2.0)*f_4(x)+(4.0)*f_4(x+hm);
    }
    s=s*(h/6.0);
    s=s+h*(f_4(b)+f_4(a)+(4.0)*f_4(a+hm))/(6.0);
    printf("\nLa integral es aproximadamente %.16G",s);
    printf("\nEl error aproximado es de %.16G\n",fabs(s-(M_PI)/4.0));
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
    int i, j, n=70, m=18;
    for(j=1;j<=3;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Problema___[4]__");
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
