.PHONY: primes triangle

primes:
	g++ ./primes/main.cpp -o ./main && ./main

triangle:
	g++ ./triangle/main.cpp -o ./main && ./main
