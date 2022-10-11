#include "test.h"
#include "testPawn.h"
//#include "board.h"
#include "testPiece.h"
#include <iostream>
using namespace std;

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   testPawn().run();
   testPiece().run();

}

int main()
{
   testRunner();
   cout << "Success!\n";
   return 0;
}