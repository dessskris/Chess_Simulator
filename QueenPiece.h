#ifndef QUEENPIECE_H
#define QUEENPIECE_H

#include <cmath>
#include <string>
#include "helper.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

using namespace std;

class QueenPiece : public ChessPiece {
 public:
  QueenPiece(Colour _c, ChessBoard *_b);
  virtual ~QueenPiece();

  // The queen can move any number of squares along rank, file, or diagonal, but it may not leap over other pieces.
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

#endif
