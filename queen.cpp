#include "queen.h"

/*************************************
CONSTRUCTOR
Set up the Pieces attributes
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
Get the Pieces Letter
*************************************/
char Queen::getLetter()
{
   return letter;
}

//virtual void display() {};

/*************************************
GET MOVES
Get the Moves for the Chess Piece
*************************************/
set<int> Queen::getMoves(Board& board)
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
      //cout << moveStruct[i].move << endl;
      
      posMove.setLocation(position.getLocation() + moveStruct[i].move);

      if (posMove.isValid() && (board.getBoard()[posMove.getLocation()]->getLetter() == 'u' || board.getBoard()[posMove.getLocation()]->isWhite() != fWhite))
      {
         queenMoves.insert(posMove.getLocation());
      }

      while (posMove.isValid(moveStruct[i].move) &&
       board.getBoard()[posMove.getLocation()]->getLetter() == 'u' )
      {
         if (board.getBoard()[posMove.getLocation()]->isWhite() != fWhite || board.getBoard()[posMove.getLocation()]->getLetter() == 'u')
         {
            cout <<"COLOR: " << board.getBoard()[posMove.getLocation()]->isWhite() << endl;
            posMove.addLocation(moveStruct[i].move);
            queenMoves.insert(posMove.getLocation());
         }
      }
   }
      return queenMoves;
};

/*************************************
DISPLAY
Draw the Piece
*************************************/
void Queen::display(ogstream& gout)
{
   gout.drawQueen(position.getLocation(), fWhite);
};