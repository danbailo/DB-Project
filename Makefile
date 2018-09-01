SRC 	= ./src
INCLUDE = ./include
BIN 	= ./bin
BUILD 	= ./build
LIB		= ./lib
FLAGS	= -O3 -Wall -std=c99
LIBS	= -lm -ldb -L $(LIB)

all: libdb main

#Recompila/atualiza as headers e funcoes passadas aq
libdb: \
	$(BUILD)/soma.o \
	$(BUILD)/subtracao.o
	ar -rcs $(LIB)/libdb.a $(BUILD)/*.o


main: $(BIN)/main


$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@


$(BIN)/%: $(SRC)/%.c
	gcc $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@


run:
	$(BIN)/main


clean:
	rm $(BUILD)/*.o
	rm $(LIB)/*.a
	rm $(BIN)/main