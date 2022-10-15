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
 * WHITE TURN
 * Is it Whites turn?
 ****************************************************************/
bool Board::whiteTurn()
{
   return(currentMove % 2 == 0);

};

/*****************************************************************
 * DISPLAY
 * Display Board
 ****************************************************************/
//void Board::display(const Interface& ui, const set <int>& possible)
//{
//   ogstream gout;
//
//   // draw the checkerboard
//   gout.drawBoard();
//
//   // draw any selections
//   gout.drawHover(ui.getHoverPosition());
//   gout.drawSelected(ui.getSelectPosition());
//
//   // draw the possible moves
//   set <int> ::iterator it;
//   for (it = possible.begin(); it != possible.end(); ++it)
//      gout.drawPossible(*it);
//
//   //array<Piece*>::iterator itPiece;
//   for (int itPiece = 0; itPiece < 64; ++itPiece)
//   {
//      board[itPiece]->display(gout);
//   }
//};

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
bool Board::move(int positionFrom, int positionTo)
{
   // do not move if a move was not indicated
   if (positionFrom == -1 || positionTo == -1)
      return false;

   // find the set of possible moves from our current location
   set <int> possiblePrevious = board[positionFrom]->getMoves(board);

   // only move there is the suggested move is on the set of possible moves
   if (possiblePrevious.find(positionTo) != possiblePrevious.end())
   {
      //Swap locations of the objects
      Position storePos = board[positionFrom]->getPosition();
      board[positionFrom]->assign(board[positionTo]->getPosition());
      board[positionTo]->assign(storePos);

      // Swap Pointers
      Piece* storePiece = board[positionTo];
      board[positionTo] = board[positionFrom];
      board[positionFrom] = storePiece;

      if (board[positionFrom]->getLetter() != 'u')
      {
         int row = board[positionFrom]->getPosition().getRow();
         int col = board[positionFrom]->getPosition().getColumn() - 1;
         Piece* pPiece = new Piece(row, col, true);

         //// Delete old object
         delete board[positionFrom];
         board[positionFrom] = pPiece;
      }
      currentMove++;
      return true;
   }
   return false;

};

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