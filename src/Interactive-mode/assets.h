#include <stdio.h>

typedef struct {
    int score;
    int artefact;
    int occupation;
    int moved;
    } Tile;

typedef struct {
        int player;
        int points;
    } Score;

void printBoard(Tile **board, int x, int numOfPlayers, char name[][11], Score scoreBoard[]);