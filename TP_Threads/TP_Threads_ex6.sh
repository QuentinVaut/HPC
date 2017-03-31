#!/bin/bash

echo "calcul avec 1 thread..."
#TODO lancer les runs et recuperer les temps dans un fichier

echo "calcul avec 2 threads..."
#TODO lancer les runs et recuperer les temps dans un fichier

echo "calcul avec 4 threads..."
#TODO lancer les runs et recuperer les temps dans un fichier

echo "generation et affichage des resultats..."
#TODO faire un paste des fichiers de temps dans un fichier graph.dat
gnuplot -e "set out 'graph_time.eps'; set terminal postscript; set style data linespoints; plot 'graph.dat' using 1:3, 'graph.dat' using 1:6, 'graph.dat' using 1:9"
gnuplot -e "set out 'graph_speedup.eps'; set terminal postscript; set style data linespoints; plot 'graph.dat' using 1:(\$3/\$9), 'graph.dat' using 1:(\$3/\$6)"

