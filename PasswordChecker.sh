#!/bin/sh
authenticate()
{
    uname=$1
    pwd=$2
    if [[ "$uname" == "MasterX" ]]
    then
        if [[ "$pwd" == "[xxXxx8xxXxx]" ]]
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
