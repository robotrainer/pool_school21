#!/bin/bash

echo "Укажите относительный путь до файла"
read path

if [ "$path" == "" ];then 
	echo "Вы ввели пустую строку!"
	exit 1
fi

echo "Укажите строку, которую нужно заменить"
read search_string

if [ "$search_string" == "" ];then 
	echo "Вы ввели пустую строку!"
	exit 1
fi

echo "Укажите строку, которую хотите вставить"
read replace_string

algoritm=256

if [ -e "$path" ]
then
	sed -i '' "s/$search_string/$replace_string/g" $path
	( echo "src/$path - $( ls -l $path | awk '{ print $5}' ) - $( date +%F' '%R ) - $( shasum -a $algoritm $path | awk '{ print $1 }' ) - sha$algoritm" ) >> files.log
	echo "Ok!"
else
	echo "Такого файла нет!"
fi
