#!/bin/bash

count=0

echo 'Здравствуйте! Вы запустили модуль ИИ, контролирующий все двери комплекса.'
echo 'Загрузка необходимых файлов с данными...'
if [ -d "door_managment_files" ]; then
  cd door_managment_files
  echo
  echo
  echo '-------------------------------------' 
  echo 'Загрузка файлов конфигурации дверей...'
  echo
  if [ -d "door_configuration" ]; then
    cd door_configuration
    for file in `find . -maxdepth 1 -type f -name "*.conf"`
    do
      wc -l $file;
      stat -c %s $file;
      cat $file;
      count=$[ $count + 1 ]
    done
    cd ..
  else
    echo "door_configuration: No such file or directory"
  fi

  echo
  echo
  echo '-------------------------------------' 
  echo 'Загрузка карты дверей...'
  echo
  if [ -d "door_map" ]; then
    cd door_map
    cat door_map_1.1
    if [ $? -eq 0 ]; then
      count=$[ $count + 1 ]
    fi
    cd ..
  else
    echo "door_map: No such file or directory"
  fi

  echo
  echo  
  echo '-------------------------------------' 
  echo 'Чтение логов дверей...'
  echo
  if [ -d "door_logs" ]; then
    cd door_logs
    for file in `find . -maxdepth 1 -type f -name "*.log"`
    do
      wc -l $file;
      stat -c %s $file;
      cat $file;
      count=$[ $count + 1 ]
    done
    cd ..
  else
    echo "door_logs: No such file or directory"
  fi

  cd ..
else
  echo "door_managment_files: No such file or directory"
fi

echo
if [ $count -eq 34 ]; then
  ./ai_door_control.sh &
else
  echo "Ошибка загрузки данных... Протокол ИИ прерван."
fi