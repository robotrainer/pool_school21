#!/bin/zsh

if [ -z "$1" ];then
	echo "Нет аргумента"
	exit 1
fi

if [ -f $1 ];then
	number=$( cat $1 | wc -l )
	uniqNumber=$( cat $1 | awk {'print $1'} | sort | uniq | wc -l )
	shaNumber=$( cat $1 | awk {'print $8'} | uniq | wc -l )
	echo "$number $uniqNumber $shaNumber"
else
	echo "Файл не существует!"
fi
