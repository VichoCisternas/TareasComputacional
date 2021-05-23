#!/bin/bash

#Toma los datos y los ordena por fecha
./ordenador.sh > datos_ord.dat

#Genera el archivo datos_finales con todo lo solicitado.
./desarrollo.awk datos_ord.dat > datos_finales.dat

#Genera el archivo datos_gnuplot con lo necesario para graficar.
./auxgnuplot.awk datos_ord.dat > datos_gnuplot.dat

#Genera el grafico en 2D.
gnuplot 'plotter'

#Genera el grafico en 3D.
gnuplot 'plotter3D'


