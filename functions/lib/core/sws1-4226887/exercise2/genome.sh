#!/bin/bash

# https://linuxconfig.org/bash-scripting-tutorial

# first arugment = filename/path
# second arugment = string for matching
# echo "$0" -> name of the script: ./genome.sh
# echo "$#" -> number of arguments supplied without $0

# Check for the right amount of arguments
if [ $# -ne 2 ]
  then
    echo -e "\nPlease call '$0 <filepath> <pattern>' to run this command! You have to provide two arguments.\n"
    exit 1
fi

# Check if file exists
if [ ! -f $1 ]
  then
    echo "Error. File does not exist."
    exit 1
fi

#You can use backticks " ` ` " or $() to execute shell commands. Often $() is easier to read.
pattern_count="$(tr --delete '\n' < $1 | grep -o $2 | wc -w)"
echo "The pattern $2 occurs ${pattern_count} times in the file $1"
exit 0
