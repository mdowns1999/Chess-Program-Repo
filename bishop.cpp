/***********************************************************************
 * Source File:
 *    Bishop 
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is code handles all the specifics of Bishop.  Bishop can move 
 * diagnol.
 ************************************************************************/

#include "bishop.h"

/*************************************
CONSTRUCTOR
Set up the Bishop attributes
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
Get the Bishop Letter
*************************************/
char Bishop::getLetter()
{
   return letter;
}

//virtual void display() {};

/*************************************
GET MOVES
Get the Moves for Bishop
*************************************/
set<int> Bishop::getMoves(Piece** board)
{
   set<int> bishopMoves;

   M moveStruct[4] =
   {
        {7}, {9},
        {-7},{-9}
   };


   Position posMove(position, 0);
   //OWN FUNCTION
   for (int i = 0; i < 4; i++)
   {
      //cout << moveStruct[i].move << endl;
      
      posMove.setLocation(position.getLocation() + moveStruct[i].move);

      if (posMove.isValid() && (board[posMove.getLocation()]->getLetter() == 'u' || board[posMove.getLocation()]->isWhite() != fWhite))
      {
         bishopMoves.insert(posMove.getLocation());
      }

      while (posMove.isValid(moveStruct[i].move) &&
       board[posMove.getLocation()]->getLetter() == 'u' )
      {
         if (board[posMove.getLocation()]->isWhite() != fWhite || board[posMove.getLocation()]->getLetter() == 'u')
         {
            cout <<"COLOR: " << board[posMove.getLocation()]->isWhite() << endl;
            posMove.addLocation(moveStruct[i].move);
            bishopMoves.insert(posMove.getLocation());
         }
      }
   }

   return bishopMoves;
};

/*************************************
DISPLAY
Draw the Bishop
*************************************/
void Bishop::display(ogstream& gout)
{
   gout.drawBishop(position.getLocation(), fWhite);
};