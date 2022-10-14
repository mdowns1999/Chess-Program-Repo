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
      //cout << moveStruct[i].move << endl;
      Position posMove(position, moveStruct[i].move);


      if (posMove.isValid())
         kingMoves.insert(posMove.getLocation());
   }

   return kingMoves;
};

/*************************************
DISPLAY
Draw the Piece
*************************************/
void King::display(ogstream& gout)
{
   gout.drawKing(position.getLocation(), fWhite);
};