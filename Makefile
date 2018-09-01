SRC 	= ./src
INCLUDE = ./include
BIN 	= ./bin
BUILD 	= ./build

all: function main

#Recompila/atualiza as headers e funcoes passadas aq
function: \
	$(BUILD)/soma.o  \
	$(BUILD)/subtracao.o


main: $(BIN)/main


$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@


$(BIN)/%: $(SRC)/%.c
	gcc $< $(BUILD)/*.o -I $(INCLUDE) -o $@


run:
	$(BIN)/main


clean:
	rm $(BUILD)/*.o
	rm $(BIN)/main