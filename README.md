# Tic-Tac-Toe!
![GitHub](https://img.shields.io/github/license/oromarrezende/tic-tac-toe)


Tic-Tac-Toe! is a simple C99 command-line implementation of the famous paper-and-pencil game

## Installation

Dowload this repository and compile with C99 Standard

### Posix

```bash
make
```

### Windows

Install [MinGW](http://mingw-w64.org/) and compile sources individually

```bash
gcc -std=c99 -c src/tictactoe.c -Iinclude/
gcc -std=c99 -c src/minimax.c -Iinclude/
gcc -std=c99 -c src/main.c -Iinclude/
gcc -std=c99 -o main main.o minimax.o tictactoe.o
```

## Author
* **Oromar Voit de Rezende** - [oromarrezende](https://github.com/oromarrezende)

## License
[MIT](LICENSE)