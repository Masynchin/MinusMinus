.PHONY: primes triangle spiral

primes:
	g++ ./primes/main.cpp -o ./main && ./main

triangle:
	g++ ./triangle/main.cpp -o ./main && ./main

spiral:
	g++ ./spiral/main.cpp -o ./main && ./main
