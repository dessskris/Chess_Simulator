#include "PawnPiece.h"
#include "ChessBoard.h"
using namespace std;

PawnPiece::PawnPiece(Colour _c, ChessBoard *_b) : ChessPiece(Pawn, _c, _b) {}
PawnPiece::~PawnPiece() {}

bool PawnPiece::is_valid_move(const string source_square, const string destination_square) {
  /* The pawn may move forward to the unoccupied square immediately in front
     of it on the same file;
     or on its first move it may advance two squares along the same file
     provided both squares are unoccupied;
     or it may move to a square occupied by an opponent's piece which is
     diagonally in front of it on an adjacent file, capturing that piece.*/

  //Moving backwards
  if (colour == Black) {
    if (source_square[1] < destination_square[1])
      return 0;
  }
  if (colour == White) {
    if (source_square[1] > destination_square[1])
      return 0;
  }

  // First move, advance two squares along the same file provided both squares are unoccupied
  if (((colour == Black) && (source_square[1] == '7')) || ((colour == White) && (source_square[1] == '2'))) {
    if ((source_square[0] == destination_square[0]) &&
	(abs(source_square[1] - destination_square[1]) == 2)) {
      char square_in_between[3];
      square_in_between[2] = '\0';
      square_in_between[0] = source_square[0];
      if (colour == Black)
	square_in_between[1] = source_square[1] - 1;
      if (colour == White)
	square_in_between[1] = source_square[1] + 1;

      if (is_empty(square_in_between) && is_empty(destination_square))
	return 1;
      return 0;
    }
  }

  // Move forward to the unoccupied square immediately in front of it on the same file
  if ((source_square[0] == destination_square[0]) &&
      (abs(source_square[1] - destination_square[1]) == 1)) {
    if (is_empty(destination_square))
      return 1;
    return 0;
  }

  // Move to a square occupied by an opponent's piece which is diagonally in front of it on an adjacent file, capturing that piece
  if ((abs(source_square[0] - destination_square[0]) == 1) &&
      (abs(source_square[1] - destination_square[1]) == 1)) {
    if (check_capture(destination_square)) {
      if (board->get_piece_colour(destination_square) != colour) {
	return 1;
      } else {
	board->capture();
	return 0;
      }
    }
  }

  return 0;
}
