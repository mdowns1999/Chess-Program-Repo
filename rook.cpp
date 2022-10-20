/***********************************************************************
 * Source File:
 *    Knight
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is code handles all the specifics of Rook.  Rook can slide forward or sideways.
 ************************************************************************/
#include "rook.h"

/*************************************
CONSTRUCTOR
Set up the Rook attributes
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
Get the Rook Letter
*************************************/
char Rook::getLetter()
{
   return letter;
}

/*************************************
GET MOVES
Get the Moves for the Rook
*************************************/
set<int> Rook::getMoves(Piece** board)
{
   set<int> rookMoves;

   M moveStruct[4] =
   {
          {8},{-1},{1},{-8}
   };
   M2 moveStruct2[4] =
   {
                         {0,  1},
                {-1, 0},         {1, 0},
                         {0, -1}
   };
   
   //Position posMove(position, 0);
   //OWN FUNCTION
   for (int i = 0; i < 4 ; i++)
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
            rookMoves.insert(posMove.getLocation());
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



































   //for (int i = 0; i < 4; i++)
   //{
   //   posMove.setLocation(position.getLocation() + moveStruct[i].move);

   //   /*if (posMove.isValid() && (board[posMove.getLocation()]->getLetter() == 'u' || 
   //      board[posMove.getLocation()]->isWhite() != fWhite))
   //   {
   //      rookMoves.insert(posMove.getLocation());
   //   }

   //   while (posMove.isValid(moveStruct[i].move) &&
   //    board[posMove.getLocation()]->getLetter() == 'u'  )
   //   {
   //      if (board[posMove.getLocation()]->isWhite() != fWhite || 
   //         board[posMove.getLocation()]->getLetter() == 'u')
   //      {
   //         cout <<"COLOR: " << board[posMove.getLocation()]->isWhite() << endl;
   //         posMove.addLocation(moveStruct[i].move);
   //         rookMoves.insert(posMove.getLocation());
   //      }
   //   }*/


   //   // position.getLocation() + (moveStruct[i].move * j) >= 0 && position.getLocation() + (moveStruct[i].move * j) <= 63 
   //}

   return rookMoves;
};

/*************************************
DISPLAY
Draw the Rook
*************************************/
void Rook::display(ogstream& gout)
{
   gout.drawRook(position.getLocation(), fWhite);
};