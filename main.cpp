#include "uiInteract.h"
#include "board.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"

//#include "move.h" //REMOVE LATER??
#include <set>
#include <iostream>
using namespace std;

/***************************************************
//  * DRAW
//  * Draw the current state of the game
//  ***************************************************/
void draw( Piece** board, const Interface& ui, const set <int>& possible)
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

}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface* pUI, void *p)
{

   set <int> possible;
   Board* pBoard = (Board*)p;

   bool whiteTurn = pBoard->whiteTurn();
   //This will get the user's Selected Position
   int prevLocation = pUI->getPreviousPosition();
   int currLocation = pUI->getSelectPosition();

   // move the piece based on turn.
   if (pBoard->move(prevLocation, currLocation))
      pUI->clearSelectPosition();
   else if (currLocation != -1)
      if (pBoard->getBoard()[currLocation]->isWhite() != whiteTurn)
         possible = pBoard->getBoard()[currLocation]->getMoves(pBoard->getBoard());

   // if we clicked on a blank spot, then it is not selected
   if (currLocation != -1 && pBoard->getBoard()[currLocation]->getLetter() == 'u')
      pUI->clearSelectPosition();

   // draw the board
   draw(pBoard->getBoard(), *pUI, possible);

}


/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/

int main()
{
   Interface ui("Chess");
   Board board;

   //SET CHESS PIECES
   //WHITE PIECES
   //new Rook(8, 7, false)
   Rook* pWRook1 = new Rook(5, 4, false);
   board.getBoard()[pWRook1->getPosition().getLocation()] = pWRook1;
   Knight* pWKnight1 = new Knight(8, 6, false);
   board.getBoard()[pWKnight1->getPosition().getLocation()] = pWKnight1;
   Bishop* pWBishop1 = new Bishop(8, 5, false);
   board.getBoard()[pWBishop1->getPosition().getLocation()] = pWBishop1;
   King* pWKing = new King(8, 4, false);
   board.getBoard()[pWKing->getPosition().getLocation()] = pWKing;
   Queen* pWQueen = new Queen(8, 3, false);
   board.getBoard()[pWQueen->getPosition().getLocation()] = pWQueen;
   Bishop* pWBishop2 = new Bishop(8, 2, false);
   board.getBoard()[pWBishop2->getPosition().getLocation()] = pWBishop2;
   Knight* pWKnight2 = new Knight(8, 1, false);
   board.getBoard()[pWKnight2->getPosition().getLocation()] = pWKnight2;
   Rook* pWRook2 = new Rook(8, 0, false);
   board.getBoard()[pWRook2->getPosition().getLocation()] = pWRook2;

   //Generate Pawns
   for(int i = 0; i < 8; i++)
   {
      Pawn* pPawn = new Pawn(7, i, false);
      board.getBoard()[pPawn->getPosition().getLocation()] = pPawn;  
   }

 

   //BLACK PIECES
   King* pBKing = new King(1, 4, true);
   board.getBoard()[pBKing->getPosition().getLocation()] = pBKing;
   //Queen was at r 1
   Queen* pBQueen = new Queen(1, 3, true);
   board.getBoard()[pBQueen->getPosition().getLocation()] = pBQueen;
   Bishop* pbBishop1 = new Bishop(1, 2, true);
   board.getBoard()[pbBishop1->getPosition().getLocation()] = pbBishop1;
   Bishop* pbBishop2 = new Bishop(1, 5, true);
   board.getBoard()[pbBishop2->getPosition().getLocation()] = pbBishop2;
   Rook* pBRook1 = new Rook(1, 7, true);
   board.getBoard()[pBRook1->getPosition().getLocation()] = pBRook1;
   Rook* pBRook2 = new Rook(1, 0, true);
   board.getBoard()[pBRook2->getPosition().getLocation()] = pBRook2;
   Knight* pBKnight1 = new Knight(1, 1, true);
   board.getBoard()[pBKnight1->getPosition().getLocation()] = pBKnight1;
   Knight* pBKnight2 = new Knight(1, 6, true);
   board.getBoard()[pBKnight2->getPosition().getLocation()] = pBKnight2;
  
   //Generate Pawns
    for (int i = 0; i < 8; i++)
    {
       Pawn* pPawn = new Pawn(2, i, true);
       board.getBoard()[pPawn->getPosition().getLocation()] = pPawn;
    }

   //Set Board to Void Pointer to pass into Callback
   void* p;
   p = &board;

   //Run CallBack
   ui.run(callBack, p);

   return 0;
}


