#include "rook.h"

/*************************************
CONSTRUCTOR
Set up the Pieces attributes
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
Get the Pieces Letter
*************************************/
char Rook::getLetter()
{
   return letter;
}

//virtual void display() {};

/*************************************
GET MOVES
Get the Moves for the Chess Piece
*************************************/
set<int> Rook::getMoves(Board& board)
{
   set<int> moves;

   Position posMove(position, fWhite ? 8 : -8);

   //Basic move 1 up

   if (posMove.isValid() && board.getBoard()[posMove.getLocation()]->getLetter() == 'u')
   {
      moves.insert(posMove.getLocation());

      //   //Basic move 2 up. NOTE FIX LOGIC OF IS VALID
      if (posMove.isValid() && board.getBoard()[posMove.getLocation() + (fWhite ? 8 : -8)]->getLetter() == 'u')
      {
         moves.insert(posMove.getLocation() + (fWhite ? 8 : -8));

      }

   }


   //Attack Left
   if (posMove.getColumn() > 1)
   {
      //posMove.setCol(posMove.getColumn() - 1);

      if (board.getBoard()[posMove.getLocation() - 1]->isWhite() != fWhite && board.getBoard()[posMove.getLocation() - 1]->getLetter() != 'u')
      {
         moves.insert(posMove.getLocation() - 1);
      }

   }

   // //Attack Right
   if (posMove.getColumn() < 8)
   {
      if (board.getBoard()[posMove.getLocation() + 1]->isWhite() != fWhite && board.getBoard()[posMove.getLocation() + 1]->getLetter() != 'u')
      {
         moves.insert(posMove.getLocation() + 1);
      }
   }

   return moves;
};

/*************************************
DISPLAY
Draw the Piece
*************************************/
void Rook::display(ogstream& gout)
{
   gout.drawRook(position.getLocation(), fWhite);
};