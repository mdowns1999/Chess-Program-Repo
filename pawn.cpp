/***********************************************************************
 * Source File:
 *    Pawn
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 * This is code handles all the specifics of Pawn.  Pawn can move one space and attack 
 * diagonally if a piece is close.  The pawn can also do a special move called
 * empassant.
 ************************************************************************/
#include "pawn.h"


Pawn::Pawn(int r, int c, bool white)  
{
   this->fWhite = white;
   this->nMove = 0;
   this->lastMove = 0;
   position.setRow(r);
   position.setCol(c);
   this->letter = fWhite ? 'P' : 'p';
   hasEmpassant = false;
}

//Inherited Functions
 set<int> Pawn::getMoves(Piece** board) 
 { 
   set<int> pawnMoves;
   updateEmpassant(false);
   Position posMove(position, fWhite ? 8 : -8);
   
   //Basic move 1 up
   if(posMove.isValid() && board[posMove.getLocation()]->getLetter() == 'u')
   {
      pawnMoves.insert(posMove.getLocation());

      // Basic move 2 up.
      if (nMove == 0 && posMove.isValid() && board[posMove.getLocation() + (fWhite ? 8 : -8)]->getLetter() == 'u')
      {
         pawnMoves.insert(posMove.getLocation() + (fWhite ? 8 : -8));
      }
   }
 
   //Attack Left
   if (posMove.getColumn() > 1)
   {
       if (board[posMove.getLocation() - 1]->isWhite() != fWhite && board[posMove.getLocation() - 1]->getLetter() != 'u')
       {
          pawnMoves.insert(posMove.getLocation() - 1);
       }
    }

   //Attack Right
   if (posMove.getColumn() < 8)
   {
      if (board[posMove.getLocation() + 1]->isWhite() != fWhite && board[posMove.getLocation() + 1]->getLetter() != 'u')
      {
         pawnMoves.insert(posMove.getLocation() + 1);
      }
   }

      
      //Empassant
     if (posMove.getColumn() < 8)
     {
        int directionRight = isWhite() ? -7 : 9;
        if ((board[posMove.getLocation() + directionRight]->getLetter() == 'P' 
            || board[posMove.getLocation() + directionRight]->getLetter() == 'p')&&
            board[posMove.getLocation() + directionRight]->isWhite() != fWhite &&
            board[posMove.getLocation() + directionRight]->getNMoves() == 1)
        {
            pawnMoves.insert(posMove.getLocation() + 1);
            updateEmpassant(true);
        }
     }

     if (posMove.getColumn() > 1)
     {
        int directionLeft = isWhite() ? -9 : 7;
        if ((board[posMove.getLocation() + directionLeft]->getLetter() == 'P'
            || board[posMove.getLocation() + directionLeft]->getLetter() == 'p') &&
            board[posMove.getLocation() + directionLeft]->isWhite() != fWhite &&
            board[posMove.getLocation() + directionLeft]->getNMoves() == 1)
        {
            pawnMoves.insert(posMove.getLocation() - 1);
            updateEmpassant(true);
        }
     }
    return pawnMoves;
 };

 void Pawn::display(ogstream &gout) 
 {
    gout.drawPawn(position.getLocation(), fWhite);
 };

