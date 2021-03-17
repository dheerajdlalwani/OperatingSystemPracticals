#!/bin/sh

echo "========== Program to check username and password =========="

authenticate()
{
    uname=$1
    pwd=$2
    if [[ "$uname" == "MasterX" ]]
    then
        if [[ "$pwd" == "EasyPassword" ]]
    	then
        	echo "Username and password is valid"
    	else
        	echo "Password is not valid"
    	fi
    else 
        echo "Username is not valid"
    fi
}

echo "Enter Username: "
read username

echo "Enter password: "
read password

authenticate "$username" "$password"
