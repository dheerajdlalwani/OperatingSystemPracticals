#!/bin/sh

echo "Please enter your age: "

read age

if [ $age -lt 18 ]
then
    echo "Not eligible to vote"
else
    echo "Eligible to vote"
fi