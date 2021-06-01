#!/usr/bin/awk -f



#Este codigo es similar al del ejercicio 1 pero sin imprimir el encabezado y con dos variables cambiadas.

BEGIN{

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

#	printf ("dia/mes/aÃ±o \tint \tdesv \tmin \tmax \tevents \tlat \tlong \tprof\n");

}


($1 == dia){

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

        int_prom = sum_int/n_ev;
	int_cuadrada_prom = sum_int_cuadrada/n_ev;
	int_desv = int_cuadrada_prom - int_prom^2;

#	for (x = 1; x <= n_ev; x++)
#	aux=(array[x] - int_prom);
#	aux = aux^2;
#	aux_sum = aux_sum + aux;
#
#	aux_sum = aux_sum/n_ev;
#	int_desv = sqrt(aux_sum);
#	aux_sum = 0;

#Estas dos variables son en resultado de la suma y resta de la intensidad promedio con la desviacion estandar.
#Estas son usadas para delimitar la altura de la caja pintada en el grafico.

	int_prom_min = int_prom - int_desv;
	int_prom_max = int_prom + int_desv;


        lat_prom = sum_lat/n_ev;
        long_prom = sum_long/n_ev;
        prof_prom = sum_prof/n_ev;

#La impresion de datos cambia al imprimir int_prom_min y int_prom_max.

        printf("%02i/%02i/%i ", dia, mes, 2010);
	printf("\t%02.3f \t%02.1f", int_prom_min, int_prom_max);
	printf("\t%02.1f \t%02.1f \t%02.0f", int_min, int_max, n_ev);
	printf("\t%02.2f \t%02.2f \t%02.2f\n", lat_prom, long_prom, prof_prom);


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


        if ($10 > int_max) int_max = $10;
        if ($10 < int_min) int_min = $10;


}



END{
        int_prom = sum_int/n_ev;
        int_cuadrada_prom = sum_int_cuadrada/n_ev;
        int_desv = int_cuadrada_prom - int_prom^2;

#        for (x = 1; x <= n_ev; x++)
#        aux=(array[x] - int_prom);
#        aux = aux^2;
#        aux_sum = aux_sum + aux;
#
#        aux_sum = aux_sum/n_ev;
#        int_desv = sqrt(aux_sum);
#        aux_sum = 0;

        int_prom_min = int_prom - int_desv;
        int_prom_max = int_prom + int_desv;


        lat_prom = sum_lat/n_ev;
        long_prom = sum_long/n_ev;
        prof_prom = sum_prof/n_ev;


        printf("%02i/%02i/%i ", dia, mes, 2010);
        printf("\t%02.3f \t%02.1f", int_prom_min, int_prom_max);
        printf("\t%02.1f \t%02.1f \t%02.0f", int_min, int_max, n_ev);
        printf("\t%02.2f \t%02.2f \t%02.2f\n", lat_prom, long_prom, prof_prom);





}
