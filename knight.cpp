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
GET MOVES
Get the Moves for the Knight Piece
*************************************/
set<int> Knight::getMoves(Piece** board)
{
  set<int> knightMoves;

  //Moves the Piece can Perform
  move moves[8] =
  {
                     {-1,  2}, { 1,  2},
            {-2,  1},                    { 2,  1},
            {-2, -1},                    { 2, -1},
                     {-1, -2}, { 1, -2}
   };

  //Move the Knight based off of its movements
  for (int i = 0; i < 8; i++)
  {
    int adjustment = (moves[i].row * 8) + moves[i].col;
     Position posMove(position, adjustment);

     if (posMove.isValid() && (position.hasWrapped(moves[i].row, moves[i].col, posMove)) && (board[posMove.getLocation()]->getLetter() == 'u' ||
        board[posMove.getLocation()]->isWhite() != fWhite) )
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