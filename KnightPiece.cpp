#include "KnightPiece.h"
#include "ChessBoard.h"
using namespace std;

KnightPiece::KnightPiece(Colour _c, ChessBoard *_b) : ChessPiece(Knight, _c, _b) {}
KnightPiece::~KnightPiece() {}

bool KnightPiece::is_valid_move(const string source_square, const string destination_square) {
  /* The knight moves to any of the closest squares that are not on the same
     rank, file, or diagonal, thus the move forms an "L"-shape:
     two squares vertically and one square horizontally, or
     two squares horizontally and one square vertically.
     The knight is the only piece that can leap over other pieces.*/

  // two squares vertically and one square horizontally
  if ((abs(source_square[1] - destination_square[1]) == 2) &&
      (abs(source_square[0] - destination_square[0]) == 1)) {
    if (check_capture(destination_square)) {
      if (board->get_piece_colour(destination_square) == colour) {
	board->capture();
	return 0;
      }
    }
    return 1;
  }

  // two squares horizontally and one square vertically
  if ((abs(source_square[0] - destination_square[0]) == 2) &&
      (abs(source_square[1] - destination_square[1]) == 1)) {
    if (check_capture(destination_square)) {
      if (board->get_piece_colour(destination_square) == colour) {
	board->capture();
	return 0;
      }
    }
    return 1;
  }

  return 0;
}
