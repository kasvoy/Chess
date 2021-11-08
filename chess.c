#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "format.h"
#include "pieces.h"


bool withinBoard(unsigned char square);


struct piece
{
    int id;
    int differenceMults[8];
    int location;
};

//0 - pawn
//1 - Rook
//2 - Knight
//3 - Bishop
//4 - Queen
//5 - King

struct piece pieces[5];

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

void showLegalTargets(struct piece piece, unsigned char square)
{
    if (piece.id == 0)
    {
        square += 16;

        if(withinBoard(square))
        {
            printAlgebraic(square);
        }
        else printf("No legal moves for this piece\n");
    }

    else if (piece.id == 1 || piece.id == 3)
    {
        int id = piece.id;

        for (int i = 0; i < 4; i++)
        {
            printMovesOneDir(square, pieces[id].differenceMults[i]);
        }
    }

    else if (piece.id == 5 || piece.id == 2)
    {
        int id = piece.id;
        unsigned char proxy = square;

        for (int i = 0; i < 8; i++)
        {
            square += pieces[id].differenceMults[i];

            if (withinBoard(square))
            {
                printAlgebraic(square);
            }

            square = proxy;
        }
    }

    else if (piece.id == 4)
    {
        for (int i = 0; i < 8; i++)
        {
            printMovesOneDir(square, pieces[4].differenceMults[i]);
        }
    }        
}

bool withinBoard(unsigned char square)
{    

    if ((square & 0x88) != 0) 
    {
        return false;
    }

    return true;
}

int main (void)
{
    setPieces();

    int id;
    char square[2];

    printf("Enter piece id: ");
    scanf("%d", &id);
    printf("Enter square: ");
    scanf("%s", square);

    showLegalTargets(pieces[id], toFormat(square));
}


