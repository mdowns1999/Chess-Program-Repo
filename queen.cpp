/***********************************************************************
 * Source File:
 *    Queen
 * Author:
 *    Ben, Star, Mike
 * Summary:
 *    This is code handles all the specifics of Queen.  Queen can move
 * in any direction.
 ************************************************************************/
 #include "queen.h"
 
/*************************************
CONSTRUCTOR
Set up the Queen attributes
*************************************/
Queen::Queen(int r, int c, bool white)
{

   this->fWhite = white;
   this->nMove = 0;
   this->lastMove = 0;
   position.setRow(r);
   position.setCol(c);
   this->letter = fWhite ? 'Q' : 'q';
}

/*************************************
GET LETTER
Get the Queen Letter
*************************************/
char Queen::getLetter()
{
   return letter;
}

/*************************************
GET MOVES
Get the Moves for the Queen Piece
*************************************/
set<int> Queen::getMoves(Piece** board)
{
   set<int> queenMoves;
   M moveStruct[8] =
   {
        {7}, {8}, {9},
        {-1},      {1},
        {-9}, {-8},{-7}

   };
   Position posMove(position, 0);
   //OWN FUNCTION
   for (int i = 0; i < 8; i++)
   {
      posMove.setLocation(position.getLocation() + moveStruct[i].move);

      if (posMove.isValid() && (board[posMove.getLocation()]->getLetter() == 'u' || board[posMove.getLocation()]->isWhite() != fWhite))
      {
         queenMoves.insert(posMove.getLocation());
      }

      while (posMove.isValid(moveStruct[i].move) &&
       board[posMove.getLocation()]->getLetter() == 'u' )
      {
         if (board[posMove.getLocation()]->isWhite() != fWhite || board[posMove.getLocation()]->getLetter() == 'u')
         {
            cout <<"COLOR: " << board[posMove.getLocation()]->isWhite() << endl;
            posMove.addLocation(moveStruct[i].move);
            queenMoves.insert(posMove.getLocation());
         }
      }
   }
      return queenMoves;
};

/*************************************
DISPLAY
Draw the Queen
*************************************/
void Queen::display(ogstream& gout)
{
   gout.drawQueen(position.getLocation(), fWhite);
};