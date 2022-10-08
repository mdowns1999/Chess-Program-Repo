#include "board.h"

Board::Board()
{
   for (int i = 0; i < 64; i++)
   {
      int r = i / 8 + 1;
      int c = i % 8;

      Piece* piece = new Piece(r, c, true);
      board[i] = piece;
   }

};


/*****************************************************************
 * GET CURRENT MOVE
 * Get Current Move
 ****************************************************************/
int Board::getCurrentMove()
{
   return 0;
};

/*****************************************************************
 * WHITE TURN
 * Is it Whites turn?
 ****************************************************************/
bool Board::whiteTurn()
{
   return false;
};

/*****************************************************************
 * DISPLAY
 * Display Board
 ****************************************************************/
void Board::display(Position posHover, Position posSel)
{

};

/*****************************************************************
 * GET
 * Get Piece Position
 ****************************************************************/
//Piece get(Position position){};

/*****************************************************************
 * FREE
 * Is something free
 ****************************************************************/
void Board::free()
{

};

/*****************************************************************
 * RESET
 * Reset the board
 ****************************************************************/
void Board::reset()
{

};

/*****************************************************************
 * MOVE
 * Move the Piece
 ****************************************************************/
//void Board::move(Move move)
//{

//};

/*****************************************************************
 * ASSIGN
 * Assign the Piece
 ****************************************************************/
//void Board::assign(Piece piece)
//{

//};

/*****************************************************************
 * SWAP
 * Swap th ePieces
 ****************************************************************/
void Board::swap(Position position1, Position position2)
{

};

/*****************************************************************
 * ASSERT BOARD
 * Check the board
 ****************************************************************/
void Board::assertBoard()
{

};