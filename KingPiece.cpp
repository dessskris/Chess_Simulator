#include "KingPiece.h"
#include "ChessBoard.h"
using namespace std;

KingPiece::KingPiece(Colour _c, ChessBoard *_b) : ChessPiece(King, _c, _b) {}
KingPiece::~KingPiece() {}

bool KingPiece::is_valid_move(const string source_square, const string destination_square) {
  // The king moves one square in any direction
  if ( (abs(source_square[0] - destination_square[0]) == 1) &&
       (abs(source_square[1] - destination_square[1]) == 1) ) {
    if (check_capture(destination_square)) {
      if (board->get_piece_colour(destination_square) == colour) {
	board->capture();
	return 0;
      }
    }
    return 1;
  }
  else
    return 0;
}
