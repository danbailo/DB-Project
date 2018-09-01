SRC = ./src
INCLUDE = ./include
BIN = ./bin
BUILD = ./build

all:
	gcc -c $(SRC)/soma.c -I $(INCLUDE) -o $(BUILD)/soma.o
	gcc $(SRC)/main.c ./build/*.o -I $(INCLUDE) -o $(BIN)/main 

run:
	$(BIN)/main

clean:
	rm $(BUILD)/*.o
	rm $(BIN)/main