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
        {-9},{-7}
   };
   M2 moveStruct2[4] =
    {
     {-1,  1}, {1,  1},
     {-1, -1}, {1, -1}
    };


   Position posMove(position, 0);
   //OWN FUNCTION
   // 
   // 
   // 
   //for (int i = 0; i < 4; i++)
   //{
   //   //cout << moveStruct[i].move << endl;
   //   
   //   posMove.setLocation(position.getLocation() + moveStruct[i].move);

   //   if (posMove.isValid() && (board[posMove.getLocation()]->getLetter() == 'u' || board[posMove.getLocation()]->isWhite() != fWhite))
   //   {
   //      bishopMoves.insert(posMove.getLocation());
   //   }

   //   while (posMove.isValid(moveStruct[i].move) &&
   //    board[posMove.getLocation()]->getLetter() == 'u' )
   //   {
   //      if (board[posMove.getLocation()]->isWhite() != fWhite || board[posMove.getLocation()]->getLetter() == 'u')
   //      {
   //         cout <<"COLOR: " << board[posMove.getLocation()]->isWhite() << endl;
   //         posMove.addLocation(moveStruct[i].move);
   //         bishopMoves.insert(posMove.getLocation());
   //      }
   //   }
   //}
   for (int i = 0; i < 4; i++)
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
            bishopMoves.insert(posMove.getLocation());
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