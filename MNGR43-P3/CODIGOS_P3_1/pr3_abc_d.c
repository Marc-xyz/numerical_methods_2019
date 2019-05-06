/*
  Compilar con  nivel de optimización 3  
  gcc -g -Wall -O3 -o pr3_abc_d pr3_abc_d.c -lm
  Compilar con  sintaxis standard ANSI C del 1990
  gcc -g -Wall -pedantic -o pr3_abc_d pr3_abc_d.c -lm
*/

// Librerías 
#include<stdio.h>
#include<math.h>

//(02)Función cabecera
void cabecera(void);

//(03) Función error
void error(void);

//(04) Función para calcular las diferencias divididas de Newton.
int Dif_Div_New(unsigned int n, unsigned int apart[], double nodos[],double x_s[], double poli_coef[]);

//(05) Evaluar función del polinomio interpolador
double eval_pf(double x,unsigned int n, unsigned int apart[],double nodos[], double poli_coef[]);

//(06) Función del polinomio de soporte
int suport_pf(unsigned int i,double nodos[],unsigned int apart[], double poli_coef[]);

//(01)Función principal
int main(void)
{
    cabecera();
    unsigned int i;
    unsigned int a[7]={6,5,4,3,2,1.0}, //Valores para apartado a
                 b[7]={7,6,8,9,10,11,0}, //Valores para apartado b
                 c[7]={6,7,4,8,3,9,0}; //Valores para apartado c
    double poli_coef[12];  
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
    for(i=1;i<=5;i=i+2)
    {
    printf("\nPolinomios de grado %u, o %u+1 nodos:",i,i);
    
 //(a) Valores positivos más proximos.
   printf("\n(a) Para nodos positivos mas proximos a cero:");
        if(Dif_Div_New(i,a,nodos,x_s,poli_coef)!=0){error(); return -1;}
        printf("\n  x*= %.16G", eval_pf(0.0,i,a, nodos, poli_coef));
        if(suport_pf(i,nodos,a,poli_coef)!=0){error(); return -1;}
 //(b) Valores negativos más proximos.
   printf("\n(b) Para nodos negativos mas proximos a cero:");        
       if(Dif_Div_New(i,b, nodos,x_s,poli_coef)!=0){error(); return -1;}
       printf("\n  x*= %.16G", eval_pf(0.0,i,b, nodos, poli_coef));
       if(suport_pf(i,nodos,b,poli_coef)!=0){error(); return -1;}
 //(c) Valores simétricos más proximos.
   printf("\n(c) Para nodos simetricos mas proximos a cero:");
       if(Dif_Div_New(i,c,nodos,x_s,poli_coef)!=1);
       printf("\n  x*= %.16G", eval_pf(0.0,i,c, nodos, poli_coef));
       if(suport_pf(i,nodos,c,poli_coef)!=0){error(); return -1;}
       printf("\n");
    }
    return 0;
}

//(04) Función para calcular las diferencias divididas de Newton.
int Dif_Div_New(unsigned int n, unsigned int apart[], double nodos[],double x_s[], double poli_coef[])
{
unsigned int i=0, j=0, k=0;
double m[13][13]={{0}};
//Introducimos en la matriz los valores de los nodos y los de la función 
    for(i=1;i<=n+1;i++)
       {
        m[i][0]=nodos[apart[i-1]];
        m[i][1]=x_s[apart[i-1]];
       }
       poli_coef[0]=x_s[apart[0]];
//Generamos matriz diferencias divididas y guardamos valores de la diagonal
     for(j=2;j<=n+2;j++)
    {
        k=0;
        for(i=j;i<=n+2;i++)
        {
            m[i][j]=(m[i][j-1]-m[i-1][j-1])/(nodos[apart[i-1]]-nodos[apart[k]]);
            if(i==j)
            {
                poli_coef[j-1]=m[i][j];
            }
            k++;
           
        }
    }
    return 0;
}

//(05) Función del polinomio interpolador
double eval_pf(double x,unsigned int n,  unsigned int apart[],double nodos[], double poli_coef[])
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
            hon=hon*(x-nodos[apart[i]]);
        }
        }
        y=y+(poli_coef[j])*hon;
    }
    return y;
}

//(06) Función del polinomio de soporte
/*
 * Función para calcular el polinomio de soporte  
 * y reinicializar coeficientes  relevantes del (no necesario)
 * polinomio interpolador de Lagrange
 */ 
int suport_pf(unsigned int i,double nodos[],unsigned int apart[], double poli_coef[])
{
    unsigned int j;
    double w_x=1;
    for(j=0;j<=i;j++)
    {
        (w_x)=(w_x)*nodos[apart[j]];
        poli_coef[j]=0;
    }
        printf("  w(J_0(x*))= %.10G\n",fabs(w_x));
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
    int i, j, n=74, m=22; //potser a  de ser 22
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
                                    
