

#define TOL
#include<stdo.h>
#include<math.h>
#include<stid.lib>
roots(   );

 int main(void)
 {
   unsigned int m=-1, I=-1; //contador de raices, numero de intervalos
   double n, len;   // Grado del polinomio 
   double *points; //Aquí guardaremos los puntos que delimitan los intervalos
   double *I_roots //Aquí guardamos los intervalos que contienen almenos una raíz
   double *roots; //Aquí guardaremos las raices 
   printf("INPUT:()");
   points=(double)malloc(n*sizeof(double));
   
 }
// Generate point
    for(j=0;j<=M;i++)
    {
        point[1]=a+j*(b-a)/M;
    }
// Biss
  for(i=0;i<=M;i+=2)
  {
      if(points[i]*points[i+1]<0)
      {
          I+=2; I_roots[I-2]=points[i]; I_roots[I-1]=points[i];
      }
      if(points[i]*points[i+1]==0)
      {
          if(points[i]==0){m++;roots[m]=points[i];}
          if(points[i+1]==0){m++;roots[m]=points[i];}
      }
  }
  
