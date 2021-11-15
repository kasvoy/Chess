#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pieces.h"
#include "format.h"
#include "globvar.h"
#include "move.h"
#include "chess.h"

int toPlay = 0;


bool isLegal(char *move)
{
    int id = toId(move[0]);

    char target_square[2];

    target_square[0] = move[1];
    target_square[1] = move[2];

    for (int i = 0; i < 16; i++)
    {
        if (id < 0)
        {
            if (black_pieces[i].id == id)
            {
                getLegalTargets(black_pieces[i].id, black_pieces[i].location);

                for (struct node *tmp = moves; tmp != NULL; tmp = tmp->next)
                {
                    if (tmp->square == toFormat(target_square)) return true;
                }
            }
        }
        else
        {
            if (white_pieces[i].id == id)
            {
                getLegalTargets(white_pieces[i].id, white_pieces[i].location);

                for (struct node *tmp = moves; tmp != NULL; tmp = tmp->next)
                {
                    if (tmp->square == toFormat(target_square)) return true;
                }
            }
        }
    }

    return false;
}


//update captured piece location to out of board
void updatePieceList(unsigned char square)
{   
    for (int i = 0; i < 16; i++)
    {
        if (white_pieces[i].location == square)
        {
            white_pieces[i].location = 15;
        }
    }

    for (int i = 0; i < 16; i++)
    {
        if (black_pieces[i].location == square)
        {
            black_pieces[i].location = 15;
        }
    }
}

void changeState(struct piece piece_list[16], unsigned char target_square, int piece_id)
{
    for (int i = 0; i < 16; i++)
    {
        if (piece_list[i].id == piece_id)
        {            
            getLegalTargets(piece_list[i].id, piece_list[i].location);

            for (struct node *tmp = moves; tmp != NULL; tmp = tmp->next)
            {
                // printAlgebraic(tmp->square);
                // printf("\n");
                if (tmp->square == target_square)
                {
                    board[piece_list[i].location] = NULL;
                    updatePieceList(target_square);
                    piece_list[i].location = target_square;
                    board[target_square] = &piece_list[i];
                }
            }
        }
    }
}

void generateMove(char *move)
{
    int id = toId(move[0]);

    char target_square[2];

    target_square[0] = move[1];
    target_square[1] = move[2];
    

    if (toPlay % 2 == 0)
    {
        changeState(white_pieces, toFormat(target_square), id);
    }

    else
    {
        changeState(black_pieces, toFormat(target_square), id);
    }

    toPlay++;
}

