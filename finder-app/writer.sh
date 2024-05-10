#!/bin/bash

writefile=$1
writestr=$2


if [ -z $1 ] || [ -z $2 ]
then
    exit 1
    echo "Values were not specified."
else
    touch $1
    echo $2 > $1
fi