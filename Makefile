all: clean main.o minimax.o tictactoe.o
	gcc -std=c99 -o main main.o minimax.o tictactoe.o

main.o: tictactoe.o minimax.o
	gcc -std=c99 -c src/main.c -Iinclude/

minimax.o: tictactoe.o
	gcc -std=c99 -c src/minimax.c -Iinclude/

tictactoe.o:
	gcc -std=c99 -c src/tictactoe.c -Iinclude/

clean:
	rm -f *.o main

.PHONY: all clean