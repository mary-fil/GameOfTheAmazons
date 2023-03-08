#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//should have some game initialization part

void reading_command_line(int argc, char *argv[])
{
    if(strcmp(argv[1],"name") == 0)
    {
        printf("GROUP A");
        exit(0);
    }

    //what phase
    char *param = argv[1];
    char *rest = param;
    char *param_name = strtok_r(rest, "=", &rest);

    if(strcmp(param_name, "phase") == 0)
    {
        char *param_val = strtok_r(rest, "=", &rest);
        if(strcmp(param_val, "placement") == 0)
        {
            if(argc < 2)
            {
                printf("Not enough parameters \n");
                exit(3);
            }
            int total_amazons = atoi(argv[2]);
            printf("placement phase \n");

            //placement phase

            exit(0);
        }
        else if(strcmp(param_val, "movement") == 0)
        {
            printf("movement phase\n");

            //movement phase

            exit(0);
        }
        else
        {
            printf("Wrong imput in command line.\n");
            exit(3);
        }
    }
    else
    {
        printf("Wrong imput in command line.\n");
        exit(3);
    }
    
}

int main(int argc, char *argv[])
{
    int size;
    int total_amazons;
    int height_board, width_board;

    //accepting command line parameters
    reading_command_line(argc, argv);

    /*
    if(strcmp(argv[1],"name") == 0)
    {
        printf("GROUP A");
        return 0;
        //display player's name
        //exit the program
    }
    else if(strcmp(argv[1],"placement") == 0)
    {
        total_amazons = atoi(argv[2]);

        //check what do to if it is not specified
        
        printf("placement phase \n");
        printf("total amazons = %d \n", total_amazons);

        //read the gamestate from the file inputboard.txt

        FILE *input;
        FILE *output;

        char inputboard_file_name[32];
        char outputboard_file_name[32];

        strncpy(inputboard_file_name, argv[3], 32);
        strncpy(outputboard_file_name, argv[4], 32);

        input = fopen(inputboard_file_name, "r");

        //reading the size of the board
        char line[256];
        fgets(line, 256, input);

        char *token;
        char *rest = line;

        token = strtok_r(rest, " ", &rest);
        height_board = atoi(token);
        token = strtok_r(rest, " ", &rest);
        width_board = atoi(token);

        printf("height_board = %d \n", height_board);
        printf("width_board = %d \n", width_board);

        Tile **board;
        board = (Tile**) malloc(height_board * width_board * sizeof(Tile));
    
        for (int i = 0; i < size; i++) 
            board[i] = (Tile*) malloc(height_board * width_board * sizeof(Tile));

        //checking on inputboard.txt if all the amazons are placed 

            //no :
            //placing the amazon
            //save the game state to the output file and exit

            char ch;
            output = fopen(outputboard_file_name, "w");

            while( ( ch = fgetc(input) ) != EOF )
                fputc(ch, output);

            fclose(input);
            fclose(output);
            return 0;
            //yes:
            //program exits immediately returning appropriate error code
    }
    else if(strcmp(argv[1],"movement") == 0)
    {
        printf("movement phase\n");
        return 0;
        //read the gamestate from the file inputboard.txt

        //can amazon make a move

            //yes:
            //move one of his amazon
            //shoot an arrow
            //alter the score
            //save the game state to the output file and exit
    }
    else
    {
        printf("wrong imput\n");
        return 3;
    }
    */
}