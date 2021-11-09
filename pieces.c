#include <stdio.h>
#include <stdlib.h>
#include "globvar.h"


struct piece white_pieces[16];
struct piece black_pieces[16];
struct piece *board[128];

//1 - White pawn    // -1 - Black pawn
//2 - White Rook    // -2 - Black Rook
//3 - White Knight  // -3 - Black Knight
//4 - White Bishop  // -4 - Black Bishop
//5 - White Queen   // -5 - Black Queen
//6 - White King    // -6 - Black King


//set starting position
void setPieces (void)
{   
    //pawns
    for (int i = 0; i < 8; i++)
    {
        white_pieces[i].id = 1;
        white_pieces[i].location = 16 + i;

        black_pieces[i].id = -1;
        black_pieces[i].location = 96 + i;      
    }


    //white pieces
    white_pieces[8].id = 2;
    white_pieces[8].location = 0;

    white_pieces[9].id = 3;
    white_pieces[9].location = 1;

    white_pieces[10].id = 4;
    white_pieces[10].location = 2;

    white_pieces[11].id = 5;
    white_pieces[11].location = 3;

    white_pieces[12].id = 6;
    white_pieces[12].location = 4;

    white_pieces[13].id = 4;
    white_pieces[13].location = 5;

    white_pieces[14].id = 3;
    white_pieces[14].location = 6;

    white_pieces[15].id = 2;
    white_pieces[15].location = 7;


    //black pieces
    black_pieces[8].id = -2;
    black_pieces[8].location = 112;

    black_pieces[9].id = -3;
    black_pieces[9].location = 113;

    black_pieces[10].id = -4;
    black_pieces[10].location = 114;

    black_pieces[11].id = -5;
    black_pieces[11].location = 115;

    black_pieces[12].id = -6;
    black_pieces[12].location = 116;

    black_pieces[13].id = -4;
    black_pieces[13].location = 117;

    black_pieces[14].id = -3;
    black_pieces[14].location = 118;

    black_pieces[15].id = -2;
    black_pieces[15].location = 119;
}

void setBoard(void)
{

    for (int i = 0; i < 128; i++)
    {
        board[i] = NULL;
    }

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (white_pieces[j].location == i)
            {
                board[i] = &white_pieces[j];
            }

            else if(black_pieces[j].location == i)
            {
                board[i] = &black_pieces[j];
            }
        }
    }
}

