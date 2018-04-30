/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT*/
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, turnSwitchTest) {
	TicTacToeBoard board;
	Piece turn = board.toggleTurn();
	ASSERT_EQ('O' , turn);
	turn = board.toggleTurn();
	ASSERT_EQ('X' , turn);
}

TEST(TicTacToeBoardTest, placePieceInEmptySquareAndReturn) {
	TicTacToeBoard board;
	Piece piece = board.placePiece(0,0);
	ASSERT_EQ(piece, 'X');
}

TEST(TicTacToeBoardTest, placePieceInEmptySquareAndRead) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.getPiece(0,0), 'X');
}

TEST(TicTacToeBoardTest, placePieceInEmptySquareAndCheckTurn) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.toggleTurn(), 'X');
}

TEST(TicTacToeBoardTest, placePieceInTakenSquareAndReturn) {
	TicTacToeBoard board;
	board.placePiece(0,0); //X
	Piece piece = board.placePiece(0,0); //O
	ASSERT_EQ(piece, 'X');
}

TEST(TicTacToeBoardTest, placePieceInTakenSquareAndRead) {
	TicTacToeBoard board;
	board.placePiece(0,0); //X
	board.placePiece(0,0); //O
	ASSERT_EQ(board.getPiece(0,0), 'X');
}

TEST(TicTacToeBoardTest, placePieceInTakenSquareAndCheckTurn) {
	TicTacToeBoard board;
	board.placePiece(0,0); //X
	board.placePiece(0,0); //O
	ASSERT_EQ(board.toggleTurn(), 'X');
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundsXLow) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1,0), '?');
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundsXHigh) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(4,0), '?');
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundsYLow) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,-1), '?');
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundsYHigh) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,3), '?');
}

TEST(TicTacToeBoardTest, getPieceOutOfBoundsXLow) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1,0), '?');
}

TEST(TicTacToeBoardTest, getPieceOutOfBoundsXHigh) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(3,0), '?');
}

TEST(TicTacToeBoardTest, getPieceOutOfBoundsYLow) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,-1), '?');
}

TEST(TicTacToeBoardTest, getPieceOutOfBoundsYHigh) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,3), '?');
}

TEST(TicTacToeBoardTest, WinTest1) {
	TicTacToeBoard board;
//horizontal win O
board.placePiece(1,1);
board.placePiece(2,1);
board.placePiece(0,1);
board.placePiece(1,2);
board.placePiece(1,0);
board.placePiece(2,2);
board.placePiece(0,2);
board.placePiece(2,0);
ASSERT_EQ(board.getWinner(), 'O');
}

TEST(TicTacToeBoardTest, WinTest2) {
	TicTacToeBoard board;
//vertical win x
board.placePiece(1,0); //x
board.placePiece(0,0); //o
board.placePiece(2,2); //x
board.placePiece(0,1); //o
board.placePiece(0,2); //x
board.placePiece(2,1); //o
board.placePiece(1,2); //o
ASSERT_EQ(board.getWinner(), 'X');
}

TEST(TicTacToeBoardTest, WinTest3) {
	TicTacToeBoard board;
//Vertical win O
board.placePiece(2,1); //x
board.placePiece(2,2); //o
board.placePiece(1,1); //x
board.placePiece(0,1); //o
board.placePiece(1,0); 
board.placePiece(1,2);
board.placePiece(0,0);
board.placePiece(0,2);
ASSERT_EQ(board.getWinner(), 'O');
}

TEST(TicTacToeBoardTest, WinTest4) {
	TicTacToeBoard board;
//vertical win x
board.placePiece(1,1);
board.placePiece(1,0);
board.placePiece(1,2);
board.placePiece(2,0);
board.placePiece(0,0);
board.placePiece(2,2);
board.placePiece(2,1);
board.placePiece(0,2);
board.placePiece(0,1);
ASSERT_EQ(board.getWinner(), 'X');
}

TEST(TicTacToeBoardTest, WinTest5) {
	TicTacToeBoard board;
//diagonal win x
board.placePiece(2,2);
board.placePiece(0,0);
board.placePiece(0,2);
board.placePiece(1,2);
board.placePiece(2,0);
board.placePiece(2,1);
board.placePiece(1,1);

ASSERT_EQ(board.getWinner(), 'X');
}


TEST(TicTacToeBoardTest, WinTest6) {
	TicTacToeBoard board;
//two way win?
board.placePiece(1,0);
board.placePiece(0,1);
board.placePiece(2,2);
board.placePiece(0,2);
board.placePiece(0,0);
board.placePiece(1,1);
board.placePiece(2,1); //x
board.placePiece(1,2); //o
board.placePiece(2,0); //x
ASSERT_EQ(board.getWinner(), 'X');
}

TEST(TicTacToeBoardTest, WinTest7) {
	TicTacToeBoard board;
//vertical win O
board.placePiece(2,0);
board.placePiece(1,2);
board.placePiece(2,1);
board.placePiece(2,2);
board.placePiece(1,1);
board.placePiece(0,2);
ASSERT_EQ(board.getWinner(), 'O');
}

TEST(TicTacToeBoardTest, WinTest8) {
	TicTacToeBoard board;
//vertical win X
board.placePiece(1,1);
board.placePiece(0,2);
board.placePiece(2,2);
board.placePiece(1,0);
board.placePiece(0,1);
board.placePiece(0,0);
board.placePiece(2,1);
ASSERT_EQ(board.getWinner(), 'X');
}


TEST(TicTacToeBoardTest, WinTest9) {
	TicTacToeBoard board;
//cats game
board.placePiece(1,2);
board.placePiece(1,0);
board.placePiece(0,0);
board.placePiece(0,2);
board.placePiece(1,1);
board.placePiece(2,2);
board.placePiece(2,1);
board.placePiece(0,1);
board.placePiece(2,0);
ASSERT_EQ(board.getWinner(), ' ');
}

TEST(TicTacToeBoardTest, WinTest10) {
	TicTacToeBoard board;
//horizontal win
board.placePiece(0,0);
board.placePiece(1,1);
board.placePiece(2,2);
board.placePiece(1,2);
board.placePiece(1,0);
board.placePiece(2,0);
board.placePiece(0,2);
board.placePiece(2,1);
board.placePiece(0,1);
ASSERT_EQ(board.getWinner(), 'X');
}


TEST(TicTacToeBoardTest, WinTest11) {
	TicTacToeBoard board;
//vertical win
board.placePiece(1,0);
board.placePiece(1,1);
board.placePiece(2,0);
board.placePiece(0,0);
board.placePiece(2,2);
board.placePiece(2,1);
board.placePiece(1,2);
board.placePiece(0,1);
ASSERT_EQ(board.getWinner(), 'O');
}






TEST(TicTacToeBoardTest, WinTest12) {
	TicTacToeBoard board;
//cats game
board.placePiece(0,2);
board.placePiece(1,2);
board.placePiece(1,1);
board.placePiece(2,0);
board.placePiece(2,2);
board.placePiece(0,0);
board.placePiece(1,0);
board.placePiece(2,1);
board.placePiece(0,1);
ASSERT_EQ(board.getWinner(), ' ');
}





TEST(TicTacToeBoardTest, WinTest13) {
	TicTacToeBoard board;
//diagonal win
board.placePiece(2,0);
board.placePiece(0,0);
board.placePiece(2,1);
board.placePiece(2,2);
board.placePiece(1,2);
board.placePiece(1,1);
ASSERT_EQ(board.getWinner(), 'O');
}

TEST(TicTacToeBoardTest, WinTest14) {
	TicTacToeBoard board;
//vertical win X
board.placePiece(1,1);
board.placePiece(0,0);
board.placePiece(2,0);
board.placePiece(0,2);
board.placePiece(0,1);
board.placePiece(1,2);
board.placePiece(2,1);
ASSERT_EQ(board.getWinner(), 'X');
}