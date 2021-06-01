#include "./modulos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cli(int argc, char **argv){

	int comportamiento=0;


	if(argc==4){
		comportamiento =1;
	}
	if(argc==6){
		comportamiento =2;
	}
	else{
		printf("Error\n");
		comportamiento =0;
	}







}
