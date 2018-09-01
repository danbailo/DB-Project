all:
	gcc -c ./src/soma.c -I ./include -o ./build/soma.o
	gcc ./src/main.c ./build/*.o -I ./include -o ./bin/main 

run:
	./bin/main

clean:
	rm ./build/*.o
	rm ./bin/main