#!/bin/sh
echo "========== Program to check even or odd =========="
echo "Please enter a natural number: "
read x

if [ $(($x % 2))==0 ]
then
	echo "$x is an even number."
else
	echo "$x is an odd number."
fi
