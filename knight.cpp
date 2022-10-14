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
   set<int> knightMoves;

   M moveStruct[8] =
   {
        {15}, {17}, 
        {6},  {10},
        {-6}, {-10},
        {-15}, {-17}

   };

   //OWN FUNCTION
   for (int i = 0; i < 8; i++)
   {
      //cout << moveStruct[i].move << endl;
      Position posMove(position, moveStruct[i].move);


      if (posMove.isValid())
         knightMoves.insert(posMove.getLocation());
   }

   return knightMoves;
};

/*************************************
DISPLAY
Draw the Piece
*************************************/
void Knight::display(ogstream& gout)
{
   gout.drawKnight(position.getLocation(), fWhite);
};