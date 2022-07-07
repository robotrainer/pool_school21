#!/bin/bash


$index 
while IFS= read -r line
do
  index=$[ $index + 1 ]
  if [ "$index" = "$line" ]; then
    echo 'ЗАГРУЗКА ПОДМОДУЛЯ '"$line"' ПРОШЛА УСПЕШНО'
  else
    echo 'ОШИБКА!ОШИБКА!ОШИБКА!ОШИБКА! Произошла ошибка при загрузке подмодуля '"$index"
    exit 1
  fi
done <  important_data_for_ai_module_2.txt
if [ "$index" = 5 ];then
  echo 'ЗАГРУЗКА ПОДМОДУЛЕЙ '"$line"' ПРОШЛА УСПЕШНО'
else
  echo 'ОШИБКА!ОШИБКА!ОШИБКА!ОШИБКА! Не хватает нескольких модулей ... '"$index"
  exit 1
fi

echo 'МОДУЛЬ 2 успешно загружен!'
exit 0
