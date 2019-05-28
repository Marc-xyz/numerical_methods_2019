## Resultados 

# Integral 1:

     / 1                                                          
     |    -x*x                                                    
     |  e       dx          
     |                                                            
     / -1
       
 * Legendre (**int_01_L.c**):
   - Para [n= 2] la aproximacion es: 1.433062621147579  
   - Para [n= 4] la aproximacion es: 1.493334622449539  
   - Para [n= 6] la aproximacion es: 1.493647614150605  
   - Para [n= 8] la aproximacion es: 1.493648264899014  
   - Para [n=10] la aproximacion es: 1.493648265624351  
   - Para [n=12] la aproximacion es: 1.493648265624854  
   - Para [n=14] la aproximacion es: 1.493648265624855 
   - Para [n=16] la aproximacion es: 1.493648265624854  
   - Para [n=18] la aproximacion es: 1.493648265624854 
   
 * Chebyshev (**int_01_C.c**):
   - Para [n= 2] la aproximacion es: 1.347372359753599  
   - Para [n= 4] la aproximacion es: 1.509544014901066  
   - Para [n= 6] la aproximacion es: 1.501716307252864  
   - Para [n= 8] la aproximacion es: 1.498269900093957  
   - Para [n=10] la aproximacion es: 1.496630466539133 
   - Para [n=12] la aproximacion es: 1.495728452515196  
   - Para [n=14] la aproximacion es: 1.495180653090259  
   - Para [n=16] la aproximacion es: 1.494823531872153  
   - Para [n=18] la aproximacion es: 1.494577972218071  
   - Para [n=20] la aproximacion es: 1.494401966092653  
   + IGNORAR :[Forzando programa: Para [n=240] la aproximacion es: **1.4936**53518422632]

 * Trapecios (**int_01_T.c**):
   - Para [n= 4] la aproximacion es: 1.462740503657126 y cota de error: ******************* 
   - Para [n= 8] la aproximacion es: 1.485968195600762 y cota de error: ******************* 
   - Para [n=16] la aproximacion es: 1.49173122969139 y cota de error: ******************* 
   - Para [n=32] la aproximacion es: 1.493169193576443 y cota de error: ******************* 
   - Para [n=64] la aproximacion es: 1.493528509304588 y cota de error: ******************* 
   - Para [n=128] la aproximacion es: 1.493618327275656 y cota de error: ******************* 
   - Para [n=256] la aproximacion es: 1.493640781083235 y cota de error: ******************* 
   - Para [n=512] la aproximacion es: 1.493646394492304 y cota de error: ******************* 
   - Para [n=1024] la aproximacion es: 1.493647797841895 y cota de error: ******************
   + **1.49364** 

# Integral 2:

     / 1                                                         
     |     e^(-x^2)                                               
     | ------------- dx    
     |  (1-x^2)^(1/3)                                             
     / 0 
              
 * Legendre (**int_02_L.c**):
   - Para [n= 2] la aproximacion es: 0.8202235964492217  
   - Para [n= 4] la aproximacion es: 0.8653882550375894  
   - Para [n= 6] la aproximacion es: 0.8745199676806141  
   - Para [n= 8] la aproximacion es: 0.8789653183338564  
   - Para [n=10] la aproximacion es: 0.881540069130857  
   - Para [n=12] la aproximacion es: 0.8831932589792649  
   - Para [n=14] la aproximacion es: 0.8843322533179921  
   - Para [n=16] la aproximacion es: 0.8851582034137871  
   - Para [n=18] la aproximacion es: 0.8857808734038876  
   - Para [n=20] la aproximacion es: 0.8862648225519152 
   + IGNORAR : [Forzando programa: Para [n=378] la aproximacion es: **0.8895**073629489517]

 * Chebyshev (**int_02_C.c**):
   - Para [n= 2] la aproximacion es: 0.8487913990500435  
   - Para [n= 4] la aproximacion es: 0.9035877798072207  
   - Para [n= 6] la aproximacion es: 0.8982364172452582  
   - Para [n= 8] la aproximacion es: 0.8955429715534456  
   - Para [n=10] la aproximacion es: 0.8940299048220692  
   - Para [n=12] la aproximacion es: 0.8930783042638903  
   - Para [n=14] la aproximacion es: 0.8924322751269118  
   - Para [n=16] la aproximacion es: 0.8919689294577995  
   - Para [n=18] la aproximacion es: 0.8916225846861565  
   - Para [n=20] la aproximacion es: 0.8913552213249788  
   + IGNORAR: [Forzando progrma: Para [n=248] la aproximacion es: **0.889**6374857560778 ]
 
* Trapecios (**int_02_T.c**):
   - Para [n= 2] la aproximacion es: 730.6492382549997 y cota de error: ******************* 
   - Para [n= 4] la aproximacion es: 365.7522185921295 y cota de error: ******************* 
   - Para [n= 8] la aproximacion es: 183.3080938146884 y cota de error: ******************* 
   - Para [n=16] la aproximacion es: 92.09017632980731 y cota de error: ******************* 
   - Para [n=32] la aproximacion es: 46.48423886319593 y cota de error: ******************* 
   - Para [n=64] la aproximacion es: 23.68329911943744 y cota de error: ******************* 
   - Para [n=128] la aproximacion es: 12.28414650942837 y cota de error: ******************* 
   - Para [n=256] la aproximacion es: 6.585412257353974 y cota de error: ******************* 
   - Para [n=512] la aproximacion es: 3.736579431334575 y cota de error: ******************* 
   - Para [n=1024] la aproximacion es: 2.312500813819087 y cota de error: ******************
   - Para [n=2048] la aproximacion es: 1.600674682948616 y cota de error: ******************
   - Para [n=4096] la aproximacion es: 1.244896030830881 y cota de error: *******************
   
# Longitud Arco 2.0

             ______________                                                   
     / 1     |            | 
     |       |  64-15x^2                                           
     |       |  ---------    dx        
     |      \|  64-16x^2                                                  
     / -1    

  - Para [n= 2] la aproximación es: 2.005673770264565
  - Para [n= 4] la aproximación es: 2.006142613716896
  - Para [n= 6] la aproximación es: 2.006145077846367
  - Para [n= 8] la aproximación es: 2.006145090374654
  - Para [n=10] la aproximación es: 2.006145090437824
  - Para [n=12] la aproximación es: 2.006145090438141
  - Para [n=14] la aproximación es: 2.006145090438144
  - Para [n=16] la aproximación es: 2.006145090438143
  - Para [n=18] la aproximación es: 2.006145090438143

