struct piece
{
    int id;
    int location;
};

struct move
{
    int start_square;
    int target_square;
};


extern int toPlay;
extern struct piece white_pieces[16];
extern struct piece black_pieces[16];
extern struct piece *board[128];