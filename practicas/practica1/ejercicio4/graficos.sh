#!/bin/bash

gnuplot -e "set terminal png size 1300, 900 ; 
	set title 'Tiempo de ejecución - tamaño' ;
        set output 'grafico_mejor.png' ; 
	plot 'tiempos_mejor' with points pointtype 3" 

gnuplot -e "set terminal png size 1300, 900 ; 
	set title 'Tiempo de ejecución - tamaño' ;
        set output 'grafico_peor.png' ; 
	plot [0:30000]'tiempos_peor'  with points pointtype 3"  

gnuplot -e "set terminal png size 1300, 900 ; 
	set title 'Tiempo de ejecución - tamaño' ;
        set output 'grafico_ambos.png' ; 
	plot [0:30000]'tiempos_mejor', 'tiempos_peor' with points pointtype 3"  
