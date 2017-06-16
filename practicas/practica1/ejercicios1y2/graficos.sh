#!/bin/bash

gnuplot -e "set terminal png size 1300, 900 ; 
	set title 'Tiempo de ejecución - tamaño' ;
        set output 'grafico1.png' ; plot 'tiempos_burbuja' with points pointtype 3" 

gnuplot -e "set terminal png size 1300, 900 ; 
	set title 'Tiempo de ejecución - tamaño' ;
        set output 'grafico2.png' ; plot [0:30000]'tiempos_burbuja',x*x  with points pointtype 3"  

gnuplot -e "set terminal png size 1300, 900 ; 
	set output 'grafico3.png' ; 
	f(x)=a*x**2+b*x+c ; fit f(x) 'tiempos_burbuja' via a,b,c ; 
	plot 'tiempos_burbuja', f(x)" 
