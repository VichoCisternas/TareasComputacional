#!/usr/bin/awk -f

BEGIN{

	#Definicion de variables
	dia=27;
	sum_lat=0;
	sum_long=0;
	sum_int=0;
	sum_prof=0;
	int_max=0;
	int_min=10;
	n_ev=0;
	int_desv=0;
	int_desv_aux=0;
	int_prom = 0;
	sum_int_cuadrada =0;
	int_cuadrada_prom = 0;
	mes = 2;
	ano = 2010;
	i=1;
	aux=1;

	printf ("dia/mes/aÃ±o \tint \tdesv \tmin \tmax \tevents \tlat \tlong \tprof\n");

}


($1 == dia){

# Para cada dia similar al anterior las variables se actualizan y se comprueba por minimo o maximo

	sum_int = sum_int + $10;
	sum_int_cuadrada = sum_int_cuadrada + ($10)^2;
	sum_lat = sum_lat + $7;
	sum_long = sum_long + $8; 
	sum_prof = sum_prof + $9;
	n_ev = n_ev + 1;
	array[i] = $10;

	if ($10 > int_max) int_max = $10;
	if ($10 < int_min) int_min = $10;
}

($1 != dia){

#Para cada dia distinto se calculan los valores finales correspondientes al dia anterior.
#El calculo de la desviacion estandar es el primero y hace uso del array con los valores de intensidad guardados.
        int_prom = sum_int/n_ev;
	int_cuadrada_prom = sum_int_cuadrada/n_ev;
	int_desv = int_cuadrada_prom - int_prom^2;

#	for (x = 1; x <= n_ev; x++)
#	{
#	aux=(array[x] - int_prom);
#	aux = aux^2;
#	aux_sum = aux_sum + aux;
#	}
#	aux_sum = aux_sum/n_ev;
#	int_desv = sqrt(aux_sum);
#	aux_sum = 0;

# Calculo del resto de los valores promedio.

        lat_prom = sum_lat/n_ev;
        long_prom = sum_long/n_ev;
        prof_prom = sum_prof/n_ev;

# Impresion de valores.

        printf("%02i/%02i/%i ", dia, mes, 2010);
	printf("\t%02.3f \t%02.1f", int_prom, int_desv);
	printf("\t%02.1f \t%02.1f \t%02.0f", int_min, int_max, n_ev);
	printf("\t%02.2f \t%02.2f \t%02.2f\n", lat_prom, long_prom, prof_prom);


# Variables se reinician para el nuevo dia.

        n_ev = 1;
        dia = $1;
        mes = $2;
        ano = $3;
        sum_int = $10;
        sum_int_cuadrada = ($10)^2;
        sum_lat = $7;
        sum_long = $8;
        sum_prof = $9;
        int_max = 0;
        int_min = 10;
	array[i]=$10;
	i=1;

#Comprobaion de minimo y maximo

        if ($10 > int_max) int_max = $10;
        if ($10 < int_min) int_min = $10;


}



END{

# Se debe realizar un proceso mas de cambio de dia al final para no perder la data del ultimo dia.

        int_prom = sum_int/n_ev;
        int_cuadrada_prom = sum_int_cuadrada/n_ev;
        int_desv = int_cuadrada_prom - int_prom^2;



        lat_prom = sum_lat/n_ev;
        long_prom = sum_long/n_ev;
        prof_prom = sum_prof/n_ev;

	printf("%02i/%02i/%i ", dia, mes, 2010);
        printf("\t%02.3f \t%02.1f", int_prom, int_desv);
        printf("\t%02.1f \t%02.1f \t%02.0f", int_min, int_max, n_ev);
        printf("\t%02.2f \t%02.2f \t%02.2f\n", lat_prom, long_prom, prof_prom);


}
