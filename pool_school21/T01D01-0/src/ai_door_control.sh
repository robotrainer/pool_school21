#!/bin/bash

while (true) 
do
    index=$[ $index + 1 ]
    echo 'Обход!'
    echo 'Идет проверка дверей ...'
    echo 'Проверка степени закрытости двери #'$[ $index % 16 ]'. Секретный код доступа: '$[ RANDOM % $index ]'.'
    echo 'Степень закрытости: 100.00%.'
    if [ $[ RANDOM % 3 ] -eq 0 ]; then
       echo
       echo 'Дополнительная проверка.'
       echo '1...'
       echo '2...'
       sleep 1
       echo '3...'
       sleep 1
       echo '4...'
       sleep 2
       echo '5...'
       echo 'Проверка успешно завершена.'
    fi
    sleep $[ RANDOM % 10 + 1 ];
done;