#!/bin/bash
#!/bin/awk -f 



archivo=$(cat datos_sismos.dat | sort -k 2n -k 1n datos_sismos.dat | tail -n +3 )
echo "$archivo"

