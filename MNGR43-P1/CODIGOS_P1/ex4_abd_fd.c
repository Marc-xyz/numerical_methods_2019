/*
  Compilar con  nivel de optimización 3 
  gcc -g -Wall -O3 -o ex4_abd_fd ex4_abd_fd.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o ex4_abd_fd ex4_abd_fd.c -lm
*/
 
// Librerías 
#include<stdio.h>
#include<math.h>
#include<time.h> //Para calcular tiempo de calculo ultimo apartado

//Declaramos funciones de interaz de texto
void cabecera(void);
void error(void);
int preg(unsigned int *u);

//Valores extraídos del enunciado
# define RF 1.6449340
# define RD 1.644934066848226
//Función principal 
int main (void)
{
    //Declaramos variables contador
    double t_ini, t_fin; 
    double timp;

    //Declaramos variables
    unsigned int  tip, u;
    float  x=0,y=0,f=0,ff=0,i;
    double z=0,t=0,d=0,dd=0,j;
    
    t_ini = clock();
    cabecera();
    if(preg(&u)!=1){error(); return -1;}
    printf("\n ¿Con que precision desea que funcione el programa? \n Escriba 1, para precision float. \n Escriba 2, para precision double. \n");
    if(!scanf(" %u",&tip))
    {  error(); return -1;}
    // case 1 : 
    if(tip==1)
    {
      printf( "\n Ha seleccionado precision float ( con 32 bits)" );
      for(i=1;i<=u;i++)
        {
            x=x+(1/(i*i));
            y=y+1/((u-i+1)*(u-i+1));
            if((unsigned int)i%2==0)
            {
                f=f-1/(i*i);
            }
            else if((unsigned int)i%2==1)
            {
                f=f+1/(i*i);
            }
            if((unsigned int) (u-i+1)%2==0)
            {
                ff=ff-1/((u-i+1)*(u-i+1));
            }
            else if((unsigned int) (u-i+1)%2==1)
            {
                ff=ff+1/((u-i+1)*(u-i+1));
            }
        }
        f=f*2;
        ff=ff*2;
      printf("\nLa suma hasta el termino %u, con formula (5), es:",u);
      printf("\nEn orden creciente %.7F, difiere en %.7F . ",x,RF-x);
      printf("\nEn orden decreciente %.7F, difiere en %.7F . \n",y,RF-y);
      printf("\nLa suma hasta el termino %u, con formula alternativa, es:",u);
      printf("\nEn orden creciente %.7F,difiere en %.7F . ",f,f-RF);
      printf("\nEn orden decrecirnte %.7F,difiere en %.7F . \n",ff,ff-RF);
    }
    // case 2:
    else if(tip==2)
    {
    printf( "\n Ha seleccionado precision double ( con 64 bits)" );
      for(j=1;j<=u;j++)
        {
            z=z+(1/(j*j));
            t=t+1/((u-j+1)*(u-j+1));
            if((unsigned int)j%2==0)
            {
                d=d-1/(j*j);
            }
            else if((unsigned int)j%2==1)
            {
                d=d+1/(j*j);
            }
            if((unsigned int) (u-j+1)%2==0)
            {
                dd=dd-1/((u-j+1)*(u-j+1));
            }
            else if((unsigned int) (u-j+1)%2==1)
            {
                dd=dd+1/((u-j+1)*(u-j+1));
            }
        }
        d=d*2;
        dd=dd*2;
      printf("\nLa suma hasta el termino %u, con formula (5), es:",u);
      printf("\nEn orden creciente %.14G, difiere en %.14G . ",z,RD-z);
      printf("\nEn orden decreciente %.14G, difiere en %.14G . \n",t,RD-t);
      printf("\nLa suma hasta el termino %u, con formula alternativa, es:",u);
      printf("\nEn orden creciente %.14G, difiere en %.14G . ",d,d-RD);
      printf("\nEn orden decrecirnte %.14G, difiere en %.14G . \n",dd,dd-RD);
   }
   else
   {
       error();
   }
   t_fin = clock();
   timp= (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
   if(timp<60)
   {
        printf("\nTiempo de calculo: %lf segundos.\n",timp);
   }
   else
   {
       printf("\nTiempo de calculo: %lf minutos.\n",timp/60);
   }
  
   return 0;
}

//Definimos funciones de interaz de texto

// Función cabezera
/* Esta función se puede ignorar solo produce la cabecera del programa, pero es agradable. */
void cabecera(void)
{
    int i, j, n=70, m=22;
    for(j=0;j<=4;j++)
    {
       if(j==2)
       {
         for(i=0;i<=n/2;i++)
         {
             if(i==(n-m)/4) /*Aquí hacemos que cuando llegue a la posición deseada imprima el texto completo y modifique el contador */
             {
                 printf("_#Ejercicio_4_|a,b,d|_");
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
int preg(unsigned int *u)
{
    printf("\n ¿Cuantos valores quiere sumar? \n Ejemplo:\n 5000 \n");
    if(!scanf("%u",u) ||u==0)
    { return -1; }
    return 1;
}
