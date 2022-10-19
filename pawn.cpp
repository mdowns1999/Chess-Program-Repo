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
}

//Inherited Functions
char Pawn::getLetter()
{ 
   return letter;
}


 set<int> Pawn::getMoves(Piece** board) 
 { 
    set<int> pawnMoves;
   
   Position posMove(position, fWhite ? 8 : -8);
   
   //Basic move 1 up
   
   if(posMove.isValid() && board[posMove.getLocation()]->getLetter() == 'u')
   {
      pawnMoves.insert(posMove.getLocation());
      //   //Basic move 2 up. NOTE FIX LOGIC OF IS VALID
      if (nMove == 0 && posMove.isValid() && board[posMove.getLocation() + (fWhite ? 8 : -8)]->getLetter() == 'u')
      {
         pawnMoves.insert(posMove.getLocation() + (fWhite ? 8 : -8));
      }

   }
 

   
   //Attack Left
   if (posMove.getColumn() > 1)
   {
       //posMove.setCol(posMove.getColumn() - 1);

       if (board[posMove.getLocation() - 1]->isWhite() != fWhite && board[posMove.getLocation() - 1]->getLetter() != 'u')
       {
          pawnMoves.insert(posMove.getLocation() - 1);
       }

      // posMove.setRow(posMove.getRow() + fWhite ? 1 : -1);

      //  if (board.getBoard()[posMove.getLocation()]->getLetter() != board.getBoard()[posMove.getLocation()]->isWhite() ? 'P' : 'p')
      //  {
      //     if (board.getBoard()[posMove.getLocation()]->getNMoves() == 1)
      //     {
      //        pawnMoves.insert(posMove.getLocation());
      //     }
      //  }

      //  posMove.setRow(posMove.getRow() + fWhite ? -1 : -1);
      //  posMove.setCol(posMove.getColumn() + 1);
    }

   // //Attack Right
      if (posMove.getColumn() < 8)
   {
       if (board[posMove.getLocation() + 1]->isWhite() != fWhite && board[posMove.getLocation() + 1]->getLetter() != 'u')
       {
          pawnMoves.insert(posMove.getLocation() + 1);
       }
   }

     //Promotion
      //cout << "posMove.getLocation() + 1: " << board[posMove.getLocation()]->getPosition().getRow() << endl;
      //cout << "GET ROW " << posMove.getLocation()]->getPosition().getRow()<< endl;
      if (board[posMove.getLocation()]->getPosition().getRow() == 1
         || board[posMove.getLocation()]->getPosition().getRow() == 8)
      {
         cout << "Promote" << endl;
         cout << "PROMOTE Row: " << board[posMove.getLocation()]->getPosition().getRow() << endl;
         cout << "PROMOTE Col: " << board[posMove.getLocation()]->getPosition().getColumn() - 1 << endl;
         int row2 = board[posMove.getLocation()]->getPosition().getRow();
         int col2 = board[posMove.getLocation()]->getPosition().getColumn() - 1;
         //board[posMove.getLocation()]->isWhite()
         Piece* pQiece = new Queen(row2, col2, true);
         //Piece* pQiece = new Piece(row, col, true);

         delete board[posMove.getLocation()];
         board[posMove.getLocation()] = pQiece;
      }

      


   // if (posMove.getColumn() <= 7)
   // {
   //    posMove.setCol(posMove.getColumn() + 1);

   //    if (board.getBoard()[posMove.getLocation()]->getLetter() != letter && board.getBoard()[posMove.getLocation()]->getLetter() != 'u')
   //    {
   //       pawnMoves.insert(posMove.getLocation());
   //    }

   //    posMove.setRow(fWhite ? 1 : -1);

   //    if (board.getBoard()[posMove.getLocation()]->getLetter() != board.getBoard()[posMove.getLocation()]->isWhite() ? 'P' : 'p')
   //    {
   //       if (board.getBoard()[posMove.getLocation()]->getNMoves() == 1)
   //       {
   //          pawnMoves.insert(board.getBoard()[posMove.getLocation()]->isWhite() ? posMove.getLocation() - 8 : posMove.getLocation() + 8);
   //       }
   //    }

   //    posMove.setRow(fWhite ? -1 : 1);
   //    posMove.setCol(posMove.getColumn() - 1);
   // }

    return pawnMoves;
 };

 void Pawn::display(ogstream &gout) 
 {
    gout.drawPawn(position.getLocation(), fWhite);
 };

 void Pawn::addPromotion()
 {
    //cout << "PROMOTE" << endl;
    //int row = board[posMove.getLocation()]->getPosition().getRow();
    //int col = board[positionFrom]->getPosition().getColumn() - 1;
    //Piece* pPiece = new Piece(row, col, true);

    //// Delete old object
    //delete board[positionFrom];
    //board[positionFrom] = pPiece;

 };