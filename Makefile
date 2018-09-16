SRC 	= ./src
INCLUDE = ./include
BIN 	= ./bin
BUILD 	= ./build
LIB		= ./lib
CC		= gcc #compiler
FLAGS	= -O3 -Wall -std=c99
LIBS	= -lm -ldb -L $(LIB)

all: libdb main

#Recompila/atualiza as headers e funcoes passadas aq
libdb: \
	$(BUILD)/dbPoint.o \
	$(BUILD)/dbVertices.o \
	# $(BUILD)/dbEdge.o \
	# $(BUILD)/dbTriangle.o \
	# $(BUILD)/dbSurface.o \
	
	ar -rcs $(LIB)/libdb.a $(BUILD)/*.o


main: $(BIN)/main


$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@


$(BIN)/%: $(SRC)/%.c
	$(CC) $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@


run:
	$(BIN)/main


clean:
	rm $(BUILD)/*.o
	rm $(LIB)/*.a
	rm $(BIN)/main