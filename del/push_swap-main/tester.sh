#!/bin/bash

# liczba testów na każde N
TESTS=50
# zakres wartości N
SIZES="4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 30 40 50 60 70 80 90 100"

for N in $SIZES; do
    max=0
    for ((i=0; i<TESTS; i++)); do
        # generowanie losowej permutacji liczb 1..N
        args=$(shuf -i 1-$N -n $N)

        # uruchomienie push_swap i zliczenie linii (operacji)
        ops=$(./plikk $args | wc -l)

        if [ "$ops" -gt "$max" ]; then
            max=$ops
        fi
    done
    echo "N=$N -> max operacji: $max"
done
