#!/bin/bash
gcc mergeSort.c tiempo.c -o mezcla
./mezcla 100 <numeros10millones.txt > mezcla.txt
./mezcla 1000 <numeros10millones.txt >> mezcla.txt
./mezcla 5000 <numeros10millones.txt >> mezcla.txt
./mezcla 10000 <numeros10millones.txt >> mezcla.txt
./mezcla 50000 <numeros10millones.txt >> mezcla.txt 
./mezcla 100000 <numeros10millones.txt > mezcla.txt 
./mezcla 200000 <numeros10millones.txt >> mezcla.txt 
./mezcla 400000 <numeros10millones.txt >> mezcla.txt 
./mezcla 600000 <numeros10millones.txt >> mezcla.txt 
./mezcla 800000 <numeros10millones.txt >> mezcla.txt 
./mezcla 1000000 <numeros10millones.txt >> mezcla.txt 
./mezcla 2000000 <numeros10millones.txt > mezcla.txt 
./mezcla 3000000 <numeros10millones.txt >> mezcla.txt 
./mezcla 4000000 <numeros10millones.txt >> mezcla.txt 
./mezcla 5000000 <numeros10millones.txt >> mezcla.txt
./mezcla 6000000 <numeros10millones.txt >> mezcla.txt
./mezcla 7000000 <numeros10millones.txt >> mezcla.txt
./mezcla 8000000 <numeros10millones.txt >> mezcla.txt
./mezcla 9000000 <numeros10millones.txt >> mezcla.txt
./mezcla 10000000 <numeros10millones.txt > mezcla.txt
./mezcla 500000 <numeros10millones.txt >> mezcla.txt 

