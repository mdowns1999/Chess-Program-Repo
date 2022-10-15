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
GET LETTER
Get the King Letter
*************************************/
char King::getLetter()
{
   return letter;
}

//virtual void display() {};

/*************************************
GET MOVES
Get the Moves for the King
*************************************/
set<int> King::getMoves(Piece** board)
{
   set<int> kingMoves;

   M moveStruct[8] =
   {
        {7}, {8}, {9},
        {-1},      {1},
        {-9}, {-8},{-7}

   };

   //OWN FUNCTION
   for (int i = 0; i < 8; i++)
   {
      Position posMove(position, moveStruct[i].move);


      if (posMove.isValid() && (board[posMove.getLocation()]->getLetter() == 'u' || 
         board[posMove.getLocation()]->isWhite() != fWhite) )
         kingMoves.insert(posMove.getLocation());
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