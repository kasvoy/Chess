#include <stdio.h>

void printAlgebraic(unsigned char hex_coordinate);
void fillBoard(unsigned char board[8][16]);

unsigned char board[8][16];

int main (void)
{
    fillBoard(board);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            printf("%x ", board[i][j]);
        }
        printf("\n");
    }

    printf("0x88 coord: %x\n", board[2][3]);

    printAlgebraic(0x42);

    printf("hello ther");

}

void printAlgebraic(unsigned char hex_coordinate)
{
    int file_index = hex_coordinate & 7;
    int rank_index = (hex_coordinate >> 4) + 1;

    char file = file_index + 97;

    printf("%c%d\n", file, rank_index);
}

void fillBoard(unsigned char board[8][16])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            board[i][j] = 16 * (7- i) + j;
        }   
    }
}