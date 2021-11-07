#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void printAlgebraic(unsigned char hex_coordinate);
void fillBoard(unsigned char board[8][16]);
void printBoard(unsigned char board[8][16]);
bool withinBoard(unsigned char square);
unsigned char toFormat(char square[5]);
void setPieces(void);


struct piece
{
    int id;
    int differenceMults[8];
};

//0 - pawn
//1 - Rook
//2 - Knight
//3 - Bishop
//4 - Queen
//5 - King

struct piece pieces[5];

unsigned char board[8][16];


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


int main (void)
{
    fillBoard(board);
    //printBoard(board);
    setPieces();

    int id;
    char square[2];

    printf("Enter piece id: ");
    scanf("%d", &id);
    printf("Enter square: ");
    scanf("%s", square);

    showLegalTargets(pieces[id], toFormat(square));

}
void setPieces (void)
{ 
    struct piece pawn = {0, {16}};
    struct piece Rook = {1, {-16, 16, -1, 1}};
    struct piece Knight = {2, {-18, 18, -14, 14, -33, 33, -31, 31}};
    struct piece Bishop = {3, {-15, 15, -17, 17}};
    struct piece Queen = {4, {-16, 16, -1, 1, -15, 15, -17, 17}};
    struct piece King = {5, {-16, 16, -1, 1, -15, 15, -17, 17}};

    pieces[0] = pawn;
    pieces[1] = Rook;
    pieces[2] = Knight;
    pieces[3] = Bishop;
    pieces[4] = Queen;
    pieces[5] = King;
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
            board[i][j] = 16 * i + j;
        }   
    }
}

void printBoard(unsigned char board[8][16])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            printf("%.2x ", board[i][j]);
        }
        printf("\n");
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

unsigned char toFormat(char square[5])
{
    int file = tolower(square[0]) - 97;
    int rank = square[1] - 49;
    
    return rank * 16 + file;
}
