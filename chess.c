#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "format.h"
#include "pieces.h"
#include "move.h"
#include "globvar.h"


//1 - White pawn    // -1 - Black pawn
//2 - White Rook    // -2 - Black Rook
//3 - White Knight  // -3 - Black Knight
//4 - White Bishop  // -4 - Black Bishop
//5 - White Queen   // -5 - Black Queen
//6 - White King    // -6 - Black King

int RookMult[] = {-16, 16, -1, 1};
int KnightMult[] = {-18, 18, -14, 14, -33, 33, -31, 31};
int BishopMult[] = {-15, 15, -17, 17};
int QueenMult[] = {-16, 16, -1, 1, -15, 15, -17, 17};

bool withinBoard(unsigned char square)
{    
    if ((square & 0x88) != 0) 
    {
        return false;
    }

    return true;
}

void printMovesOneDir(unsigned char square, int multiplier)
{
    int n = 1;

    unsigned char proxy = square;

    while(true)
    {
        square = proxy + n * multiplier;

        if (withinBoard(square))
        {
            printAlgebraic(square);
        }

        else
        {
            break;
        }
        n++;
    }
}

void showLegalTargets(int piece_id, unsigned char square)
{
    if (piece_id == 0)
    {
        square += 16;
        
        if (withinBoard(square))
        {
            printAlgebraic(square);
        }
    }        

    else if (piece_id == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            printMovesOneDir(square, RookMult[i]);
        }
    }

    else if (piece_id == 2)
    {
        unsigned char proxy = square;

        for (int i = 0; i < 8; i++)
        {
            square += KnightMult[i];

            if (withinBoard(square))
            {
                printAlgebraic(square);
            }

            square = proxy;
        }
    }

    else if (piece_id == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            printMovesOneDir(square, BishopMult[i]);
        }
    }

    else if(piece_id == 4)
    {
        for (int i = 0; i < 8; i++)
        {
            printMovesOneDir(square, QueenMult[i]);
        }
    }

    else if (piece_id == 5)
    {
        unsigned char proxy = square;

        for (int i = 0; i < 8; i++)
        {
            square += QueenMult[i];

            if (withinBoard(square))
            {
                printAlgebraic(square);
            }

            square = proxy;
        }
    }
}

int main (void)
{
    setPieces();
    setBoard();
    //generateMove();
    printState();
}


