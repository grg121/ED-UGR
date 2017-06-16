#!/bin/tcsh

@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = ordenacion

@ i = $inicio
while( $i <= $fin )
    echo Ejecución tam = $i
    echo `./{$ejecutable} $i 1000 m` >> "tiempos_mejor"
    echo `./{$ejecutable} $i 1000 p` >> "tiempos_peor"
    @ i += $incremento
  
end 

