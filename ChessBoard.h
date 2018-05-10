//Limits maximum board size
const unsigned int MAX_SQUARES_PER_SIDE = 10;

//Stores a value for each square, board can be any size (rectangular
//or square) up to MAX_SQUARES_PER_SIDE x MAX_SQUARES_PER_SIDE
typedef struct {
	int board[MAX_SQUARES_PER_SIDE][MAX_SQUARES_PER_SIDE];
	unsigned int numberRows;
	unsigned int numberColumns;
} CHESSBOARD;




//Initializes dimensions of board, false if dimensions too large, true if ok
bool InitBoard(unsigned int numberRows, unsigned int numberColumns, CHESSBOARD& chessboard);

//Reads values for squares from file, returns false if not enough values
//or some value(s) are not positive numbers, true for success
bool ReadBoard(istream& fin, CHESSBOARD& chessboard);

//Find row and column of a square where value appears. Any square
//is where value appears is ok. Returns true if found, false otherwise
bool FindOnBoard(unsigned int value, int& row, int& col, CHESSBOARD& chessboard);

//Displays values on chessboard in using characters-|* to
//delineate the squares
void PrintBoard(CHESSBOARD& chessboard);