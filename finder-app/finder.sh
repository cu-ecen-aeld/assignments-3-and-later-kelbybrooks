#!/bin/bash


filesdir=$1
searchstr=$2

if [ -z $1 ] || [ -z $2 ]
then
    echo "Values were not specified."
    exit 1
elif ! [ -d $1 ]
then
    echo "$1 is not a valid directory."
    exit 1
else
    X=$( find $1 -type f | wc -l)
    Y=$(grep -r $2 $1 | wc -l)
    echo "The number of files are $X and the number of matching lines are $Y."
fi




