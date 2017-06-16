#!/bin/tcsh

@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = ordenacion
set salida = tiempos_burbuja

@ i = $inicio
echo > $salida
while( $i <= $fin )
    echo Ejecución tam = $i
    echo `./{$ejecutable} $i 1000` >> $salida
    @ i += $incremento
  
end 

