#ifndef TAUCS_H
#define TAUCS_H
#include "assets.h"
#endif

void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], Tile **board, int size, int numOfPlayers, char name[][11], Score scoreBoard[]);

void usingArtifact(int player_id, int x, int y, Tile **board, int size, int numOfPlayers, char name[][11], Score scoreBoard[]);

void shoot(int id, int x, int y, int numOfTiles, char direction[], Tile **board, int size, int numOfPlayers, char name[][11], Score scoreBoard[]);

int isAmazonAvaiable(int x, int y, Tile **board, int size);

int isMovementPossible(int x, int y, Tile **board);

int availableAmazons(int player_id, Tile **board, int size);

int endGameCheck(int playerCanMove[], int players);

void newMove(Tile **board, int size);
