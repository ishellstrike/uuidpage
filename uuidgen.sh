#!bin/bash

MAXCOUNT=1000000
count=1
temp=0

rm 1.txt
rm 2.txt
rm 3.txt

touch 1.txt
touch 2.txt
touch 3.txt

while [ "$count" -le $MAXCOUNT ]
do
    let "temp = count * 3"
    printf "00000000-0000-0000-0000-%06x\n" "$temp" >> 1.txt
    let "temp = count * 3 + 1"
    printf "00000000-0000-0000-0000-%06x\n" "$temp" >> 2.txt
    let "temp = count * 3 + 2"
    printf "00000000-0000-0000-0000-%06x\n" "$temp" >> 3.txt
    let "count += 1"
done
