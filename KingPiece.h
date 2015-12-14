#ifndef KINGPIECE_H
#define KINGPIECE_H

#include <cmath>
#include <string>
#include "helper.h"
#include "ChessPiece.h"

using namespace std;

class KingPiece : public ChessPiece {
 public:
  KingPiece(Colour _c, ChessBoard *_b);
  virtual ~KingPiece();

  // The king moves one square in any direction
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

#endif
