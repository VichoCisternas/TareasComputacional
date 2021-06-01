#include "./modulos.h"
#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>

int main(int argc, char *argv[])
{
//Intento de CLI para comprocaion de datos
	
	//char *ruta_datos_salida;
	//char *ruta_datos_entrada;
	//char *ruta_imagen_salida;
	//int comportamiento = cli(argc,argv);

	//char nombre_archivo[]=argv[2];
	//strcpy(nombre_archivo,argv[2]);
  
//Abrir y leer el archvio, almacenando las variables en dos vectores.

	char nombre_archivo[]="Datos.txt";
  
	int dim=obtener_n_lineas(nombre_archivo);
 	double elasticas[dim];
 	double masas[dim];
 	leer_vectores(elasticas,masas,nombre_archivo,dim);
  
	double Res[dim];
	
//La variable guardado debe tener el valor 0 para mostrar los graficos por pantalla y 1 para que estos se guarden.

 	int guardado = 1;
 	
	for (int i=0;i<dim;++i){
		printf("%f %f\n",elasticas[i],masas[i]);
	}

//Usar as funciones presentes en los modulos para crear el espacio en la memoria y resolver el sistema de ecuaciones.  
  
	datos*obj_datos;
	obj_datos=crea_obj_datos(dim);  
  	defi(obj_datos,elasticas,masas);
  	resolver(obj_datos);
	
//Transformacion del objeto resultante en un vector e impresion de esta para su manipulacion mas tardia.
	
	for (int i = 0; i < dim; ++i) {
   		 Res[i]=gsl_vector_get(obj_datos->Pos,i);
   		 printf("El estiramiento del resorte %d es %lf\n",i,Res[i]);
  	}
	
//Obtencion de estadisticas e impresion de ellas.

	max(Res,dim);
	min(Res,dim);
	prom(Res,dim);
	desviacion(Res,dim);

//Creacion del histograma e impresion/guardado

	histograma(Res,dim,guardado);

//Eliminacion de la memoria

	eliminacion(obj_datos);


	return 0;
}
