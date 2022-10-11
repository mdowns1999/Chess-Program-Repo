#include "uiInteract.h"
#include "board.h"
#include "pawn.h"
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

   for (int itPiece1 = 0; itPiece1 < 64; ++itPiece1)
   {
      cout << board[itPiece1]->getLetter() << endl;
   }


   // draw the pieces
   // for (int i = 0; i < 64; i++)
   //    switch (board[i])
   //    {
   //    case 'P':
   //       gout.drawPawn(i, true);
   //       break;
   //    case 'p':
   //       gout.drawPawn(i, false);
   //       break;
   //    case 'K':
   //       gout.drawKing(i, true);
   //       break;
   //    case 'k':
   //       gout.drawKing(i, false);
   //       break;
   //    case 'Q':
   //       gout.drawQueen(i, true);
   //       break;
   //    case 'q':
   //       gout.drawQueen(i, false);
   //       break;
   //    case 'R':
   //       gout.drawRook(i, true);
   //       break;
   //    case 'r':
   //       gout.drawRook(i, false);
   //       break;
   //    case 'B':
   //       gout.drawBishop(i, true);
   //       break;
   //    case 'b':
   //       gout.drawBishop(i, false);
   //       break;
   //    case 'N':
   //       gout.drawKnight(i, true);
   //       break;
   //    case 'n':
   //       gout.drawKnight(i, false);
   //       break;
   //    }
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

   void* p;
   p = &board;
   Pawn pawn(2, 4, true); 
   board.getBoard()[pawn.getPosition().getLocation()] = &pawn;


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


