/***********************************************************************
 * Source File:
 *    Knight
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is code handles all the specifics of Knight.  Knight can move
 * in various L shapes.
 ************************************************************************/
#include "knight.h"

/*************************************
CONSTRUCTOR
Set up the Knight attributes
*************************************/
Knight::Knight(int r, int c, bool white)
{

  this->fWhite = white;
  this->nMove = 0;
  this->lastMove = 0;
  position.setRow(r);
  position.setCol(c);

  this->letter = fWhite ? 'K' : 'k';
}

/*************************************
GET LETTER
Get the Knight Letter
*************************************/
char Knight::getLetter()
{
  return letter;
}

/*************************************
GET MOVES
Get the Moves for the Knight Piece
*************************************/
set<int> Knight::getMoves(Piece** board)
{
  set<int> knightMoves;

  M moveStruct[8] =
  {
       {15}, {17}, 
       {6},  {10},
       {-6}, {-10},
       {-15}, {-17}

  };

  //OWN FUNCTION
  for (int i = 0; i < 8; i++)
  {
     Position posMove(position, moveStruct[i].move);

     if (posMove.isValid() && (board[posMove.getLocation()]->getLetter() == 'u' ||
        board[posMove.getLocation()]->isWhite() != fWhite))
        knightMoves.insert(posMove.getLocation());
  }

  return knightMoves;
};

/*************************************
DISPLAY
Draw the Knight
*************************************/
void Knight::display(ogstream& gout)
{
  gout.drawKnight(position.getLocation(), fWhite);
};