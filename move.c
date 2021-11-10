#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pieces.h"
#include "format.h"
#include "globvar.h"
#include "move.h"
#include "chess.h"

int toPlay = 0;

void changeState(struct piece piece_list[16], unsigned char target_square, int piece_id)
{
    for (int i = 0; i < 16; i++)
    {
        if (piece_list[i].id == piece_id)
        {
            getLegalTargets(piece_list[i].id, piece_list[i].location);

            for (struct node *tmp = moves; tmp != NULL; tmp = tmp->next)
            {
                if (tmp->square == target_square)
                {
                    board[piece_list[i].location] = NULL;
                    piece_list[i].location = target_square;
                    board[target_square] = &piece_list[i];
                }
            }
        }
     }
}

void generateMove(char piece_symbol, unsigned char target_square)
{
    int id = toId(piece_symbol);
    
 
    if (toPlay % 2 == 0)
    {
        changeState(white_pieces, target_square, id);
    }
    else
    {
        changeState(black_pieces, target_square, id);
    }

    toPlay++;
}

