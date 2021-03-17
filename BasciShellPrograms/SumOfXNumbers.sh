#!/bin/sh
echo "Please enter n : "

read -r n
sum=0

while [ "$n" != 0 ]
do
	sum=$(( sum + n ))
	n=$(( n - 1 ))
	echo ""
done

echo "Sum of $n numbers is: $sum"
