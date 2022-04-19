#!/bin/bash
gcc main.c -o lck

end=$((SECONDS+300))
count=0

while [ $SECONDS -lt $end ]; do
    # Do what you want.
    ./lck rr &
    ./lck rr &
    ./lck rr &
    ./lck rr &
    ./lck rr &
    ./lck rr &
    ./lck rr &
    ./lck rr &
    ./lck rr &
    ./lck rr
    count=$(($count+10))
done
echo $count
