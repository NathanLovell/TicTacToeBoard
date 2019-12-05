/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
protected:
	TicTacToeBoardTest() {}			 //constructor runs before each test
	virtual ~TicTacToeBoardTest() {} //destructor cleans up after tests
	virtual void SetUp() {}			 //sets up before each test (after constructor)
	virtual void TearDown() {}		 //clean up after each test, (before destructor)
};

TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleTurn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, toggleTwoTurns)
{
	TicTacToeBoard board;
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, toggleThreeTurns)
{
	TicTacToeBoard board;
	board.toggleTurn();
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, placeXIn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1, 1), X);
}

TEST(TicTacToeBoardTest, placeXOutSmall)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1, -1), Invalid);
}

TEST(TicTacToeBoardTest, placeXOutLargeColumn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1, 5), Invalid);
}

TEST(TicTacToeBoardTest, placeXOutLargeRow)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(5, 1), Invalid);
}

TEST(TicTacToeBoardTest, getPieceX)
{
	TicTacToeBoard board;
	board.placePiece(1, 1);
	ASSERT_EQ(board.getPiece(1, 1), X);
}

TEST(TicTacToeBoardTest, getPieceIn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1, 1), Blank);
}

TEST(TicTacToeBoardTest, getPieceOut)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1, 3), Invalid);
}

TEST(TicTacToeBoardTest, placeOneExisting)
{
	TicTacToeBoard board;
	board.placePiece(1, 1);
	ASSERT_EQ(board.placePiece(1, 1), X);
}

TEST(TicTacToeBoardTest, placeAfterWin)
{
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.placePiece(1, 0);
	board.placePiece(0, 1);
	board.placePiece(1, 1);
	board.placePiece(0, 2);
	board.placePiece(1, 2);
	ASSERT_EQ(board.placePiece(1, 1), O);
}

TEST(TicTacToeBoardTest, placeAfterDraw)
{
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.placePiece(1, 0);
	board.placePiece(1, 1);
	board.placePiece(2, 2);
	board.placePiece(2, 0);
	board.placePiece(0, 2);
	board.placePiece(1, 2);
	board.placePiece(0, 1);
	board.placePiece(2, 1);
	ASSERT_EQ(board.placePiece(0, 0), X);
}

