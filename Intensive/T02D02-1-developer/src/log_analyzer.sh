#!/bin/bash

# Проверка наличия аргумента - пути к файлу журнала
if [ $# -ne 1 ]; then
    echo "Usage: $0 <path_to_log_file>"
    exit 1
fi

# Сохранение пути к файлу журнала из аргумента
log_file="$1"

# Проверка существования файла журнала
if [ ! -f "$log_file" ]; then
    echo "Error: Log file not found."
    exit 1
fi

# Общее количество записей в файле журнала
total_records=$(wc -l < "$log_file")

# Количество уникальных файлов
unique_files=$(awk -F '–' '{print $1}' "$log_file" | sort -u | wc -l)

# Количество изменений, вызвавших изменения в хеш-файле
changes=$(awk -F '–' '{print $5}' "$log_file" | sort -u | wc -l)

# Вывод результатов анализа
echo "$total_records $unique_files $changes"

