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
   set<int> rookMoves;

   //Position posMove(position, fWhite ? 8 : -8);

   M moveStruct[4] =
   {
               {8},
         {-1},      {1},
               {-8}

   };

   //OWN FUNCTION
   for (int i = 0; i < 4; i++)
   {
      //cout << moveStruct[i].move << endl;
      Position posMove(position, moveStruct[i].move);


      // position.getLocation() + (moveStruct[i].move * j) >= 0 && position.getLocation() + (moveStruct[i].move * j) <= 63 
       for(int j = 1;posMove.isValid() &&
       board.getBoard()[posMove.getLocation()]->getLetter() == 'u'; j++)
       {
          rookMoves.insert(posMove.getLocation());
          if (posMove.isValid(moveStruct[i].move))
            posMove.addLocation(moveStruct[i].move);
         
       }
   }

   return rookMoves;
};

/*************************************
DISPLAY
Draw the Piece
*************************************/
void Rook::display(ogstream& gout)
{
   gout.drawRook(position.getLocation(), fWhite);
};