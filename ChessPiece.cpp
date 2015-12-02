#include "ChessPiece.h"
using namespace std;

string ChessPiece::get_colour() {
  switch (colour) {
  case 0:
    return "Black";
  case 1:
    return "White";
  }
}

string ChessPiece::get_type() {
  switch (type) {
  case 0:
    return "King";
  case 1:
    return "Queen";
  case 2:
    return "Bishop";
  case 3:
    return "Knight";
  case 4:
    return "Rook";
  case 5:
    return "Pawn";
  }
}
