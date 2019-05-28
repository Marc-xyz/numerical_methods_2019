##Integral 01

****************************DATE************************************
*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
*NOMBRE FICHERO ORIGEN:int_01_L.c                                  *
*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *
*                                                                  *
*     / 1                                                          *
*     |    -x*x                                                    *
*     |  e       dx    mediante cuadratura de Gauss-Legendre.      *
*     |                                                            *
*     / -1                                                         *
********************************************************************

 Para [n= 2] la aproximación es: 1.433062621147579
 Para [n= 4] la aproximación es: 1.493334622449539
 Para [n= 6] la aproximación es: 1.493647614150605
 Para [n= 8] la aproximación es: 1.493648264899014
 Para [n=10] la aproximación es: 1.493648265624351
 Para [n=12] la aproximación es: 1.493648265624854
 Para [n=14] la aproximación es: 1.493648265624855
 Para [n=16] la aproximación es: 1.493648265624854
 Para [n=18] la aproximación es: 1.493648265624854
 Para [n=20] la aproximación es: 1.493648265624855
 
 
****************************DATE************************************
*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
*NOMBRE FICHERO ORIGEN:int_01_C.c                                  *
*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *
*                                                                  *
*     / 1                                                          *
*     |    -x*x                                                    *
*     |  e       dx    mediante cuadratura de Gauss-Chebyshev.     *
*     |                                                            *
*     / -1                                                         *
********************************************************************

 Para [n= 2] la aproximacion es: 1.347372359753599
 Para [n= 4] la aproximacion es: 1.509544014901066
 Para [n= 6] la aproximacion es: 1.501716307252864
 Para [n= 8] la aproximacion es: 1.498269900093957
 Para [n=10] la aproximacion es: 1.496630466539133
 Para [n=12] la aproximacion es: 1.495728452515196
 Para [n=14] la aproximacion es: 1.495180653090259
 Para [n=16] la aproximacion es: 1.494823531872153
 Para [n=18] la aproximacion es: 1.494577972218071
 Para [n=20] la aproximacion es: 1.494401966092653


 ****************************DATE************************************
*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
*NOMBRE FICHERO ORIGEN:int_01_T.c                                  *
*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *
*                                                                  *
*     / 1                                                          *
*     |    -x*x                                                    *
*     |  e       dx    mediante regla de los Trapecios compuestos. *
*     |                                                            *
*     / -1                                                         *
********************************************************************


 Para [n= 4] la aproximacion es: 1.462740503657126
Una cota superior para el error esperado es: 0.083333333

 Para [n= 8] la aproximacion es: 1.485968195600762
Una cota superior para el error esperado es: 0.020833333

 Para [n=16] la aproximacion es: 1.49173122969139
Una cota superior para el error esperado es: 0.0052083333

 Para [n=32] la aproximacion es: 1.493169193576443
Una cota superior para el error esperado es: 0.0013020833

 Para [n=64] la aproximacion es: 1.493528509304588
Una cota superior para el error esperado es: 0.00032552083

 Para [n=128] la aproximacion es: 1.493618327275656
Una cota superior para el error esperado es: 8.1380208E-05

 Para [n=256] la aproximacion es: 1.493640781083235
Una cota superior para el error esperado es: 2.0345052E-05

 Para [n=512] la aproximacion es: 1.493646394492304
Una cota superior para el error esperado es: 5.086263E-06

 Para [n=1024] la aproximacion es: 1.493647797841895
Una cota superior para el error esperado es: 1.2715658E-06

 Para [n=2048] la aproximacion es: 1.493648148679122
Una cota superior para el error esperado es: 3.1789144E-07

 Para [n=4096] la aproximacion es: 1.493648236388422
Una cota superior para el error esperado es: 7.947286E-08

##Integral 02

****************************DATE************************************
*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
*NOMBRE FICHERO ORIGEN:int_02_L.c                                  *
*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *
*                                                                  *
*     / 1                                                          *
*     |     e^(-x^2)                                               *
*     | ------------- dx    mediante cuadratura de Gauss-Legendre. *
*     |  (1-x^2)^(1/3)                                             *
*     / 0                                                          *
********************************************************************

 Para [n= 2] la aproximacion es: 0.8202235964492217
 Para [n= 4] la aproximacion es: 0.8653882550375894
 Para [n= 6] la aproximacion es: 0.8745199676806141
 Para [n= 8] la aproximacion es: 0.8789653183338564
 Para [n=10] la aproximacion es: 0.881540069130857
 Para [n=12] la aproximacion es: 0.8831932589792649
 Para [n=14] la aproximacion es: 0.8843322533179921
 Para [n=16] la aproximacion es: 0.8851582034137871
 Para [n=18] la aproximacion es: 0.8857808734038876
 Para [n=20] la aproximacion es: 0.8862648225519152
 
****************************DATE************************************
*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
*NOMBRE FICHERO ORIGEN:int_02_C.c                                  *
*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *
*                                                                  *
*     / 1                                                          *
*     |     e^(-x^2)                                               *
*     | ------------- dx    mediante cuadratura de Gauss-Chebyshev.*
*     |  (1-x^2)^(1/3)                                             *
*     / 0                                                          *
********************************************************************

 Para [n= 2] la aproximación es: 0.8487913990500435
 Para [n= 4] la aproximación es: 0.9035877798072207
 Para [n= 6] la aproximación es: 0.8982364172452582
 Para [n= 8] la aproximación es: 0.8955429715534456
 Para [n=10] la aproximación es: 0.8940299048220692
 Para [n=12] la aproximación es: 0.8930783042638903
 Para [n=14] la aproximación es: 0.8924322751269118
 Para [n=16] la aproximación es: 0.8919689294577994
 Para [n=18] la aproximación es: 0.8916225846861565
 Para [n=20] la aproximación es: 0.8913552213249788

 

****************************DATE************************************
*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
*NOMBRE FICHERO ORIGEN:int_02_T.c                                  *
*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *
*                                                                  *
*            / 1                                                   *
*           |      e^(-x^2)                                        *
*           |  -------------- dx   (integral impropia)             *
*           |   (1-x^2)^(1/3)                                      *
*           / 0                                                    *
*       (por defecto) mediante regla de los Trapecios compuestos.  *
*                                                                  *
********************************************************************

 Para [n= 2] la aproximacion es: 1.408847241863596
 Para [n= 4] la aproximacion es: 1.131665186639992
 Para [n= 8] la aproximacion es: 0.997382427483424
 Para [n=16] la aproximacion es: 0.9342828019942294
 Para [n=32] la aproximacion es: 0.9056229648388634
 Para [n=64] la aproximacion es: 0.8931599011964524
 Para [n=128] la aproximacion es: 0.8880522912332446
 Para [n=256] la aproximacion es: 0.8861221825962625
 Para [n=512] la aproximacion es: 0.8854649903719338
 Para [n=1024] la aproximacion es: 0.885265567640896
 Para [n=2048] la aproximacion es: 0.8852107350625201
 Para [n=4096] la aproximacion es: 0.8851965306247532

##Integral 03

****************************DATE************************************
*FECHA ULTIMA MODIFICACIÓN:24/05/2019                              *
*NOMBRE FICHERO ORIGEN:int_03_L.c                                  *
*DESCRIPCIÓN: Programa para calcular numéricamente la integral     *
*                                                                  *
*                 ______________                                   *
*         / 1     |            |                                   *
*         |       |  64-15x^2                                      *
*         |       |  ---------    dx                               *
*         |    -_ |  64-16x^2                                      *
*         / -1                                                     *
*                      mediante cuadratura de Gauss-Legendre.      *
*                                                                  *
*                                                                  *
********************************************************************

 Para [n= 2] la aproximación es: 2.005673770264565
 Para [n= 4] la aproximación es: 2.006142613716896
 Para [n= 6] la aproximación es: 2.006145077846367
 Para [n= 8] la aproximación es: 2.006145090374654
 Para [n=10] la aproximación es: 2.006145090437824
 Para [n=12] la aproximación es: 2.006145090438141
 Para [n=14] la aproximación es: 2.006145090438144
 Para [n=16] la aproximación es: 2.006145090438143
 Para [n=18] la aproximación es: 2.006145090438143
 Para [n=20] la aproximación es: 2.006145090438144
