#ifndef MODULO1_H
#define MODULO1_H

#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include <string.h>

typedef struct Datos{

  int N;
  gsl_matrix *Const;
  gsl_vector *Work;
  gsl_vector *Pos;
}datos;

void cli(int argc, char **argv);


int obtener_n_lineas(char nombre_archivo[]);
void leer_vectores(double *cte_elastica,double *masas,char nombre_archivo[],int n);



datos *crea_obj_datos(int dim);
datos *resolver(datos *dat);
void defi(datos *dat,double *a,double *b);
void eliminacion(datos *dat);


int max(double x[], int N);
int min(double x[], int N);
void prom(double x[], int N);
void desviacion(double x[], int N);
void histograma(double x[], int N, int guardado);

#endif
