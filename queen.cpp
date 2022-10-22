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
* CONSTRUCTOR
* Set up the Queen attributes
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
* GET MOVES
* Get the Moves for the Queen Piece
*************************************/
set<int> Queen::getMoves(Piece** board, int lastMove)
{
   set<int> queenMoves;

   //Moves the Piece can Perform
   move moves[8] =
             {
                {-1,  1}, {0,  1}, {1,  1},
                {-1,  0},          {1,  0},
                {-1, -1}, {0, -1}, {1, -1}
             };
   
   //Have the Piece Slide
   for (int i = 0; i < 8; i++)
   {
      int r = position.getRow();
      int c = position.getColumn();
      int count = 1;
      int adjustment = (moves[i].row * 8) + moves[i].col;
      while (r >= 0 && r < 9 && c >= 0 && c < 9)
      {
         Position posMove(position, adjustment * count);
         if (posMove.isValid() && (position.hasWrapped(moves[i].row * count, moves[i].col * count, posMove)) && 
            (board[posMove.getLocation()]->getLetter() == 'u' ||
            board[posMove.getLocation()]->isWhite() != fWhite))
         {
            queenMoves.insert(posMove.getLocation());
            if (board[posMove.getLocation()]->getLetter() != 'u')
            {
               r = 100;
            }
         }
         else
            r = 100;

         r += moves[i].row;
         c += moves[i].col;
         count++;
      }
   }
      return queenMoves;
};

/*************************************
* DISPLAY
* Draw the Queen
*************************************/
void Queen::display(ogstream& gout)
{
   gout.drawQueen(position.getLocation(), fWhite);
};