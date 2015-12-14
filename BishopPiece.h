#ifndef BISHOPPIECE_H
#define BISHOPPIECE_H

#include <cmath>
#include <string>
#include "helper.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

using namespace std;

class BishopPiece : public ChessPiece {
 public:
  BishopPiece(Colour _c, ChessBoard *_b);
  virtual ~BishopPiece();

  // The bishop can move any number of squares diagonally, but may not leap over other pieces.
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

#endif
