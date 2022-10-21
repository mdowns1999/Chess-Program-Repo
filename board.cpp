/***********************************************************************
 * Header File:
 *    Board : The Board of Chess
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    This keeps track of the chess board.
 ************************************************************************/
#include "board.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"


Board::Board()
{
   for (int i = 0; i < 64; i++)
   {
      int r = i / 8 + 1;
      int c = i % 8;

      Piece* piece = new Piece(r, c, true);
      board[i] = piece;
   }

   //SET CHESS PIECES
   //WHITE PIECES
   Rook* pWRook1 = new Rook(8, 7, false);
   board[pWRook1->getPosition().getLocation()] = pWRook1;
   Knight* pWKnight1 = new Knight(8, 6, false);
   board[pWKnight1->getPosition().getLocation()] = pWKnight1;
   Bishop* pWBishop1 = new Bishop(8, 5, false);
   board[pWBishop1->getPosition().getLocation()] = pWBishop1;
   King* pWKing = new King(8, 4, false);
   board[pWKing->getPosition().getLocation()] = pWKing;
   Queen* pWQueen = new Queen(8, 3, false);
   board[pWQueen->getPosition().getLocation()] = pWQueen;
   Bishop* pWBishop2 = new Bishop(8, 2, false);
   board[pWBishop2->getPosition().getLocation()] = pWBishop2;
   Knight* pWKnight2 = new Knight(8, 1, false);
   board[pWKnight2->getPosition().getLocation()] = pWKnight2;
   Rook* pWRook2 = new Rook(8, 0, false);
   board[pWRook2->getPosition().getLocation()] = pWRook2;

   //Generate Pawns
   for (int i = 0; i < 8; i++)
   {
      Pawn* pPawn = new Pawn(7, i, false);
      board[pPawn->getPosition().getLocation()] = pPawn;
   }



   //BLACK PIECES
   King* pBKing = new King(1, 4, true);
   board[pBKing->getPosition().getLocation()] = pBKing;
   //Queen was at r 1
   Queen* pBQueen = new Queen(1, 3, true);
   board[pBQueen->getPosition().getLocation()] = pBQueen;
   Bishop* pbBishop1 = new Bishop(1, 2, true);
   board[pbBishop1->getPosition().getLocation()] = pbBishop1;
   Bishop* pbBishop2 = new Bishop(1, 5, true);
   board[pbBishop2->getPosition().getLocation()] = pbBishop2;
   Rook* pBRook1 = new Rook(1, 7, true);
   board[pBRook1->getPosition().getLocation()] = pBRook1;
   Rook* pBRook2 = new Rook(1, 0, true);
   board[pBRook2->getPosition().getLocation()] = pBRook2;
   Knight* pBKnight1 = new Knight(1, 1, true);
   board[pBKnight1->getPosition().getLocation()] = pBKnight1;
   Knight* pBKnight2 = new Knight(1, 6, true);
   board[pBKnight2->getPosition().getLocation()] = pBKnight2;

   //Generate Pawns
   for (int i = 0; i < 8; i++)
   {
      Pawn* pPawn = new Pawn(2, i, true);
      board[pPawn->getPosition().getLocation()] = pPawn;
   }

};

/*****************************************************************
 * DISPLAY
 * Display Board
 ****************************************************************/
void Board::display(Interface& ui, set <int> possible)
{
   ogstream gout;

   // draw the checkerboard
   gout.drawBoard();

   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());

   // draw the possible moves
   set <int> ::iterator it;
   for (it = possible.begin(); it != possible.end(); ++it)
      gout.drawPossible(*it);

   //array<Piece*>::iterator itPiece;
   for (int itPiece = 0; itPiece < 64; ++itPiece)
   {
      board[itPiece]->display(gout);
   }
};

/*****************************************************************
 * MOVE
 * Move the Piece
 ****************************************************************/
bool Board::move(int positionFrom, int positionTo)
{
   // do not move if a move was not indicated
   if (positionFrom == -1 || positionTo == -1)
      return false;

   // find the set of possible moves from our current location
   set <int> possiblePrevious = board[positionFrom]->getMoves(board);

   // only move there is the suggested move is on the set of possible moves
   if (possiblePrevious.find(positionTo) != possiblePrevious.end())
   {
      //Swap normal moves.
      swap(positionFrom, positionTo);

      //If we are going to Capture someone
      capture(positionFrom);

      //Can the piece Promote?
      if ((board[positionTo]->getPosition().getRow() == 1 
      || board[positionTo]->getPosition().getRow() == 8) 
      && (board[positionTo]->getLetter() == 'P' || 
      board[positionTo]->getLetter() == 'p'))
      {
          addPromotion(positionTo);
      }

      //Enpassant
          if (board[positionTo]->getEmpassant())
          {
             //Based off the color will determine the direction of the pawn.
             int direction = board[positionTo]->isWhite() ? -8 : 8;

             int row = board[positionTo]->getPosition().getRow() - 1;
             int col = board[positionTo]->getPosition().getColumn() - 1;

             Piece* pPiece = new Piece(row, col, true);

             delete board[positionTo + direction];
             board[positionTo + direction] = pPiece;
          }

       //King Side Castle Move
         if((board[positionTo]->getLetter() == 'k'  && positionTo == 62) 
         || (board[positionTo]->getLetter() == 'K' && positionTo == 6))
         {
            swap(positionTo + 1, positionTo - 1);
         }

         //Queen Side Castle
         if((board[positionTo]->getLetter() == 'k'  && positionTo == 58) 
         || (board[positionTo]->getLetter() == 'K' && positionTo == 2))
         {
            swap(positionTo + 1, positionTo - 2);
         }


      currentMove++;
      return true;
   }
   return false;

};


/*****************************************************************
 * SWAP
 * Swap the Pieces
 ****************************************************************/
void Board::swap(int positionFrom, int positionTo)
{
   //Swap locations of the objects
   Position storePos = board[positionFrom]->getPosition();
   board[positionFrom]->assign(board[positionTo]->getPosition());
   board[positionTo]->assign(storePos);

   // Swap Pointers
   Piece* storePiece = board[positionTo];
   board[positionTo] = board[positionFrom];
   board[positionFrom] = storePiece;


};

/*****************************************************************
 * CAPTURE
 ****************************************************************/
void Board::capture(int positionFrom)
{
   //If the space is unoccupied, then we kill the piece.
   if (board[positionFrom]->getLetter() != 'u')
   {
      int row = board[positionFrom]->getPosition().getRow();
      int col = board[positionFrom]->getPosition().getColumn() - 1;
      Piece* pPiece = new Piece(row, col, true);

      // Delete old object
      delete board[positionFrom];
      board[positionFrom] = pPiece;
   }
};

void Board::addPromotion(int positionTo)
{

   int row2 = board[positionTo]->getPosition().getRow();
   int col2 = board[positionTo]->getPosition().getColumn() - 1;

   Piece* pQiece = new Queen(row2, col2, board[positionTo]->isWhite());

   delete board[positionTo];
   board[positionTo] = pQiece;

};