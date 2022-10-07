/***********************************************************************
 * Header File:
 *    Test Pawn : Test the Pawn class
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    All the unit tests for Pawn
 ************************************************************************/

 /*********************************************
 * * * A  B  C  D  E  F  G  H * *
 * 8   57 58 59 60 61 62 63 64
 * 7   49 50 51 52 53 54 55 56
 * 6   41 42 43 44 45 46 47 48
 * 5   33 34 35 36 37 38 39 40
 * 4   25 26 27 28 29 30 31 32
 * 3   17 18 19 20 21 22 23 24
 * 2   9  10 11 12 13 14 15 16
 * 1   1  2  3  4  5  6  7  8  * *
 **********************************************/


#pragma once
#include "pawn.h"
#include "cassert"
#include <set>

class testPawn
{
public:
   void run()
   {
      getLetterTest_P();
      getLetterTest_p();

      //getMovesTest_noMove();
      //getMovesTest_simpleMove();
      //getMovesTest_capture();
      //getMovesTest_empassant();
      //getMovesTest_promotion();

   }
private:

   // test the getLetter for the pawn class 
   void getLetterTest_P() const
   {
      // setup
      Pawn p(1, 2, true);
      char letter;

      // exercise
      letter = p.getLetter();

      // verify
      assert(letter == 'P');
   }  // teardown

   void getLetterTest_p() const
   {
      // setup
      Pawn p(1, 2, false);
      char letter;

      // exercise
      letter = p.getLetter();

      // verify
      assert(letter == 'p');
   }  // teardown

   // test the getMoves for the pawn class 
  /*********************************************
  * * * A  B  C  D  E  F  G  H * *
  * 8   57 58 59 60 61 62 63 64
  * 7   49 50 51 52 53 54 55 56
  * 6   41 42 43 44 45 46 47 48
  * 5   33 34 35 36 37 38 39 40
  * 4   25 26 27 28 29 30 31 32
  * 3   17 18 P1 P2 P3 22 23 24
  * 2   9  10 11 *  13 14 15 16
  * 1   1  2  3  4  5  6  7  8  * *
  **********************************************/
   void getMovesTest_noMove() const
   {
      // setup
      Pawn p(2, 4, true); // *: main pawn 
      Pawn p1(3, 3, true); // P: Blocking 
      Pawn p2(3, 4, true); // P: Blocking
      Pawn p3(3, 5, true); // P: Blocking
      set <int> moves;
      // exercise
      moves = p.getMoves();

      // verify
      assert(moves.empty());

   }  // teardown

  /*********************************************
  * * * A  B  C  D  E  F  G  H * *
  * 8   57 58 59 60 61 62 63 64
  * 7   49 50 51 52 53 54 55 56
  * 6   41 42 43 44 45 46 47 48
  * 5   33 34 35 36 37 38 39 40
  * 4   25 26 27 P2 29 30 31 32
  * 3   17 18 P1 20 P3 22 23 24
  * 2   9  10 11 *  13 14 15 16
  * 1   1  2  3  4  5  6  7  8  * *
  **********************************************/
   void getMovesTest_simpleMove() const
   {
      // setup
      Pawn p(2, 4, true); // *: main pawn 
      Pawn p1(3, 3, true); // P: Blocking 
      Pawn p2(4, 4, true); // P: Blocking
      Pawn p3(3, 5, true); // P: Blocking
      set <int> moves;

      // exercise
      moves = p.getMoves();

      // verify
      assert(moves.find(20) != moves.end());
   }  // teardown

  /*********************************************
  * * * A  B  C  D  E  F  G  H * *
  * 8   57 58 59 60 61 62 63 64
  * 7   49 50 51 52 53 54 55 56
  * 6   41 42 43 44 45 46 47 48
  * 5   33 34 35 36 37 38 39 40
  * 4   25 26 27 28 29 30 31 32
  * 3   17 18 P1 P2 p3 22 23 24
  * 2   9  10 11 *  13 14 15 16
  * 1   1  2  3  4  5  6  7  8  * *
  **********************************************/
   void getMovesTest_capture() const
   {
      // setup
      Pawn p(2, 4, true); // *: main pawn 
      Pawn p1(3, 3, true); // P: Blocking 
      Pawn p2(3, 4, true); // P: Blocking
      Pawn p3(3, 5, false); // P: Enemy
      set <int> moves;

      // exercise
      moves = p.getMoves();

      // verify
      assert(moves.find(21) != moves.end());
      assert(moves.size() == 1);

   }  // teardown

  /*********************************************
  * * * A  B  C  D  E  F  G  H * *
  * 8   57 58 59 60 61 62 63 64
  * 7   49 50 51 52 53 54 55 56
  * 6   41 42 43 P1 P2 46 47 48
  * 5   33 34 35 36 *  p3 39 40
  * 4   25 26 27 28 29 30 31 32
  * 3   17 18 19 20 21 22 23 24
  * 2   9  10 11 12 13 14 15 16
  * 1   1  2  3  4  5  6  7  8  * *
  **********************************************/
   void getMovesTest_empassant() const
   {
      // setup
      Pawn p(5, 5, true); // *: main pawn 
      Pawn p1(6, 4, true); // P: Blocking 
      Pawn p2(6, 5, true); // P: Blocking
      Pawn p3(5, 6, false); // P: Enemy
      set <int> moves;
      // exercise
      moves = p.getMoves();

      // verify
      assert(moves.find(21) != moves.end());
      assert(moves.size() == 1);

   }  // teardown

  /*********************************************
  * * * A  B  C  D  E  F  G  H * *
  * 8   57 58 59 60 61 62 63 64
  * 7   49 50 51 52 53 54 55 56
  * 6   41 42 43 44 45 46 47 48
  * 5   33 34 35 36 37 38 39 40
  * 4   25 26 27 28 29 30 31 32
  * 3   17 18 19 20 21 22 23 24
  * 2   9  10 11 *  13 14 15 16
  * 1   1  2  3  4  5  6  7  8  * *
  **********************************************/
   void getMovesTest_promotion() const
   {
      // setup
      Pawn p(2, 4, false); // *: main pawn 
      set <int> moves;
      // exercise
      moves = p.getMoves();

      // verify
      assert(moves.find(4) != moves.end());

   }  // teardown

};

