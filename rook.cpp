/***********************************************************************
 * Source File:
 *    Knight
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is code handles all the specifics of Rook.  Rook can slide forward or sideways.
 ************************************************************************/
#include "rook.h"

/*************************************
CONSTRUCTOR
Set up the Rook attributes
*************************************/
Rook::Rook(int r, int c, bool white)
{
   this->fWhite = white;
   this->nMove = 0;
   this->lastMove = 0;
   position.setRow(r);
   position.setCol(c);
   this->letter = fWhite ? 'R' : 'r';
}

/*************************************
GET LETTER
Get the Rook Letter
*************************************/
char Rook::getLetter()
{
   return letter;
}

/*************************************
GET MOVES
Get the Moves for the Rook
*************************************/
set<int> Rook::getMoves(Piece** board)
{
   set<int> rookMoves;

   M moveStruct[4] =
   {
          {8},{-1},{1},{-8}
   };
   
   Position posMove(position, 0);
   //OWN FUNCTION
   for (int i = 0; i < 4; i++)
   {
      posMove.setLocation(position.getLocation() + moveStruct[i].move);

      if (posMove.isValid() && (board[posMove.getLocation()]->getLetter() == 'u' || 
         board[posMove.getLocation()]->isWhite() != fWhite))
      {
         rookMoves.insert(posMove.getLocation());
      }

      while (posMove.isValid(moveStruct[i].move) &&
       board[posMove.getLocation()]->getLetter() == 'u' )
      {
         if (board[posMove.getLocation()]->isWhite() != fWhite || 
            board[posMove.getLocation()]->getLetter() == 'u')
         {
            cout <<"COLOR: " << board[posMove.getLocation()]->isWhite() << endl;
            posMove.addLocation(moveStruct[i].move);
            rookMoves.insert(posMove.getLocation());
         }
      }
      // position.getLocation() + (moveStruct[i].move * j) >= 0 && position.getLocation() + (moveStruct[i].move * j) <= 63 

   }

   return rookMoves;
};

/*************************************
DISPLAY
Draw the Rook
*************************************/
void Rook::display(ogstream& gout)
{
   gout.drawRook(position.getLocation(), fWhite);
};