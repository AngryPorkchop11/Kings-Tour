//// Title: Lab 4 Chess Board Unit Test - Lab4UnitTest.cpp
////
//// Purpose: Runs validation tests on the chess board component for Lab 4.
//// 
//// Class: CSC 2430 Winter 2018
////
//// Author: Max Benson
//
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <assert.h>
//
//using namespace std;
//
//#include "ChessBoard.h"
//
//void CompareStrings(string expected, string actual);
//
//int main()
//{
//	CHESSBOARD chessboard;
//	stringstream inbuffer1;
//	stringstream outbuffer;
//	string expected;
//	int row, col;
//
//	// Everything written to cout goes into this buffer instead of out to the screen
//	cout.rdbuf(outbuffer.rdbuf());
//
//	// Initialize the call database
//	assert(InitBoard(3, 4, chessboard));
//
//	// Read in a board
//	inbuffer1.str("1 2 3 4 8 7 6 5 9 10 11 12");
//	assert(ReadBoard(inbuffer1, chessboard));
//
//	// Print it and verify
//	PrintBoard(chessboard);
//	expected = "+--+--+--+--+\n| 1| 2| 3| 4|\n+--+--+--+--+\n| 8| 7| 6| 5|\n+--+--+--+--+\n| 9|10|11|12|\n+--+--+--+--+\n";
//	CompareStrings(expected, outbuffer.str());
//	assert(outbuffer.str() == expected);
//	outbuffer.str(string());	// Clear the buffer
//
//								// Find things
//	assert(FindOnBoard(1, row, col, chessboard));
//	assert(row == 1 && col == 1);
//	assert(FindOnBoard(2, row, col, chessboard));
//	assert(row == 1 && col == 2);
//	assert(FindOnBoard(3, row, col, chessboard));
//	assert(row == 1 && col == 3);
//	assert(FindOnBoard(4, row, col, chessboard));
//	assert(row == 1 && col == 4);
//	assert(FindOnBoard(5, row, col, chessboard));
//	assert(row == 2 && col == 4);
//	assert(FindOnBoard(6, row, col, chessboard));
//	assert(row == 2 && col == 3);
//	assert(FindOnBoard(7, row, col, chessboard));
//	assert(row == 2 && col == 2);
//	assert(FindOnBoard(8, row, col, chessboard));
//	assert(row == 2 && col == 1);
//	assert(FindOnBoard(9, row, col, chessboard));
//	assert(row == 3 && col == 1);
//	assert(FindOnBoard(10, row, col, chessboard));
//	assert(row == 3 && col == 2);
//	assert(FindOnBoard(11, row, col, chessboard));
//	assert(row == 3 && col == 3);
//	assert(FindOnBoard(12, row, col, chessboard));
//	assert(row == 3 && col == 4);
//	assert(!FindOnBoard(13, row, col, chessboard));
//	assert(!FindOnBoard(0, row, col, chessboard));
//
//	// A little more testing
//	stringstream inbuffer2;
//	assert(InitBoard(2, 2, chessboard));
//	inbuffer2.str("1 2 3 4");
//	assert(ReadBoard(inbuffer2, chessboard));
//	PrintBoard(chessboard);
//	expected = "+--+--+\n| 1| 2|\n+--+--+\n| 3| 4|\n+--+--+\n";
//	CompareStrings(expected, outbuffer.str());
//	assert(outbuffer.str() == expected);
//	outbuffer.str(string());	// Clear the buffer
//
//	stringstream inbuffer3;
//	inbuffer3.str("0 1 2 3");
//	assert(!ReadBoard(inbuffer3, chessboard));
//
//	stringstream inbuffer4;
//	inbuffer4.str("1 2 3");
//	assert(!ReadBoard(inbuffer4, chessboard));
//
//	stringstream inbuffer5;
//	inbuffer5.str("x y z w");
//	assert(!ReadBoard(inbuffer5, chessboard));
//
//	// Congratulate 
//	cerr << "Good work, you passed the unit tests." << endl;
//
//	return 0;
//}
//
//void CompareStrings(string expected, string actual)
//{
//	int ich;
//	int cch;
//
//	cch = expected.length();
//	for (ich = 0; ich < cch; ich++)
//	{
//		if (ich == actual.length())
//		{
//			cerr << "Expected output has additional characters: '" << expected.substr(ich, cch - ich) << "'" << endl;
//			return;
//		}
//		if (expected[ich] != actual[ich])
//		{
//			cerr << "Expected and actual outputs differ at char " << (ich + 1) << endl;
//			cerr << "Rest of expected = '" << expected.substr(ich, cch - ich) << endl;
//			cerr << "Rest of actual   = '" << actual.substr(ich, actual.length() - ich) << endl;
//			return;
//		}
//	}
//	if (ich < (int)actual.length())
//	{
//		cerr << "Actual output has additional characters: '" << actual.substr(ich, cch - ich) << "'" << endl;
//		return;
//	}
//}
//
