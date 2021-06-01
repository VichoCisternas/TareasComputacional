#include "./modulos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>


//Funcion calculo e impresion estiramiento maximo

int max( double x[], int N){
	double max=0.0;
  	for (int i=0;i<N;i++){
    		if (max<x[i]){
      			max=x[i];
    		}
  	}
	printf("El estiramiento maximo es %f \n",max);
	return max;
}

//Funcion calculo e impresion estiramiento minimo
int min(double x[], int N){
	double min=11110;
	for (int i=0;i<N;i++){
    		if (min>x[i]){
      			min=x[i];
    		}
  	}
	printf("El estiramiento minimo es %f \n",min);
	return min;
}

//Funcion calculo e impresion estiramiento promedio
void prom(double x[], int N){
	double prom=0;
	for (int i=0;i<N;i++){
    		prom=prom+x[i];
  	}
	prom=prom/N;
	printf("El promedio de los estiramientos es %f \n",prom);
}

//Funcion calculo e impresion desviacion estandar
void desviacion(double x[], int N){
  	double prom=0;
  	double prom_cuadrado=0;
  	double desv=0;
  	for (int i=0;i<N;i++){
    		prom=prom+x[i];
    		prom_cuadrado=prom_cuadrado + (x[i] * x[i]);
  	}
  	prom = prom/N;
  	prom = prom*prom;
  	prom_cuadrado = prom_cuadrado/N;
  	desv = prom_cuadrado - prom;
  	desv = sqrt(2);
  	//desv = sqrt(desv);
  	printf("La varianza de los datos es %f \n",desv);
  
}

//Funcion calculo e impresion histograma
void histograma(double x[], int N, int guardado){

  	FILE *grafico;
  	FILE *grafico2;
//Funcion que define si el archivo sera guardado como .eps o mostrado por pantalla.
	if (guardado){
    		grafico = popen("gnuplot", "w");
    		fprintf(grafico, "set terminal eps\n");
    		fprintf(grafico, "set output 'Histograma.eps' \n");
    		
    		grafico2 = popen("gnuplot", "w");
    		fprintf(grafico2, "set terminal eps\n");
    		fprintf(grafico2, "set output 'Histograma2.eps' \n");
  	}else{  
    		grafico = popen("gnuplot -p", "w");
    		grafico2 = popen("gnuplot -p", "w");
  	}
  	
//Procesa el primer grafico (Color Celeste) este representa el estiramiento del resorte de la forma en la que se define
//en la guia y el ejercicio y es lo que yo considero la posicion del resorte mas que el estiramiento  

  	fprintf(grafico, "set title 'Histograma '\n");
  	fprintf(grafico, "set xtics 1\n");
  	fprintf(grafico, "set xlabel 'Numero de resorte'\n");
  	fprintf(grafico, "set ylabel 'Estiramiento (Posicion) (m)'\n");
  	fprintf(grafico, "set boxwidth 0.9\n");
  	fprintf(grafico, "set style fill solid\n");
  	fprintf(grafico, "plot '-' with boxes notitle fc rgbcolor 'turquoise' \n");
  	for (int i=0; i<N; ++i){
    		fprintf(grafico, "%i %lf\n", (i+1), x[i]);
  	}
  	fprintf(grafico, "e\n");
//Muestra el segundo grafico (Color morado). Este representa el estiramiento del resorte considerando la diferencia con los estiramientos previos.
//Es lo que considero como el estiramiento real del resorte
  	
  	fprintf(grafico2, "set title 'Histograma 2 '\n");
  	fprintf(grafico2, "set xtics 1\n");
  	fprintf(grafico2, "set xlabel 'Numero de resorte'\n");
  	fprintf(grafico2, "set ylabel 'Estiramiento (real) (m)'\n");
  	fprintf(grafico2, "set boxwidth 0.9\n");
  	fprintf(grafico2, "set style fill solid\n");
  	fprintf(grafico2, "plot '-' with boxes notitle fc rgbcolor 		'dark-violet' \n");
  	fprintf(grafico2, "%i %lf\n", (1), x[0]);
  	for (int i=1; i<N; ++i){
    		fprintf(grafico2, "%i %lf\n", (i+1), x[i]-x[i-1]);
  	}
  	fprintf(grafico2, "e\n");
  
  	pclose(grafico2);
}	
		  	

