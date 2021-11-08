#include <stdio.h>

struct piece
{
    int id;
    int differenceMults[8];
    int location;
};

struct piece pieces[5];

//0 - pawn
//1 - Rook
//2 - Knight
//3 - Bishop
//4 - Queen
//5 - King

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

