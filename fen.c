#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "globvar.h"
#include "format.h"
#include "pieces.h"


void setPositionFEN(char *fen)
{
    for (int i = 0; i < 16; i++)
    {
        white_pieces[i].id = 0;
        black_pieces[i].id = 0;

        white_pieces[i].location = 15;
        black_pieces[i].location = 15;
    }


    int l = strlen(fen);

    //a8
    int init_location = 112;
    int location = init_location;
    int n = 0;
    int k = 0;
    int w = 0;
    int b = 0;
    int offset = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen[i] == 32) break;
        if (fen[i] == 47)
        {
            i++;
            n++;
            k = 0;
            location = init_location - 16 * n;
        }

        if (!isdigit(fen[i]))
        {  
            if (caseId(fen[i]) > 0)
            {
                white_pieces[w].id = caseId(fen[i]);
                white_pieces[w].location = location + k;
                w++;
            }
            else
            {
                black_pieces[b].id = caseId(fen[i]);
                black_pieces[b].location = location + k;
                b++;
            }
            k++;
        }

        else
        {
            offset = (int)fen[i] - 48;
            k += offset;
        }
    }
    setBoard();
}