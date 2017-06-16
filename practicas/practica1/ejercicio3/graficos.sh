#!/bin/bash

gnuplot -e "set terminal png size 1300, 900 ; 
	set title 'Tiempo de ejecución - tamaño' ;
        set output 'grafico1.png' ; plot 'tiempos' with points pointtype 3" 

gnuplot -e "set terminal png size 1300, 900 ; 
	set title 'Tiempo de ejecución - tamaño' ;
	f(x) = a*log(x)/log(2) ; 
	fit f(x) 'tiempos' via a ; 
        set output 'grafico2.png' ; plot 'tiempos', f(x) with points pointtype 3" 

