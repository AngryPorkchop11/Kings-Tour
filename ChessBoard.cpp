// Title: Lab 4 Kings Tour
//
// Purpose: Attempt to complete a kings tour on a game board. If the king can't make the move the game is over. 
//
// Class: CSC 2430 Winter 2018
//
// Author: Mathew Lister

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <assert.h>
using namespace std;

#include "ChessBoard.h"

//Initializes dimensions of board, false if dimensions too large, true if ok
bool InitBoard(unsigned int numberRows, unsigned int numberColumns, CHESSBOARD& chessboard)
{
	chessboard.board[numberRows][numberColumns];
	chessboard.numberRows = numberRows; 
	chessboard.numberColumns = numberColumns;

	if (numberRows > MAX_SQUARES_PER_SIDE || numberColumns > MAX_SQUARES_PER_SIDE)
	{
		return false;
	}
	return true;
}

//Reads values for squares from file, returns false if not enough values
//or some value(s) are not positive numbers, true for success
bool ReadBoard(istream& fin, CHESSBOARD& chessboard)
{
	unsigned int counter = 0;


	for (unsigned int i = 0; i < chessboard.numberRows; i++)
	{
		for (unsigned int x = 0; x < chessboard.numberColumns; x++)
		{
			if (fin >> chessboard.board[i][x])
			{
				counter++;
			}
			
			if (chessboard.board[i][x] < 1)
			{
				return false;
			}
			
		}
	}
	if (counter != chessboard.numberRows * chessboard.numberColumns)
	{
		return false;
	}
	return true;
}

//Find row and column of a square where value appears. Any square
//is where value appears is ok. Returns true if found, false otherwise
bool FindOnBoard(unsigned int value, int& row, int& col, CHESSBOARD& chessboard)
{
	unsigned int search = 0;
	for (int i = 0; i < chessboard.numberRows; i++)
	{
		for (int x = 0; x < chessboard.numberColumns; x++)
		{
			search = chessboard.board[i][x];
			if (value == search)
			{
				row = i+1;
				col = x+1;
				return true;
			}
		}
	}
	return false;
}

//Displays values on chessboard in using characters-|* to
//delineate the squares
void PrintBoard(CHESSBOARD& chessboard)
{
	for (int i = 0; i < chessboard.numberRows; i++) // loopiny rows
	{
		for (int j = 0; j < chessboard.numberColumns; j++) // looping collumns
		{
			cout << "+--"; // adding board sections
		}
		cout << "+" << endl;
		cout << "|";
		for (int x = 0; x < chessboard.numberColumns; x++)
		{
			cout << setw(2) << chessboard.board[i][x] << "|"; // printing board

		}
		cout << endl;
	}
	for (int j = 0; j < chessboard.numberColumns; j++)
	{
		cout << "+--";
	}
	cout << "+" << endl;
}
