all: 
	g++ -Wall biggest-divisible-conglomerate.cpp main.cpp -o bdc
	
run:
	./bdc
	
try:all run
