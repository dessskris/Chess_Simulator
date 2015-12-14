#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <cmath>
#include <string>
#include "helper.h"

using namespace std;

class ChessBoard;

class ChessPiece {
 protected:
  Type type;
  Colour colour;
  ChessBoard *board;

  // Helper function to check if moving to SQUARE will capture a piece
  // and signals the board. Note the captured piece may be of the same colour
  bool check_capture(const string square);

  // Helper function to check if SQUARE in board is empty
  bool is_empty(const string square);

 public:
  ChessPiece(Type _t, Colour _c, ChessBoard *_b);
  virtual ~ChessPiece();

  Colour get_colour();
  string print_colour();

  Type get_type();
  string print_type();

  string get_symbol(); // Used in print_board()

  /* Virtual function to check if this piece can potentially move from
     SOURCE_SQUARE to DESTINATION_SQUARE.
     Note:
     - Both squares are assumed to be valid squares
     - It is not taken into account whether its own King will be in check
       after this move
     - This function does not make the move */
  virtual bool is_valid_move(const string source_square, const string destination_square) = 0;
};

#endif
