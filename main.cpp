/***********************************************************************
 * Chess Game
 * Author(s):
 *   Ben, Star, and Mike
 * Summary:
 *    Allows users to take turns playing a game of Chess.
 ************************************************************************/

#include "uiInteract.h"
#include "board.h"
#include <set>
#include <iostream>
using namespace std;

/*************************************
 * CALLBACK
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
   pBoard->display(*pUI, possible);

}


/*********************************
 * MAIN
 * Main is calls the display engine 
 * and callback
 *********************************/
int main()
{
   Interface ui("Chess");
   Board board;

   //Set Board to Void Pointer to pass into Callback
   void* p;
   p = &board;

   //Run CallBack
   ui.run(callBack, p);

   return 0;
}

