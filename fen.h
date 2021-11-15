void setPositionFEN(char *fen);
bool whiteCastleKingside (char *fen);
bool whiteCastleQueenside (char *fen);
bool blackCastleKingside (char *fen);
bool blackCastleQueenside (char *fen);
unsigned char enPassantTargetSquare (char *fen);
int halfMoveClock (char *fen);
int fullMoveNumber (char *fen);