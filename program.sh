#!/bin/bash
echo "What do you want to do?"
echo "1. Input into diary"
echo "2. Read Diary"
read -n 1 -p "Enter corresponding Option (1 or 2): " option
if [ $option = '1']; then
    bash src/diary
elif [ $option = '2']; then
    bash src/read
else
    echo "You didn't input a valid option. Exiting the program"