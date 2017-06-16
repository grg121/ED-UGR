#!/bin/tcsh

@ inicio = 100
@ fin = 30000
@ incremento = 300
set ejecutable = desc
set salida = tiempos


@ i = $inicio
echo > $salida

	while( $i <= $fin )
	    echo Ejecución tam = $i
	    echo `./{$ejecutable} $i` >> $salida
	    @ i += $incremento
	end 


