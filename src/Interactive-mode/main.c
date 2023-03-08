#ifndef TAUCS_H
#define TAUCS_H
#include "assets.h"
#include "movement.h"
#include "placement.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif

int main()
{
    //Declaration of all variables
    int numOfPlayers, numOfAmazons, size, x, y, numOfTiles;
    char direction[6];

    //Title
    printf("\n-WELCOME TO THE GAME OF AMAZONS-\n\n");

    //Inputing the number of players
    printf("Input the number of players\n");
    scanf("%d", &numOfPlayers);

    //Inputing the Player names
    char name[numOfPlayers][11];
    for(int i = 0; i < numOfPlayers; i++)
    {
        printf("Enter Player %d's name (max. 12 characters)\n", i+1);
        scanf("%s", name[i]);
    }

    //Inputting the number of Amazons per player
    printf("Input the number of amazons for each player\n");
    scanf("%d", &numOfAmazons);

    //Inputing the board dimensions
    printf("Input the board size\n");
    scanf ("%d", &size);
    printf("\n");

    //Initializing the board array
    Tile **board;
    board = (Tile**) malloc(size  * sizeof(Tile));
    for (int i = 0; i < size; i++) 
        board[i] = (Tile*) malloc(size * sizeof(Tile));

    //Randomizing the board array
    srand(time(NULL));
    randomizeBoard(board, size);

    //Initializing the Scoreboard
    Score *scoreBoard;
    scoreBoard = (Score*) malloc(numOfPlayers * sizeof(Score));

    printBoard(board, size, numOfPlayers, name, scoreBoard);

    //Resetting the Scoreboard
    for (int i = 0; i < numOfPlayers; i++) {
        scoreBoard[i].points = 0;
    }

    //Placement Phase
    for (int i = 0; i < numOfAmazons; i++) 
    {
        for (int j = 0; j < numOfPlayers; j++) 
        {
            printf("Turn of %s" , name[j]);
            placement(board , j+1, size);
            printBoard(board, size, numOfPlayers, name, scoreBoard);
        }
    }

    printf("\n\n");

    //Movement Phase

    int playersAvailableAmazons[numOfPlayers];

    for (int id = 0; id < numOfPlayers; id++)
        playersAvailableAmazons[id] = availableAmazons(id+1, board, size);

    while (endGameCheck(playersAvailableAmazons, numOfPlayers))
    {
        for (int i = 0; i < numOfPlayers; i++)
        {
            newMove(board, size);
            while (playersAvailableAmazons[i])
            {
                printf("Turn of %s\n" , name[i]);
                
                printf("Enter the coordinates of the amazon you want to move\n");
                printf("x: ");
                scanf("%d", &x);
                printf("y: ");
                scanf("%d", &y);
                
                int canMove = isAmazonAvaiable(x, y, board, size);

                while (board[y][x].occupation != i+1 || !canMove) //error check
                {
                    printf("Your amazon is not on given tile or cannot move. Input the coordinates again\n");
                    printf("x: ");
                    scanf("%d", &x);
                    printf("y: ");
                    scanf("%d", &y);

                    canMove = isAmazonAvaiable(x, y, board, size);
                }
            
                int num;
                char direction[15];
                printf("Number of tiles the amazon will move: ");
                scanf("%d", &num);
                printf("Enter the direction: ");
                scanf("%s", &direction);

                moveAmazon(i+1, y, x, num, direction, board, size, numOfPlayers, name, scoreBoard);

                printBoard(board, size, numOfPlayers, name, scoreBoard);

                for (int id = 0; id < numOfPlayers; id++)
                    playersAvailableAmazons[id] = availableAmazons(id+1, board, size);
                    
                printf("\n");
            }
        }
    }
    
    printf("---GAME OVER---\n");
    
    getchar();
    return 1;
}
