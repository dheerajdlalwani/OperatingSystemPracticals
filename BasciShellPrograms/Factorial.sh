echo  "Enter you number: " 
read x

counter=1
factorial=1

while [ $counter -le $x ]
do
    factorial=$((factorial*counter))
    counter=$((counter+1))
done

echo "Factorial of $x is $factorial"
