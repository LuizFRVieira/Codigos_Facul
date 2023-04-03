SRC=./src/*.c
INCLUDE=-I./libraries/
BIN=./main

all:
	gcc $(SRC) -g -lm $(INCLUDE) -o $(BIN)
	
run:
	$(BIN)

clean:
	rm $(BIN)
	
valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BIN)