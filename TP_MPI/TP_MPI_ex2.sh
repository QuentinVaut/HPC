#!/bin/sh
NB_THREAD=10
STEP=0.000001
DAT_FILE=ex2.dat
OUT_FILE=./TP_MPI_ex2d.out
EPS_FILE=ex2_scalability.eps

if [ -f $DAT_FILE ]
then
    rm $DAT_FILE
fi

for i in `seq $NB_THREAD`
do
    echo "calcul avec $i threads..."
    mpirun -n $i $OUT_FILE $STEP  >> $DAT_FILE
done

echo "generation et affichage des resultats..."
T1=`head -n 1 $DAT_FILE | awk '{print $3}'`
gnuplot -e "set out '$EPS_FILE'; set terminal postscript; set yrange [0:20]; set style data linespoints; plot '$DAT_FILE' using 1:1, '$DAT_FILE' using 1:($T1/\$3)"

