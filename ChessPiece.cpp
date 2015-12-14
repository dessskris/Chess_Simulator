#include "ChessPiece.h"
#include "ChessBoard.h"
using namespace std;

ChessPiece::ChessPiece(Type _t, Colour _c, ChessBoard *_b) : type(_t), colour(_c), board(_b) {}

ChessPiece::~ChessPiece() {}

Colour ChessPiece::get_colour() {
  return colour;
}

string ChessPiece::print_colour() {
  switch (colour) {
  case Black:
    return "Black";
  case White:
    return "White";
  default:
    return "Null";
  }
}

Type ChessPiece::get_type() {
  return type;
}

string ChessPiece::print_type() {
  switch (type) {
  case King:
    return "King";
  case Queen:
    return "Queen";
  case Bishop:
    return "Bishop";
  case Knight:
    return "Knight";
  case Rook:
    return "Rook";
  case Pawn:
    return "Pawn";
  default:
    return "Null";
  }
}

string ChessPiece::get_symbol() {
  switch (type) {
  case King:
    return (colour == Black) ? "♚" : "♔";
  case Queen:
    return (colour == Black) ? "♛" : "♕";
  case Bishop:
    return (colour == Black) ? "♝" : "♗";
  case Knight:
    return (colour == Black) ? "♞" : "♘";
  case Rook:
    return (colour == Black) ? "♜" : "♖";
  case Pawn:
    return (colour == Black) ? "♟" : "♙";
  default:
    return "Null";
  }
}

bool ChessPiece::check_capture(const string square) {
  if (!is_empty(square)) {
    board->capture();
    return 1;
  }
  return 0;
}

bool ChessPiece::is_empty(const string square) {
  if ((*board)[square] != NULL)
    return 0;
  else
    return 1;
}
