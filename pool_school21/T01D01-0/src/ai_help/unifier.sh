#!/bin/bash

FILES=key/*
KEY=0

for file in $FILES
do
    if [[ $file =~ \.key$ ]]
    then
        tmp=$(< $file)
        KEY=$(($KEY + $tmp))
    else
        KEY=0
        break
    fi
done

if [ $KEY == 0 ]
then
    echo "Error."
else
    echo "Ok."
    echo $(($KEY*2)) > main.key
fi
