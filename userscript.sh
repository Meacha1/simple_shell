#!/bin/bash

echo "Starting script-------"

echo "cmd line parameters:"
for var in "$@"
do
	echo " $var"
done

echo "envi vars:"
echo " HOME=$SHELL"
echo " USER=meacha"

echo "end of dcript."
