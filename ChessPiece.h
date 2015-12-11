#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include "helper.h"
#include "ChessBoard.h"

using namespace std;

class ChessBoard;

class ChessPiece {
 protected:
  Type type;
  Colour colour;
  ChessBoard *board;
 public:
  ChessPiece(Type _t, Colour _c, ChessBoard *_b);
  virtual ~ChessPiece();
  Colour get_colour();
  string print_colour();
  string print_type();
  string get_symbol();
  virtual bool is_valid_move(const string source_square, const string destination_square) = 0;
  bool is_empty(const string square);
};


class KingPiece : public ChessPiece {
 public:
  KingPiece(Colour _c, ChessBoard *_b);
  virtual ~KingPiece();
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

class QueenPiece : public ChessPiece {
 public:
  QueenPiece(Colour _c, ChessBoard *_b);
  virtual ~QueenPiece();
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

class BishopPiece : public ChessPiece {
 public:
  BishopPiece(Colour _c, ChessBoard *_b);
  virtual ~BishopPiece();
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

class KnightPiece : public ChessPiece {
 public:
  KnightPiece(Colour _c, ChessBoard *_b);
  virtual ~KnightPiece();
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

class RookPiece : public ChessPiece {
 public:
  RookPiece(Colour _c, ChessBoard *_b);
  virtual ~RookPiece();
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

class PawnPiece : public ChessPiece {
 public:
  PawnPiece(Colour _c, ChessBoard *_b);
  virtual ~PawnPiece();
  virtual bool is_valid_move(const string source_square, const string destination_square);
};



#endif
