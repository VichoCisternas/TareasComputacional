#include "./modulos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcion de lectura del archivo para obtener el numero de filas:
int obtener_n_lineas(char nombre_archivo[]){
  FILE *archivo = fopen(nombre_archivo,"r");
  int n_lineas=0;
  char string[1024];

  while (1){

    if (fgets(string,1024,archivo)==NULL){
      printf("\nSe leyó el archivo.\n");
      printf("El archivo tiene %d líneas.\n",n_lineas);
      break;
    }
    else{
      n_lineas+=1;
      printf("%s",string);
    }
  }

  fclose(archivo);
  return n_lineas;
}

//Funcion que lee y separa las datos del archivo en dos vectores.
void leer_vectores(double *cte_elastica,double *masas,char nombre_archivo[],int n){
  FILE *archivo = fopen(nombre_archivo,"r");
  char string[1024];
  char *token=NULL;
  double elastica;
  double masa;

 for (int i=0;i<n;i++){

   
   fgets(string,1024,archivo);
   token=strtok(string," ");
   elastica=atof(token);   
   token=strtok(NULL," ");
   masa=atof(token);
   cte_elastica[i]=elastica;
   masas[i]=masa;
   
  }

 fclose(archivo);
}
