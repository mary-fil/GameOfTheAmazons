#include "assets.h"

void printBoard(Tile **board, int x, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers])
{
    printf("    ");

    for (int k = 0; k < x; k++) {
        printf("%d ", k);
    }

    printf("\n    ");

    for (int k = 0; k < x; k++) {
        printf("- ");
    }

    printf("\n");

    for (int i = 0; i < x; i++) {
        printf("%d | ", i);
        for (int j = 0; j < x; j++)
        {
            if (board[i][j].occupation == 0) {
                printf("%c", 254);
            }

            else if (board[i][j].occupation == 9) {
                printf("%c", 92);
            }

            else {
                printf("%d", board[i][j].occupation);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < numOfPlayers; i++) {
        printf("%s : %d points\n", name[i], scoreBoard[i].points);
    }
    printf("\n");
}
