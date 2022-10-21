/***********************************************************************
 * Source File:
 *    Bishop 
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is code that handles all the specifics of Bishop.  Bishop can move 
 * diagnol.
 ************************************************************************/

#include "bishop.h"

/*************************************
* CONSTRUCTOR
* Set up the Bishop attributes
*************************************/
Bishop::Bishop(int r, int c, bool white)
{

   this->fWhite = white;
   this->nMove = 0;
   this->lastMove = 0;
   position.setRow(r);
   position.setCol(c);
   this->letter = fWhite ? 'B' : 'b';
}


/*************************************
* GET MOVES
* Get the Moves for Bishop
*************************************/
set<int> Bishop::getMoves(Piece** board)
{
   set<int> bishopMoves;

   //Moves the Piece can Perform
   move moves[4] =
    {
     {-1,  1}, {1,  1},
     {-1, -1}, {1, -1}
    };

   //Have the Piece Slide
   for (int i = 0; i < 4; i++)
   {
      int r = position.getRow();
      int c = position.getColumn();
      int count = 1;
      int adjustment = (moves[i].row * 8) + moves[i].col;
      while (r >= 0 && r < 9 && c >= 0 && c < 9)
      {
         Position posMove(position, adjustment * count);
         if (posMove.isValid() && (position.hasWrapped(moves[i].row * count, moves[i].col * count, posMove)) && (board[posMove.getLocation()]->getLetter() == 'u' ||
            board[posMove.getLocation()]->isWhite() != fWhite))
         {
            bishopMoves.insert(posMove.getLocation());
            if (board[posMove.getLocation()]->getLetter() != 'u')
               r = 100;
         }
         else
            r = 100;
            
         r += moves[i].row;
         c += moves[i].col;
         count++;
      }
   }

   return bishopMoves;
};

/*************************************
* DISPLAY
* Draw the Bishop
*************************************/
void Bishop::display(ogstream& gout)
{
   gout.drawBishop(position.getLocation(), fWhite);
};