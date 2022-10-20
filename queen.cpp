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
   M2 moveStruct2[8] =
             {
                {-1,  1}, {0,  1}, {1,  1},
                {-1,  0},          {1,  0},
                {-1, -1}, {0, -1}, {1, -1}
             };


   Position posMove(position, 0);
   //OWN FUNCTION
   for (int i = 0; i < 8; i++)
   {
      //       for (int i = 0; i < 4; i++)
//       {
//          r = row + moves[i].row;
//          c = col + moves[i].col;
//          while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
//             board[r * 8 + c] == ' ')
//          {
//             possible.insert(r * 8 + c);
//             r += moves[i].row;
//             c += moves[i].col;
//          }

      int r = position.getRow();
      int c = position.getColumn();
      int count = 1;
      Position posMove(position, moveStruct[i].move);
      //r >= 0 && r < 9 && c >= 0 && c < 8
      while (r >= 0 && r < 9 && c >= 0 && c < 9)
      {
         Position posMove(position, moveStruct[i].move * count);
         cout << "newPosition R: " << r << endl;
         cout << "newPosition C: " << c << endl;
         if (posMove.isValid() && (position.hasWrapped(moveStruct2[i].row * count, moveStruct2[i].col * count, posMove)) && (board[posMove.getLocation()]->getLetter() == 'u' ||
            board[posMove.getLocation()]->isWhite() != fWhite))
         {
            queenMoves.insert(posMove.getLocation());
            cout << "Valid locations" << posMove.getLocation() << endl;
            if (board[posMove.getLocation()]->getLetter() != 'u')
            {
               r = 100;
            }
         }
         else
            r = 100;
         //posMove.setRow(posMove.getRow() + moveStruct2[i].row);
         //posMove.setCol(posMove.getColumn() + moveStruct2[i].col);
         r += moveStruct2[i].row;
         c += moveStruct2[i].col;
         count++;
      }
   }

  /* for (int i = 0; i < 8; i++)
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
   }*/
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