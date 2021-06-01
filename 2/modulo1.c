#include "./modulos.h"
#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>

//Este modulo contiene toda la informacion que respecta a la resolucion del sistema de ecuaciones.



//Creacion espacio en la memoria.
datos *crea_obj_datos(int dim){
  datos *obj=malloc(sizeof(datos));
  
  obj->N=dim;
  obj->Const=gsl_matrix_alloc(dim,dim);
  obj->Work=gsl_vector_alloc(dim);
  obj->Pos=gsl_vector_alloc(dim);

  return obj;
}


//Funcion de llenado
void defi(datos *obj,double *a,double *b){

	  //Conversion masa a fuerza.
	for (int i=0;i<obj->N;i++){
		gsl_vector_set(obj->Work,i,9.8*b[i]);
	}

	//Llenado inicio:
	gsl_matrix_set(obj->Const,0,0,a[0]+a[1]);
	gsl_matrix_set(obj->Const,0,1,-a[1]);


	//Llenado final:
  
	gsl_matrix_set(obj->Const,(obj->N)-1,(obj->N)-2,-a[(obj->N)-1]);
	gsl_matrix_set(obj->Const,(obj->N)-1,(obj->N)-1,a[(obj->N)-1]);

 	//Llenado del resto:
	for (int i=1;i< obj->N -1;i++){
		gsl_matrix_set(obj->Const,i,i-1,-a[i]);
		gsl_matrix_set(obj->Const,i,i,a[i]+a[i+1]);
		gsl_matrix_set(obj->Const,i,i+1,-a[i+1]);
  	}
}

//Resolucion sistema de ecuaciones
datos *resolver(datos *dat){

  int i;
  gsl_permutation *p=gsl_permutation_alloc(dat->N);
  gsl_linalg_LU_decomp(dat->Const,p,&i);	
  gsl_linalg_LU_solve(dat->Const,p,dat->Work,dat->Pos);
	
  return dat;
}

//Limpieza de datos
void eliminacion(datos *dat){

	gsl_matrix_free(dat->Const);
	gsl_vector_free(dat->Work);
	gsl_vector_free(dat->Pos);
	free(dat);
}




