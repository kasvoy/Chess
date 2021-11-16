#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "globvar.h"
#include "format.h"
#include "pieces.h"


bool whiteCastleKingside (char *fen)
{
    int l = strlen(fen);
    int index = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen [i] == 32)
        {
            index = i + 3;
            break;
        }   
    }

    for (int i = index; i < index + 4; i++)
    {
        if (fen[i] == 'K') return true;
    }

    return false;

}

bool whiteCastleQueenside (char *fen)
{
    int l = strlen(fen);
    int index = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen [i] == 32)
        {
            index = i + 3;
            break;
        }   
    }

    for (int i = index; i < index + 4; i++)
    {
        if (fen[i] == 'Q') return true;
    }

    return false;
}

bool blackCastleKingside (char *fen)
{
    int l = strlen(fen);
    int index = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen [i] == 32)
        {
            index = i + 3;
            break;
        }   
    }

    for (int i = index; i < index + 4; i++)
    {
        if (fen[i] == 'k') return true;
    }

    return false;
}

bool blackCastleQueenside (char *fen)
{
    int l = strlen(fen);
    int index = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen [i] == 32)
        {
            index = i + 3;
            break;
        }   
    }

    for (int i = index; i < index + 4; i++)
    {
        if (fen[i] == 'q') return true;
    }

    return false;
}

unsigned char enPassantTargetSquare (char *fen)
{
    int l = strlen(fen);

    int index = 0;
    int count = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen[i] == 32)
        {
            count++;
            if (count == 3) 
            {
                index = i + 1;
                break;
            }
        }
    }

    char target_square[2];

    target_square[0] = fen[index];
    target_square[1] = fen[index + 1]; 
 
    return toFormat(target_square);

}

int halfMoveClock (char *fen)
{
    int l = strlen(fen);

    int index = 0;
    int count = 0;
    int a = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen[i] == 32)
        {
            count++;
            if (count == 4)
            {
                index = i + 1;
                break;
            }
        }
    }

    char hmclock[4];

    for (int i = index; fen[i] != 32; i++)
    {
        hmclock[a] = fen[i];
        a++;
    }

    return atoi(hmclock);
}

int fullMoveNumber (char *fen)
{
    int l = strlen(fen);

    int index = 0;
    int count = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen[i] == 32)
        {
            count++;
            if (count == 5) 
            {
                index = i + 1;
                break;
            }
        }
    } 
    
    char fmnumber[4]; 
    int a = 0;
    for (int i = index; i < l; i++)
    {
        fmnumber[a] = fen[i];
        a++;
    }

    return atoi(fmnumber);
}


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

    //starting from a8
    int init_location = 112;

    int location = init_location;
    int n = 0;
    int k = 0;
    int w = 0;
    int b = 0;
    int offset = 0;

    for (int i = 0; i < l; i++)
    {
        if (fen[i] == 32)
        {
            i++;
            if (fen[i] == 'w') toPlay = 0;
            else toPlay = 1;
            
            break;
        }

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