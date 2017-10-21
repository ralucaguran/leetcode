#!/bin/bash
#read from the file file.txt and output the tenth line to stdout.
LINES=`wc -l file.txt | cut -d' ' -f1`
if [ $LINES -gt 9 ]
then
    head file.txt | tail -n1
fi
