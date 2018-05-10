#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <assert.h>
using namespace std;

#include "ChessBoard.h"


int main()
{
	CHESSBOARD board;
	string fileName;
	ifstream fin;

	int row;
	int col;
	int sizeRow;
	int sizeCol;
	unsigned int find = 1;
	int start = 1;
	int position = 0;
	int tempR = 0;
	int tempC = 0;

	// Opening the file
	cout << "File name: ";
	cin >> fileName;
	fin.open(fileName);
	if (fin.fail())
	{
		cerr << "Can't open \"" << fileName << "\"" << endl;
		return 0;
	}
	// Getting the dimensions of the board from the file and settig them into the ADT if dimensions are too big the game will end
	fin >> sizeRow;
	fin >> sizeCol;
	if (InitBoard(sizeRow, sizeCol, board) == false)
	{
		cout << "Invalid board positions" << endl;
		return 0;
	}
	// Reading the boards values from the file and adding them to the ADT end the game if something is wrong with the board
	if (ReadBoard(fin, board) == false)
	{
		cout << "Invalid board positions" << endl;
		return 0;
	}
	// Displaying the board to the user
	PrintBoard(board);

	// Play the game
	cout << "Moving the king from square to square ..." << endl;
	if (FindOnBoard(start, tempR, tempC, board) == false)
	{
		cout << "Invalid board positions" << endl;
		return 0;
	}
	else
	{
		cout << "Position 1: start at (" << tempR << "," << tempC << ")" << endl;
	}
		for (int x = 2; x <= sizeCol * sizeRow; x++)
		{
			if (FindOnBoard(x, row, col, board) == false)
			{
				cout << "Invalid board positions" << endl;
				return 0;
			}
			else if (row == tempR + 1 || row == tempR - 1 || row == tempR && col == tempC + 1 || col == tempC - 1 || col == tempC)
			{
				cout << "Position  " << x << ": jump to row (" << row << ", " << col << ")" << endl;
				tempR = row;
				tempC = col;
			}
			else
			{
				cout << "Position " << x << ": can't jump to row" << endl;
				cout << "Does not represent a King's tour" << endl;
				return 0;
			}
		}
		cout << "Represents a King's tour!" << endl;
	return 0;
}
