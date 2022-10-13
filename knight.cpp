#include "knight.h"

/*************************************
CONSTRUCTOR
Set up the Pieces attributes
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
GET LETTER
Get the Pieces Letter
*************************************/
char Knight::getLetter()
{
   return letter;
}

//virtual void display() {};

/*************************************
GET MOVES
Get the Moves for the Chess Piece
*************************************/
set<int> Knight::getMoves(Board& board)
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
void Knight::display(ogstream& gout)
{
   gout.drawKnight(position.getLocation(), fWhite);
};