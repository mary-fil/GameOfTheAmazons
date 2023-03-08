#include "placement.h"

void randomizeBoard (Tile **board, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            board[i][j].score = rand() % 6;
            board[i][j].artefact = rand() % 4;
            board[i][j].occupation = 0;
            board[i][j].moved = 0;
        }
    }
}

void placement(Tile **board, int j, int dimensions)
{
    int x,y,r;

    while (1) {
        r = 0;
        while (r == 0) {
            printf("\nx: ");
            r=scanf("%d" ,&x);
            if(r == 0 || x < 0 || x > dimensions ) {
                printf("Wrong input, give another positive number in the range: \n");
                r=0;
            }
            while(getchar() != '\n');
        }
        
        r = 0;
        while (r == 0) {
            printf("y: ");
            r=scanf("%d" ,&y);
            if(r==0 || y < 0 || y > dimensions ) {
                printf("Wrong input, give another positive number in the range: \n");
                r=0;
            }
            while(getchar()!='\n');
        }
        
        if(board[y][x].occupation == 0) {
            board[y][x].occupation = j;
            board[y][x].artefact = 0;
            board[y][x].score = 0;
            break;
        }

        else printf("\nInvalid placement. Try again.\n");
    }    
}