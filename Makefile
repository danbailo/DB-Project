SRC = ./src
INCLUDE = ./include
BIN = ./bin
BUILD = ./build

all:
	gcc -c $(SRC)/soma.c -I $(INCLUDE) -o $(BUILD)/soma.o
	gcc -c $(SRC)/subtracao.c -I $(INCLUDE) -o $(BUILD)/subtracao.o
	gcc $(SRC)/main.c ./build/*.o -I $(INCLUDE) -o $(BIN)/main 

libed: \
	soma.o \
	subtracao.o

%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $(BUILD)/$@

run:
	$(BIN)/main

clean:
	rm $(BUILD)/*.o
	rm $(BIN)/main