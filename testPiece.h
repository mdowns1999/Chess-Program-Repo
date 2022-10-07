/***********************************************************************
 * Header File:
 *    Test Position : Test the Piece class
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    All the unit tests for Piece
 ************************************************************************/


#pragma once
#include "piece.h"
#include "position.h"
#include <cassert>
#include <iostream>
using namespace std;

class testPiece
{
public:
   void run()
   {
      //Run the Test Methods
      nonDefaultConstructorTest();

      assign_PositionTest();

      assign_PieceTest();

      isWhiteTest_white();
      isWhiteTest_black();

      isMoveTest_nonMoved();
      isMoveTest_Moved();

      getNMovesTest_noMoves();
      getNMovesTest_moved();

      getPositionTest();

      justMovedTest_true();
      justMovedTest_false();

   }
private:
   // test the non-default constructor for the piece class 
   void nonDefaultConstructorTest() const
   {
      // setup
      // exercise
      Piece p(1, 2, true);

      // verify
      assert(p.r == 1);
      assert(p.c == 2);
      assert(p.fWhite == true);

   }  // teardown

   // create a piece with a position, assign position to new location then
   // check the location
   void assign_PositionTest() const
   {
      // setup
      Piece p(1, 2, true);
      Position pos;
      pos.location = 2;
      // exercise
      p.assign(pos);
      // verify
      cout << p.position.location << endl;
      assert(p.position.location == 2);

   }  // teardown

   // testing assign_PieceTest using the assign method
   void assign_PieceTest() const
   {
      // setup
      Piece p(1, 2, true);
      Piece p2(2, 2, false);
      // exercise
      p.assign(p2);
      // verify
      assert(p.position.location == p2.position.location);
      assert(p.fWhite == false);
   }  // teardown

   // Testing isWhite with the following methods
   void isWhiteTest_white() const
   {
      // setup
      Piece p(2, 2, true);
      // exercise
      p.isWhite();
      // verify
      assert(p.fWhite == true);
   } // teardown

   void isWhiteTest_black() const
   {
      // setup
      Piece p(2, 2, false);
      // exercise
      p.isWhite();
      // verify
      assert(p.fWhite == false);
   } // teardown

   // Testing isMove with the following methods
   void isMoveTest_nonMoved() const
   {
      // setup
      Piece p(1, 2, true);
      bool isMoved;
      // exercise
      isMoved = p.isMove();
      // verify
      assert(isMoved == false);
   }  // teardown

   void isMoveTest_Moved() const
   {
      // setup
      Piece p(1, 2, true);
      Position pos;
      pos.location = 10;
      p.assign(pos);
      bool isMoved;

      // exercise
      isMoved = p.isMove();
      // verify
      assert(isMoved == true);
   }  // teardown

   // Testing getNMoves with following methods.
   void getNMovesTest_noMoves() const
   {
      // setup
      Piece p(1, 2, true);
      int moves;

      // exercise
      moves = p.getNMoves();

      // verify
      assert(moves == 0);
   }  // teardown

   void getNMovesTest_moved() const
   {
      // setup
      Piece p(1, 2, true);
      int moves;
      Position pos;
      pos.location = 10;
      p.assign(pos);
      pos.location = 18;
      p.assign(pos);

      // exercise
      moves = p.getNMoves();

      // verify
      assert(moves == 2);
   }  // teardown

   // Test for getPosition
   void getPositionTest() const
   {
      // setup
      Piece p(1, 2, true);
      Position pos;

      // exercise
      pos = p.getPosition();

      // verify
      assert(pos.location == p.position.location);

   }  // teardown

   // Testing justMoved with the following methods
   void justMovedTest_true() const
   {
      // setup
      Piece p(6, 2, true);
      Position pos;
      pos.location = 10;
      p.assign(pos);
      bool isMoved;

      // exercise
      isMoved = p.isMove();
      // verify
      assert(isMoved == true);

   }  // teardown

   void justMovedTest_false() const
   {
      // setup
      Piece p(1, 2, true);
      bool isMoved;
      // exercise
      isMoved = p.isMove();
      // verify
      assert(isMoved == false);
   }  // teardown

};
