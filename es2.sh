#!/bin/bash

N=$1
M=$2

if [ $# -eq 2 ] && [$M < 32767]; then
  echo "Inserire almeno due numeri, N e m" 1>&2
else
  for (( i=0; i<$N; i++ )); do
    echo $(($RANDOM % $M))
   done
fi
