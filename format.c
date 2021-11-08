#include <stdio.h>
#include <ctype.h>

void printAlgebraic(unsigned char hex_coordinate)
{
    int file_index = hex_coordinate & 7;
    int rank_index = (hex_coordinate >> 4) + 1;

    char file = file_index + 97;

    printf("%c%d\n", file, rank_index);
}

unsigned char toFormat(char square[5])
{
    int file = tolower(square[0]) - 97;
    int rank = square[1] - 49;
    
    return rank * 16 + file;
}