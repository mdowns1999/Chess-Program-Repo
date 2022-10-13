#include "king.h"

/*************************************
CONSTRUCTOR
Set up the Pieces attributes
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
Get the Pieces Letter
*************************************/
char King::getLetter()
{
   return letter;
}

//virtual void display() {};

/*************************************
GET MOVES
Get the Moves for the Chess Piece
*************************************/
set<int> King::getMoves(Board& board)
{
   set<int> moves;

   Position posMove(position, 9);

   //Basic move 1 up

   if (posMove.isValid() && board.getBoard()[posMove.getLocation()]->getLetter() == 'u')
   {
      moves.insert(posMove.getLocation());

   }


   //Move Diagonal Left
   if (posMove.getColumn() > 1)
   {
      //posMove.setCol(posMove.getColumn() - 1);

      if ((board.getBoard()[posMove.getLocation() - 1]->isWhite() != fWhite 
         && board.getBoard()[posMove.getLocation() - 1]->getLetter() != 'u')
         || board.getBoard()[posMove.getLocation() - 1]->getLetter() == 'u')
      {
         moves.insert(posMove.getLocation() - 1);
      }

   }

   //Move Diagonal Right
   if (posMove.getColumn() < 8)
   {
      //posMove.setCol(posMove.getColumn() - 1);

      if ((board.getBoard()[posMove.getLocation() + 1]->isWhite() != fWhite
         && board.getBoard()[posMove.getLocation() + 1]->getLetter() != 'u')
         || board.getBoard()[posMove.getLocation() + 1]->getLetter() == 'u')
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
void King::display(ogstream& gout)
{
   gout.drawKing(position.getLocation(), fWhite);
};