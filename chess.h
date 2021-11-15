bool withinBoard(unsigned char square);
void freeMoves(void);
bool pieceOnSquare (struct piece piece_list[16], unsigned char square);
void addMove(unsigned char square);
int getLegalTargets(int piece_id, unsigned char square);