#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
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

struct node* moves;

bool withinBoard(unsigned char square)
{    
    if ((square & 0x88) != 0) 
    {
        return false;
    }

    return true;
}

//unloads previous list of legal moves
void freeMoves(void)
{
    while(moves != NULL)
    {
        struct node *tmp = moves->next;
        free(moves);
        moves = tmp;
    }
}

void addMove(unsigned char square)
{
    struct node *move = malloc(sizeof(struct node));
    move->square = square;
    move->next = moves;
    moves = move;
}

void getLegalTargets(int piece_id, unsigned char square)
{
    
    if (piece_id == 1)
    {
        square += 16;
        
        if (withinBoard(square))
        {
            freeMoves();
            addMove(square);
        }
    }

    if (piece_id == -1)
    {
        square -= 16;
        
        if (withinBoard(square))
        {
            freeMoves();
            addMove(square);
        }
    }          

    else if (piece_id == 2 || piece_id == -2)
    {
        
        unsigned char proxy = square;
        freeMoves();

        for (int i = 0; i < 4; i++)
        {
            int n = 1;

            while(true)
            {
                square = proxy + n * RookMult[i];

                if (withinBoard(square))
                {
                    
                    addMove(square);
                }

                else
                {
                    break;
                }
                n++;
            }
        }
    }

    else if (piece_id == 3 || piece_id == -3)
    {
        unsigned char proxy = square;
        freeMoves();
        for (int i = 0; i < 8; i++)
        {
            square += KnightMult[i];

            if (withinBoard(square))
            {
                addMove(square);
            }

            square = proxy;
        }
    }

    else if (piece_id == 4 || piece_id == -4)
    {
        unsigned char proxy = square;
        freeMoves();

        for (int i = 0; i < 4; i++)
        {
            int n = 1;

            while(true)
            {
                square = proxy + n * BishopMult[i];

                if (withinBoard(square))
                {
                    addMove(square);
                }

                else
                {
                    break;
                }
                n++;
            }
        }
    }

    else if(piece_id == 5 || piece_id == -5)
    {
        unsigned char proxy = square;
        freeMoves();

        for (int i = 0; i < 8; i++)
        {
            int n = 1;

            while(true)
            {
                square = proxy + n * QueenMult[i];

                if (withinBoard(square))
                {
                    addMove(square);
                }

                else
                {
                    break;
                }
                n++;
            }
        }
    }

    else if (piece_id == 6 || piece_id == -6)
    {
        unsigned char proxy = square;
        freeMoves();

        for (int i = 0; i < 8; i++)
        {
            square += QueenMult[i];

            if (withinBoard(square))
            {
                addMove(square);
            }

            square = proxy;
        }
    }
}

int main (void)
{
    setPieces();
    setBoard();
    
    printState();

    char symbol;
    char target_square[2];
    printf("symbol: ");
    scanf("%c", &symbol);
    printf("target square (alg): ");
    scanf("%s", target_square);


    
    generateMove(symbol, toFormat(target_square));
    printState();


}


