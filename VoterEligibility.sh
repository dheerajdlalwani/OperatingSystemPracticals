#!/bin/sh
currentDate=$(date +"%Y-%m-%d")
echo "Please enter your name: "
read -r name

echo "Please enter your birthdate in the format yyyymmdd: "
# read -r dob

dob="20010925"

is_leap_year=0

if [ ${#dob} -eq 8 ] 
then
    year=${dob:0:4}
    month=${dob:4:6}
    day=${dob:6:8}
    months_with_30_days="04 06 09 11"
    if [ $(($year%400)) == 0 ]
    then
        is_leap_year=1
    elif [ $(($year%100)) == 0 ]
    then 
        is_leap_year=0
    elif [ $(($year%4)) == 0 ]
    then
        is_leap_year=1
    
    fi


    if [ "$month" >= 1 ] || [ "$month" <= 12 ] && [ "$days" >= 1 ] || [ "$days" <= 31 ] 
    then
        if \[ \[ "$month" == 02 \] && \[ "$day" > 28 \] \] || \[ \[ "$leapyear" == 1 \] &&  \[ "$month" == 02 \] && \[ "$day" < 29 \] \]
        then
            echo "Too many days in February" 
            exit
        fi
        if [[ "$months_with_30_days" =~ $month ]] && [ "$day" -gt 30 ]
        then
            echo "Month $month cannot have more than 30 days... try again"
            exit
        fi
    else 
    echo "Date is out of range" 
    exit
    fi
else echo "Try again...expecting format as YYYYMMDD"
exit
fi

echo "year: $year  month: $month  day: $day"
