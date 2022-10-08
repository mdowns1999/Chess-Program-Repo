#include "pawn.h"

Pawn::Pawn()
{
   r = 1;
   c = 0;
   fWhite = true;
   nMove = 0;
   lastMove = 0;
   position.setRow(r);
   position.setCol(c);
};

Pawn::Pawn(int r, int col, bool white)  
{
   this->r = r;
   this->c = col;
   this->fWhite = white;
   this->nMove = 0;
   this->lastMove = 0;
   position.setRow(r);
   position.setCol(c);
   //int x = ((r - 1) * 8) + c;
   //position.setLocation(((r - 1) * 8) + c);

   this->letter = fWhite ? 'P' : 'p';
}

//Inherited Functions
char Pawn::getLetter()
{ 
   return letter;
}

//virtual void display() {};


 set<int> Pawn::getMoves(Board &board) 
 { 
   
   Position posMove(position, fWhite ? 8 : -8);
   
   //Piece* test = board.getBoard()[posMove.getLocation()];
   //.getLetter();
   //cout << "\nLetter: " << test->getLetter() << endl;

   //Basic move 1 up
   if(posMove.isValid() && board.getBoard()[posMove.getLocation()]->getLetter() == 'u')
   {
      pawnMoves.insert(posMove.getLocation());

      //Basic move 2 up
      if (posMove.isValid() && board.getBoard()[posMove.getLocation() + fWhite ? 1 : -1]->getLetter() == 'u')
      {
         pawnMoves.insert(posMove.getLocation() + fWhite ? 1 : -1);

      }

   }

   
   //Attack Left
   if (posMove.getColumn() >= 1)
   {
      posMove.setCol(posMove.getColumn() - 1);

      if (board.getBoard()[posMove.getLocation()]->getLetter() != letter && board.getBoard()[posMove.getLocation()]->getLetter() != 'u')
      {
         pawnMoves.insert(posMove.getLocation());
      }

      posMove.setRow(posMove.getRow() + fWhite ? 1 : -1);

      if (board.getBoard()[posMove.getLocation()]->getLetter() != board.getBoard()[posMove.getLocation()]->isWhite() ? 'P' : 'p')
      {
         if (board.getBoard()[posMove.getLocation()]->getNMoves() == 1)
         {
            pawnMoves.insert(posMove.getLocation());
         }
      }

      posMove.setRow(posMove.getRow() + fWhite ? -1 : -1);
      posMove.setCol(posMove.getColumn() + 1);
   }

   //Attack Right
   if (posMove.getColumn() <= 7)
   {
      posMove.setCol(posMove.getColumn() + 1);

      if (board.getBoard()[posMove.getLocation()]->getLetter() != letter && board.getBoard()[posMove.getLocation()]->getLetter() != 'u')
      {
         pawnMoves.insert(posMove.getLocation());
      }

      posMove.setRow(fWhite ? 1 : -1);

      if (board.getBoard()[posMove.getLocation()]->getLetter() != board.getBoard()[posMove.getLocation()]->isWhite() ? 'P' : 'p')
      {
         if (board.getBoard()[posMove.getLocation()]->getNMoves() == 1)
         {
            pawnMoves.insert(board.getBoard()[posMove.getLocation()]->isWhite() ? posMove.getLocation() - 8 : posMove.getLocation() + 8);
         }
      }

      posMove.setRow(fWhite ? -1 : 1);
      posMove.setCol(posMove.getColumn() - 1);
   }

    return pawnMoves;
 };