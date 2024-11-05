#!/bin/bash

# Проверяем, что переданы все необходимые аргументы
if [ "$#" -ne 4 ]; then
    echo "Usage: $0 <file_path> <search_string> <replace_string> <log_file>"
    exit 1
fi

file_path=$1
search_string=$2
replace_string=$3
log_file=$4

# Проверяем существование файла
if [ ! -f "$file_path" ]; then
    echo "Error: File '$file_path' not found."
    exit 1
fi

# Выполняем замену подстроки в файле
sed -i "s/$search_string/$replace_string/g" "$file_path"

# Получаем размер файла
file_size=$(stat -c %s "$file_path")

# Вычисляем хэш файла (SHA-256)
file_hash=$(sha256sum "$file_path" | cut -d ' ' -f 1)

# Получаем текущую дату и время
current_datetime=$(date "+%Y-%m-%d %H:%M:%S")

# Добавляем запись в файл журнала
echo "$file_path $file_size $current_datetime $file_hash SHA-256" >> "$log_file"

echo "Replacement completed successfully."
