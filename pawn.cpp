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

Pawn::Pawn(int r, int col, bool white)  : Piece()
{
   this->r = r;
   this->c = c;
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
//virtual void display() {};
 set<int> Pawn::getMoves(Board &board) 
 { 
   
   Position posMove(position, fWhite ? 8 : -8);

   cout << posMove.getLocation();
   
   Piece* test = board.getBoard()[posMove.getLocation()];
   //.getLetter();
   cout << "\nLetter: " << test->getLetter() << endl;

   /*if(posMove.isValid() && board.getBoard()[posMove.getLocation()].getLetter() == 'u')
   {

   }*/
   

    return pawnMoves;
 };