#include "bishop.h"

/*************************************
CONSTRUCTOR
Set up the Pieces attributes
*************************************/
Bishop::Bishop(int r, int c, bool white)
{

   this->fWhite = white;
   this->nMove = 0;
   this->lastMove = 0;
   position.setRow(r);
   position.setCol(c);

   this->letter = fWhite ? 'B' : 'b';
}

/*************************************
GET LETTER
Get the Pieces Letter
*************************************/
char Bishop::getLetter()
{
   return letter;
}

//virtual void display() {};

/*************************************
GET MOVES
Get the Moves for the Chess Piece
*************************************/
set<int> Bishop::getMoves(Board& board)
{
   set<int> bishopMoves;

   M moveStruct[4] =
   {
        {7}, {9},
        {-7},  {-9}


   };


   Position posMove(position, 0);
   //OWN FUNCTION
   for (int i = 0; i < 4; i++)
   {
      //cout << moveStruct[i].move << endl;
      
      posMove.setLocation(position.getLocation() + moveStruct[i].move);

      if (posMove.isValid() && (board.getBoard()[posMove.getLocation()]->getLetter() == 'u' || board.getBoard()[posMove.getLocation()]->isWhite() != fWhite))
      {
         bishopMoves.insert(posMove.getLocation());
      }

      while (posMove.isValid(moveStruct[i].move) &&
       board.getBoard()[posMove.getLocation()]->getLetter() == 'u' )
      {
         if (board.getBoard()[posMove.getLocation()]->isWhite() != fWhite || board.getBoard()[posMove.getLocation()]->getLetter() == 'u')
         {
            cout <<"COLOR: " << board.getBoard()[posMove.getLocation()]->isWhite() << endl;
            posMove.addLocation(moveStruct[i].move);
            bishopMoves.insert(posMove.getLocation());
         }
      }
   }

   return bishopMoves;
};

/*************************************
DISPLAY
Draw the Piece
*************************************/
void Bishop::display(ogstream& gout)
{
   gout.drawBishop(position.getLocation(), fWhite);
};