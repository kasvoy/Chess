#include <stdio.h>
#include <ctype.h>
#include "move.h"
#include "globvar.h"


void printAlgebraic(unsigned char hex_coordinate)
{
    int file_index = hex_coordinate & 7;
    int rank_index = (hex_coordinate >> 4) + 1;

    char file = file_index + 97;

    printf("%c%d", file, rank_index);
}

unsigned char toFormat(char *square)
{
    int file = tolower(square[0]) - 97;
    int rank = square[1] - 49;
    
    return rank * 16 + file;
}


int toId (char symbol)
{
    if (toPlay % 2 == 0)
    {
        if (tolower(symbol) == 'p') return 1;
        else if (tolower(symbol) == 'r') return 2;
        else if (tolower(symbol) == 'n') return 3;
        else if (tolower(symbol) == 'b') return 4;
        else if (tolower(symbol) == 'q') return 5;
        else if (tolower(symbol) == 'k') return 6;
    }
    else
    {
        if (tolower(symbol) == 'p') return -1;
        else if (tolower(symbol) == 'r') return -2;
        else if (tolower(symbol) == 'n') return -3;
        else if (tolower(symbol) == 'b') return -4;
        else if (tolower(symbol) == 'q') return -5;
        else if (tolower(symbol) == 'k') return -6;
    }

    return 0;
}

char toSymbol(int id)
{
    if (id == 1) return 'P';
    else if (id == 2) return 'R';
    else if (id == 3) return 'N';
    else if (id == 4) return 'B';
    else if (id == 5) return 'Q';
    else if (id == 6) return 'K';
    else if (id == -1) return 'p';
    else if (id == -2) return 'r';
    else if (id == -3) return 'n';
    else if (id == -4) return 'b';
    else if (id == -5) return 'q';
    else return 'k';

}
void printState(void)
{
    //int count = 0;

    if (toPlay % 2 == 0)
    {
        printf("White to play\n");
    }

    else
    {
        printf("Black to play\n");
    }

    char board_gui[9][9];
    board_gui[8][8] = ' ';
    
    for (int i = 0; i < 8; i++)
    {
        board_gui[i][8] = 56 - i;
    }

    for (int i = 0; i < 8; i++)
    {
        board_gui[8][i] = 97 + i;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[112 + j - 16 * i] != NULL)
            {
                board_gui[i][j] = toSymbol(board[112 + j - 16 * i]->id);
            }
            else
            {
                board_gui[i][j] = ' ';
            }
        }
    }


    for (int i = 0; i < 8; i++)
    {
        printf("+---+---+---+---+---+---+---+---+\n|");

        for (int j = 0; j < 9; j++)
        {
            
            if (!isdigit(board_gui[i][j]))
            {
                
                printf(" %c |",board_gui[i][j]);
            } 
            else
            {
                printf(" %c",board_gui[i][j]);
            }
            
        }   
        printf("\n");
    }

    printf("+---+---+---+---+---+---+---+---+\n");

    for (int i = 0; i < 9; i++)
    {
        printf("  %c ", board_gui[8][i]);
    }
    printf("\n\n");
}
