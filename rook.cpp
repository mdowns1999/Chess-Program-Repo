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
GET MOVES
Get the Moves for the Rook
*************************************/
set<int> Rook::getMoves(Piece** board)
{
   set<int> rookMoves;
   move moves[4] =
   {
                         {0,  1},
                {-1, 0},         {1, 0},
                         {0, -1}
   };
   
   //Have the Piece Slide
   for (int i = 0; i < 4 ; i++)
   {
      int r = position.getRow();
      int c = position.getColumn();
      int count = 1;
      int adjustment = (moves[i].row * 8) + moves[i].col;
      while (r >= 0 && r < 9 && c >= 0 && c < 9)
      {
         Position posMove(position, adjustment * count);
         cout << "newPosition R: " << r << endl;
         cout << "newPosition C: " << c << endl;
         if (posMove.isValid() && (position.hasWrapped(moves[i].row * count, moves[i].col * count, posMove)) && (board[posMove.getLocation()]->getLetter() == 'u' ||
            board[posMove.getLocation()]->isWhite() != fWhite))
         {
            rookMoves.insert(posMove.getLocation());
            cout << "Valid locations" << posMove.getLocation() << endl;
            if (board[posMove.getLocation()]->getLetter() != 'u')
            {
               r = 100;
            }
         }
         else
            r = 100;
 
         r += moves[i].row;
         c += moves[i].col;
         count++;
      }  

   }



































   //for (int i = 0; i < 4; i++)
   //{
   //   posMove.setLocation(position.getLocation() + moveStruct[i].move);

   //   /*if (posMove.isValid() && (board[posMove.getLocation()]->getLetter() == 'u' || 
   //      board[posMove.getLocation()]->isWhite() != fWhite))
   //   {
   //      rookMoves.insert(posMove.getLocation());
   //   }

   //   while (posMove.isValid(moveStruct[i].move) &&
   //    board[posMove.getLocation()]->getLetter() == 'u'  )
   //   {
   //      if (board[posMove.getLocation()]->isWhite() != fWhite || 
   //         board[posMove.getLocation()]->getLetter() == 'u')
   //      {
   //         cout <<"COLOR: " << board[posMove.getLocation()]->isWhite() << endl;
   //         posMove.addLocation(moveStruct[i].move);
   //         rookMoves.insert(posMove.getLocation());
   //      }
   //   }*/


   //   // position.getLocation() + (moveStruct[i].move * j) >= 0 && position.getLocation() + (moveStruct[i].move * j) <= 63 
   //}

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