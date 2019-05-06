/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o ex3_a_fd ex3_a_fd.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o ex3_a_fd ex3_a_fd.c -lm
*/
 
// Librerías 
#include<stdio.h>
#include<math.h>
#include<stdlib.h> //(Aquí está la función malloc)

//Declaramos funciones de interaz de texto
void cabecera(void);
void error(void);
int preg(float *nf, double *nd, char *nombre);

//Función principal 
int main (void)
{
    //Declaramos variables
    unsigned int  tip,fs;
    float  *v, sum1f=0.0, sum2f=0.0, sum3f=0.0, sum4f=0.0, i,nf;
    double *w, sum1d=0.0, sum2d=0.0, sum3d=0.0, sum4d=0.0, j,nd;
    char nombre[50];
    FILE *input;
    cabecera();
    //input
    preg(&nf,&nd,nombre);
    printf("%lf",nd);
    printf("\n ¿Con que precision desea que funcione el programa? \n Escriba 1, para precision float. \n Escriba 2, para precision double. \n");
    if(!scanf(" %u",&tip))
    {  error();  printf("\n No se ha detectado correctamente la precision deseada\n"); return -1;}
    // case 1 : 
    if(tip==1)
    {
      printf( "\n Ha seleccionado precision float ( con 32 bits)" );
      input=fopen(nombre, "r");
      if(input== NULL) // Por si no se detecta bien en el  código 
      {
        error();
        printf("\n No se ha detectado correctamente el fichero  \n");
      }
      //Aquí leemos los vectores
      v=(float*)malloc((unsigned int) nf*sizeof(float));
      for(i=1;i<=nd;i++)
      {
          if(fscanf(input,"%f\n", &v[(unsigned int) i-1])!=1)
          {error(); 
          printf("\n No se ha detectado correctamente un vector \n");
          return -1;}
          if(i<=100)
          {
          printf(" \n Valor %G leido como: %.7G",i,v[(unsigned int) i-1]);
          }
          else if( (int) i==101)
          {
              printf("\nMas de 100 valores leeidos, %1.G",nf);
          }
      }
      fclose(input);
      //Aquí hacemos cálculos
      for(i=1;i<=nf;i++)
      {
        sum1f=sum1f+v[(unsigned int) i-1];
      }
      sum3f=sum1f; //Guardamos este calculo
      sum1f=(1/nf)*sum1f;
      for(i=1;i<=nf;i++)
       {
         sum2f=sum2f+(v[(unsigned int) i-1]-sum1f)*(v[(unsigned int) i-1]-sum1f);
       }
       sum2f=(1/(nf-1))*sum2f;
      for(i=1;i<=nf;i++)
      {
        sum4f=sum4f+v[(unsigned int) i-1]*v[(unsigned int) i-1];
      }
      sum4f=(1/(nf-1))*(sum4f-(1/nf)*sum3f*sum3f);
      printf( "\n El resultado obtenido para las formulas (3) y (4) ,respectivamente, es: \n s_(%G)=sqrtf(%.7F)=%.7F \n s_(%G)=sqrtf(%.7F)=%.7F \n",nf,sum2f,sqrtf(sum2f),nf,sum4f,sqrtf(sum4f));
      free(v); //liberamos espacio de v
      }
    // case 2:
    else if(tip==2)
    {
      printf( "\n Ha seleccionado precision double ( con 64 bits)" );
      input=fopen(nombre,"r");
      //Aquí leemos los vectores
      w=(double*)malloc((unsigned int) nd*sizeof(double));
      for(j=1;j<=nd;j++)
      {
          fs=fscanf(input,"%lf \n",&w[(unsigned int) j-1]);
          if(fs!=1){error(); return -1;}
          if(j<=100)
          {
          printf(" \n Valor %G leido como: %.14G",j,w[(unsigned int) j-1]);
          }
          else if((int) j==101)
          {
              printf("\nMas de 100 valores leeidos, %1.G",nd);
          }
      }
      fclose(input);
      ///Aquí hacemos calculos ( invertido orden despues)
      for(j=1;j<=nd;j++)
      {
        sum1d=sum1d+w[(unsigned int) j-1];
      }
      sum3d=sum1d; //Guardamos este calculo
      sum1d=(1/nd)*sum1d;
      for(j=1;j<=nd;j++)
       {
         sum2d=sum2d+(w[(unsigned int) j-1]-sum1d)*(w[(unsigned int) j-1]-sum1d);
       }
       sum2d=(1/(nd-1))*sum2d;
      for(j=1;j<=nd;j++)
      {
        sum4d=sum4d+(w[(unsigned int) j-1]*w[(unsigned int) j-1]);
      }
      sum4d=(1/(nd-1))*(sum4d-(1/nd)*sum3d*sum3d);
     printf( "\n El resultado obtenido para las formulas (3) y (4) ,respectivamente, es: \n s_(%G)=sqrtf(%.14G)=%.14G \n s_(%G)=sqrtf(%.14G)=%.14G \n",nd,sum2d,sqrt(sum2d),nd,sum4d,sqrt(sum4d));
     free(w); //liberamos espacio de w
   }
   else
   {
       error(); return -1;
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
                 printf("_#Ejercicio_3_|a|_");
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
int preg(float *nf, double *nd, char *nombre)
{
    printf("\n Introduzca el nombre del fichero.txt del cual quiere que se lean los vectores. \n*Nota_1: Suponemos que las componentes del vector no estan separadas por comas. \n*Nota_2: Suponemos que las componentes del vector estan en una columna de datos \n*Nota_3: El archivo debe tener nombre con caracteres standars. \n*Nota_4: El archivo no debe ser muy largo y debe incluir la extensión del archivo \nEjemplo: vector_b.txt \n"
    );
    if(!scanf("%s",nombre))
    { error(); return -1;}
    printf("%s", nombre);
    printf("\n Introduzca el numero de  vectores a considerar \n");
    if(!scanf("%lf",nd))
    { error(); return -1;}
    (*nf)= (float)(*nd);
    //Aquí pasamos de double a float que si podemos.
    // Aunque reciproco fatal
    return 0;
}
