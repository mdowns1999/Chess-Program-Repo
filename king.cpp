/***********************************************************************
 * Source File:
 *    King
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is code handles all the specifics of King.  King can move
 * one space any direction.
 ************************************************************************/
#include "king.h"

/*************************************
CONSTRUCTOR
Set up the King attributes
*************************************/
King::King(int r, int c, bool white)
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
Get the Moves for the King
*************************************/
set<int> King::getMoves(Piece** board)
{
   set<int> kingMoves;
   move moves[8]=
   {
                {-1,  1}, {0,  1}, {1,  1},
                {-1,  0},          {1,  0},
                {-1, -1}, {0, -1}, {1, -1}       
   };

   //OWN FUNCTION
   for (int i = 0; i < 8; i++)
   {
      int adjustment = (moves[i].row * 8) + moves[i].col;
      Position posMove(position, adjustment);


      if (posMove.isValid() && (position.hasWrapped(moves[i].row, moves[i].col, posMove)) && (board[posMove.getLocation()]->getLetter() == 'u' ||
         board[posMove.getLocation()]->isWhite() != fWhite))
         kingMoves.insert(posMove.getLocation());
   }

   //King Side Castle
   if(!isMove() && 
      (board[position.getLocation() + 3]->getLetter() == 'r' || 
         board[position.getLocation() + 3]->getLetter() == 'R')
         && !board[position.getLocation() + 3]->isMove()
         && board[position.getLocation() + 1]->getLetter() == 'u'
         && board[position.getLocation() + 2]->getLetter() == 'u')
   {
      kingMoves.insert(position.getLocation() + 2);
   }

   //Queen Side Castle
   if (!isMove() &&
      (board[position.getLocation() - 4 ]->getLetter() == 'r' ||
         board[position.getLocation() - 4]->getLetter() == 'R')
      && !board[position.getLocation() - 4]->isMove()
      && board[position.getLocation() - 1]->getLetter() == 'u'
      && board[position.getLocation() - 2]->getLetter() == 'u'
      && board[position.getLocation() - 3]->getLetter() == 'u')
   {
      kingMoves.insert(position.getLocation() - 2);
   }

   return kingMoves;
};

/*************************************
DISPLAY
Draw the King
*************************************/
void King::display(ogstream& gout)
{
   gout.drawKing(position.getLocation(), fWhite);
};