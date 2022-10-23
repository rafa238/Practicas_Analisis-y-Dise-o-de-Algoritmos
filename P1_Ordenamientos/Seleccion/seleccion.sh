#!/bin/bash
gcc selection.c tiempo.c -o seleccion
./seleccion 100 <numeros10millones.txt >> seleccion.txt
./seleccion 1000 <numeros10millones.txt > seleccion.txt
./seleccion 5000 <numeros10millones.txt >> seleccion.txt
./seleccion 10000 <numeros10millones.txt >> seleccion.txt
./seleccion 20000 <numeros10millones.txt >> seleccion.txt
./seleccion 30000 <numeros10millones.txt >> seleccion.txt
./seleccion 40000 <numeros10millones.txt >> seleccion.txt
./seleccion 50000 <numeros10millones.txt >> seleccion.txt
./seleccion 60000 <numeros10millones.txt >> seleccion.txt
./seleccion 70000 <numeros10millones.txt >> seleccion.txt
./seleccion 80000 <numeros10millones.txt >> seleccion.txt
./seleccion 90000 <numeros10millones.txt >> seleccion2.txt
./seleccion 100000 <numeros10millones.txt >> seleccion2.txt
./seleccion 150000 <numeros10millones.txt >> seleccion.txt
./seleccion 200000 <numeros10millones.txt >> seleccion.txt
./seleccion 250000 <numeros10millones.txt >> seleccion.txt
./seleccion 300000 <numeros10millones.txt >> seleccion.txt
./seleccion 400000 <numeros10millones.txt >> seleccion.txt
./seleccion 500000 <numeros10millones.txt >> seleccion.txt
./seleccion 600000 <numeros10millones.txt >> seleccion.txt




