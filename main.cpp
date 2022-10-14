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

/*********************************************
 * MOVE
 * Execute one movement. Return TRUE if successful
 *********************************************/
bool move(Board* board, int positionFrom, int positionTo)
{
   // do not move if a move was not indicated
   if (positionFrom == -1 || positionTo == -1)
     return false;

   // find the set of possible moves from our current location
   set <int> possiblePrevious = board->getBoard()[positionFrom]->getMoves(*board);

   // only move there is the suggested move is on the set of possible moves
   if (possiblePrevious.find(positionTo) != possiblePrevious.end())
   {
      cout << "POSITION FROM:" << positionFrom << endl;
      cout << "POSITION TO:" << positionTo << endl;
      cout << "Old piece: " << board->getBoard()[positionTo]->getPosition().getLocation() << endl;
     board->getBoard()[positionFrom]->assign(board->getBoard()[positionTo]->getPosition());
     board->getBoard()[positionTo] = board->getBoard()[positionFrom];

     int r = board->getBoard()[positionFrom]->getPosition().getLocation() / 8 + 1;
     int c = board->getBoard()[positionFrom]->getPosition().getLocation() % 8 + 1;

     cout << r << endl;
     cout << c << endl;

     board->getBoard()[positionFrom] = new Piece(r, c, true);

     return true;
   }

   return false;

}

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

   // for (int itPiece1 = 0; itPiece1 < 64; ++itPiece1)
   // {
   //    cout << board[itPiece1]->getLetter() << endl;
   // }

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
   //This will get the user's Selected Position
   int prevLocation = pUI->getPreviousPosition();
   int currLocation = pUI->getSelectPosition();


      // move 
      if (move(pBoard, prevLocation, currLocation))
         pUI->clearSelectPosition();
      else if (currLocation != -1)
         possible = pBoard->getBoard()[currLocation]->getMoves(*pBoard);

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
   Rook wRook1(8, 7, false);
   board.getBoard()[wRook1.getPosition().getLocation()] = &wRook1;
   Knight wKnight1(8, 6, false);
   board.getBoard()[wKnight1.getPosition().getLocation()] = &wKnight1;
   Bishop wBishop1(8, 5, false);
   board.getBoard()[wBishop1.getPosition().getLocation()] = &wBishop1;
   King wKing(8, 4, false);
   board.getBoard()[wKing.getPosition().getLocation()] = &wKing;
   Queen wQueen(8, 3, false);
   board.getBoard()[wQueen.getPosition().getLocation()] = &wQueen;
   Bishop wBishop2(8, 2, false);
   board.getBoard()[wBishop2.getPosition().getLocation()] = &wBishop2;
   Knight wKnight2(8, 1, false);
   board.getBoard()[wKnight2.getPosition().getLocation()] = &wKnight2;
   Rook wRook2(4, 4, false);
   board.getBoard()[wRook2.getPosition().getLocation()] = &wRook2;

   for(int i = 0; i < 8; i++)
   {
      Pawn* pPawn = new Pawn(7, i, false);
      board.getBoard()[pPawn->getPosition().getLocation()] = pPawn;  
   }

 

   //BLACK PIECES
   King bKing(1, 4, true);
   board.getBoard()[bKing.getPosition().getLocation()] = &bKing;
   Queen bQueen(1, 3, true);
   board.getBoard()[bQueen.getPosition().getLocation()] = &bQueen;
   Bishop bBishop1(1, 2, true);
   board.getBoard()[bBishop1.getPosition().getLocation()] = &bBishop1;
   Bishop bBishop2(1, 5, true);
   board.getBoard()[bBishop2.getPosition().getLocation()] = &bBishop2;
   Rook bRook1(1, 7, true);
   board.getBoard()[bRook1.getPosition().getLocation()] = &bRook1;
   Rook bRook2(1, 0, true);
   board.getBoard()[bRook2.getPosition().getLocation()] = &bRook2;
   Knight bKnight1(1, 1, true);
   board.getBoard()[bKnight1.getPosition().getLocation()] = &bKnight1;
   Knight bKnight2(1, 6, true);
   board.getBoard()[bKnight2.getPosition().getLocation()] = &bKnight2;
  
  
   for (int i = 0; i < 8; i++)
   {
      Pawn* pPawn = new Pawn(2, i, true);
      board.getBoard()[pPawn->getPosition().getLocation()] = pPawn;
   }
   


















   void* p;
   p = &board;

   Pawn pawn(2, 4, true);
   cout << pawn.getPosition().getLocation() << endl;
   board.getBoard()[pawn.getPosition().getLocation()] = &pawn;

   Pawn pawn2(7, 5, false);
   board.getBoard()[pawn2.getPosition().getLocation()] = &pawn2;


   // Initialize the game class
   // note this is upside down: 0 row is at the bottom
   //char board[64] = {
   //   'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
   //   'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
   //   'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   //};


   // set everything into action
   //ui.run(callBack, board.getBoard());
   ui.run(callBack, p);

   return 0;
}


