#include "test.h"
#include "testpawn.h"
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
   cout << "Success!\n";
}