#ifndef TAUCS_H
#define TAUCS_H
#include "assets.h"
#endif

void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers]) 
{

    int valid = 1;
    int x_axis;
    int y_axis;
    
    //checking if movement is possible
    if(strcmp(direction, "LEFT")==0)
    {
        x_axis = 0;
        y_axis = -numOfTiles;

        if (y - numOfTiles < 0)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "RIGHT")==0)
    {
        x_axis = 0;
        y_axis = numOfTiles;

        if (y + numOfTiles > size)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UP")==0)
    {
        x_axis = -numOfTiles;
        y_axis = 0;
        
        if (x - numOfTiles < 0)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWN")==0)
    {
        x_axis = numOfTiles;
        y_axis = 0;

        if (x + numOfTiles > size)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UPLEFT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = -numOfTiles;

        if (x - numOfTiles < 0 || y - numOfTiles < 0)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWNLEFT")==0)
    {
        x_axis = numOfTiles;
        y_axis = -numOfTiles;

        if (x + numOfTiles > size || y - numOfTiles < 0)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UPRIGHT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = numOfTiles;

        if (x - numOfTiles < 0 || y + numOfTiles > size)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWNRIGHT")==0)
    {
        x_axis = numOfTiles;
        y_axis = numOfTiles;

        if (x + numOfTiles > size || y + numOfTiles > size)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else
    {
        valid = 0;
    }

    if(valid == 1)
    {
        board[x][y].occupation = 0;
        board[x + x_axis][y + y_axis].occupation = player_id;
        scoreBoard[player_id - 1].points += board[x + x_axis][y + y_axis].score;
        board[x + x_axis][y + y_axis].score = 0;
        board[x + x_axis][y + y_axis].moved = 1;
        board[x][y].moved = 0;
        printBoard(board, size, numOfPlayers, name, scoreBoard);
        //using artefact
        usingArtifact(player_id, x + x_axis, y + y_axis, board, size, numOfPlayers, name, scoreBoard);
    }
    else
    {
        printf("Move is invalid. Make the move again.\n");
        printBoard(board, size, numOfPlayers, name, scoreBoard);
        int num;
        char direction[15];
        printf("Number of tiles the amazon will move: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        moveAmazon(player_id, x, y, num, direction, board, size, numOfPlayers, name, scoreBoard);
    }
}

void usingArtifact(int player_id, int x, int y, Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers])
{
    if(board[x][y].artefact == 0)
    {
        printf("There is no artifact. Shoot an arrow now.\n");
        
        //shooting an arrow
        if (isAmazonAvaiable(x, y, board, size))
        {
            int num;
            char direction[15];

            printf("Number of tiles you want to shoot an arrow: ");
            scanf("%d", &num);
            printf("Enter the direction: ");
            scanf("%s", &direction);

            shoot(1, x, y, num, direction, board, size, numOfPlayers, name, scoreBoard);
        }
        
        else
        {
            printf("The amazon is blocked. It cannot shoot an arrow.\n");
        }
        
    }
    else if(board[x][y].artefact == 1)
    {
        //horse
        printf("Amazon found a horse, shoot an arrow and make a move.\n");

        int num;
        char direction[15];

        printf("Number of tiles you want to shoot an arrow: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        shoot(1, x, y, num, direction, board, size, numOfPlayers, name, scoreBoard);

        printBoard(board, size, numOfPlayers, name, scoreBoard);

        printf("Time for another move\n");
        printf("Number of tiles the amazon will move: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        moveAmazon(player_id, x, y, num, direction, board, size, numOfPlayers, name, scoreBoard);
        board[x][y].artefact = 0;
    }
    else if(board[x][y].artefact == 2)
    {
        //broken arrow
        printf("Amazon found a broken arrow and it cannot shoot.\n");
        board[x][y].artefact = 0;
    }
    else
    {
        //spear
        printf("Amazon found a spear. Shoot a spear now.\n");

        int num;
        char direction[15];

        printf("Number of tiles you want to shoot a spear: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        shoot(2, x, y, num, direction, board, size, numOfPlayers, name, scoreBoard);
        board[x][y].artefact = 0;
    }
}

void shoot(int id, int x, int y, int numOfTiles, char direction[], Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers])
{
    //id = 1    arrow
    //id = 2    spear

    int valid = 1;
    int inBoundaries = 1;
    int x_axis;
    int y_axis;
    
    //checking if shot is possible
    if(strcmp(direction, "LEFT")==0)
    {
        x_axis = 0;
        y_axis = -numOfTiles;

        if (y - numOfTiles < 0)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
        
        
    }
    else if(strcmp(direction, "RIGHT")==0)
    {
        x_axis = 0;
        y_axis = numOfTiles;

        if (y + numOfTiles > size)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UP")==0)
    {
        x_axis = -numOfTiles;
        y_axis = 0;
        
        if (x - numOfTiles < 0)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWN")==0)
    {
        x_axis = numOfTiles;
        y_axis = 0;

        if (x + numOfTiles > size)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UPLEFT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = -numOfTiles;

        if (x - numOfTiles < 0 || y - numOfTiles < 0)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWNLEFT")==0)
    {
        x_axis = numOfTiles;
        y_axis = -numOfTiles;

        if (x + numOfTiles > size || y - numOfTiles < 0)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UPRIGHT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = numOfTiles;

        if (x - numOfTiles < 0 || y + numOfTiles > size)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWNRIGHT")==0)
    {
        x_axis = numOfTiles;
        y_axis = numOfTiles;

        if (x + numOfTiles > size || y + numOfTiles > size)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else
    {
        valid = 0;
    }
    
    if(id == 2 && board[x + x_axis][y + y_axis].occupation == 0 && inBoundaries)
    {
        board[x + x_axis][y + y_axis].occupation = 9;
        printf("Amazon shot a spear.\n");
    }
    else if(valid)
    {
        board[x + x_axis][y + y_axis].occupation = 9;
        printf("Amazon shot an arrow.\n");
    }
    else
    {
        printf("Shot is invalid. Make the shot again.\n");
        printBoard(board, size, numOfPlayers, name, scoreBoard);
        int num;
        char direction[15];

        printf("Number of tiles you want to shoot a spear or an arrow: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        shoot(id, x, y, num, direction, board, size, numOfPlayers, name, scoreBoard);
    }
}

int isAmazonAvaiable(int x, int y, Tile **board, int size)
{   
    size--;

    if(board[y][x].moved == 1)
        return 0;

    if(x == 0) {
        if(y == 0) {
            if (board[y+1][x+1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (y == size) {
            if (board[y-1][x+1].occupation != 0 && board[y-1][x].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y+1][x].occupation != 0 && board[y-1][x].occupation != 0) {
                return 0;
            }
            return 1;
    }
    if(x == size) {
        if(y == 0) {
            if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (y == size) {
             if (board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x-1].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0) {
                return 0;
            }
            return 1;
    }
    if(y == 0) {
        if(x != 0 && x != size) {
            if (board[y][x-1].occupation != 0 && board[y+1][x-1].occupation != 0 && board[y][x+1].occupation != 0 && board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        
    }
    if(y == size) {
        if(x != 0 && x != size) {
            if (board[y][x-1].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        } 
    }
    else if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y-1][x].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
}

int isMovementPossible(int x, int y, Tile **board)
{
    if(board[x][y].occupation == 0)
    {
        return 1;
    }
    return 0;
}

int availableAmazons(int player_id, Tile **board, int size)
{
    int freeAmazons = 0;

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            if (board[y][x].occupation == player_id)
                if (isAmazonAvaiable(x, y, board, size))
                    freeAmazons++;
    
    return freeAmazons;
}

int endGameCheck(int playerCanMove[], int players)
{
    for (int id = 0; id < players; id++)
        if (playerCanMove[id] > 0)
            return 1;
    
    return 0;
}

void newMove(Tile **board, int size)
{
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            board[x][y].moved = 0;
}