#!/bin/bash

PUSH_SWAP=./../push_swap

invalid_tests=(
	"1 2 3 a"
	"1 2 3 1"
	"2147483648"
	"-2147483649"
	"42 --5 7"
	"+ 4 5"
	"1 3 dog 35 80 -3"
	"1 2 3 5 67b778 947"
	" 12 4 6 8 54fhd 4354"
	"1 --    45 32"
	"1 3 58 9 3"
	"3 03"
	" 49 128     50 38   49"
	"54867543867438 3"
	"-2147483647765 4 5"
	"214748364748385 28 47 29"
)

valid_tests=(
	"1 2 3"
	"2 1 3"
	"-5 0 42"
	"3"
	"10 -2 4 8"
	"1 3 5 +9 20 -4 50 60 04 08"
	"3 4 6 8 9 74 -56 +495"
	"95 99 -9 10 9"
	"2147483647 2 4 7"
	"99 -2147483648 23 545"
	"2147483647 843 56544 24394"
)

run_test() {
	local args="$1"
	local expect_error=$2
	local output exit_code

	output=$($PUSH_SWAP $args 2>&1)
	exit_code=$?

	if [[ $expect_error -eq 1 ]]; then
		if [[ "$output" == *"Error"* ]]; then
			echo "[OK]   '$args' -> correct error call (code $exit_code)"
		else
			echo "[FAIL] '$args' -> none or wrong error call (code $exit_code)"
			echo "	   Output: '$output'"
		fi
	else
		if [[ "$output" == *"Error"* ]]; then
			echo "[FAIL] '$args' -> Error when it should NOT be one (code $exit_code)"
			echo "	   Output: '$output'"
		else
			echo "[OK]   '$args' -> Correct output (kod $exit_code)"
		fi
	fi
}

echo "=== TESTS FOR INVALID ==="
for args in "${invalid_tests[@]}"; do
	run_test "$args" 1
done

echo
echo "=== TESTS FOR VALID ==="
for args in "${valid_tests[@]}"; do
	run_test "$args" 0
done
