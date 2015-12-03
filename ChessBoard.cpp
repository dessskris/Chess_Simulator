#include "ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard() {
  InitialisePieces();
  InitialisePosition();
  turn = White;
}

ChessBoard::~ChessBoard() {
  delete [] black_piece[16];
  delete [] white_piece[16];
}

void ChessBoard::InitialisePieces() {
  black_piece[0] = new RookPiece(Black);
  black_piece[1] = new KnightPiece(Black);
  black_piece[2] = new BishopPiece(Black);
  black_piece[3] = new QueenPiece(Black);
  black_piece[4] = new KingPiece(Black);
  black_piece[5] = new BishopPiece(Black);
  black_piece[6] = new KnightPiece(Black);
  black_piece[7] = new RookPiece(Black);
  black_piece[8] = new PawnPiece(Black);
  black_piece[9] = new PawnPiece(Black);
  black_piece[10] = new PawnPiece(Black);
  black_piece[11] = new PawnPiece(Black);
  black_piece[12] = new PawnPiece(Black);
  black_piece[13] = new PawnPiece(Black);
  black_piece[14] = new PawnPiece(Black);
  black_piece[15] = new PawnPiece(Black);

  white_piece[0] = new RookPiece(White);
  white_piece[1] = new KnightPiece(White);
  white_piece[2] = new BishopPiece(White);
  white_piece[3] = new QueenPiece(White);
  white_piece[4] = new KingPiece(White);
  white_piece[5] = new BishopPiece(White);
  white_piece[6] = new KnightPiece(White);
  white_piece[7] = new RookPiece(White);
  white_piece[8] = new PawnPiece(White);
  white_piece[9] = new PawnPiece(White);
  white_piece[10] = new PawnPiece(White);
  white_piece[11] = new PawnPiece(White);
  white_piece[12] = new PawnPiece(White);
  white_piece[13] = new PawnPiece(White);
  white_piece[14] = new PawnPiece(White);
  white_piece[15] = new PawnPiece(White);
}

void ChessBoard::InitialisePosition() {
  position.insert (make_pair("A8", *black_piece[0]));
  position.insert (make_pair("B8", *black_piece[1]));
  position.insert (make_pair("C8", *black_piece[2]));
  position.insert (make_pair("D8", *black_piece[3]));
  position.insert (make_pair("E8", *black_piece[4]));
  position.insert (make_pair("F8", *black_piece[5]));
  position.insert (make_pair("G8", *black_piece[6]));
  position.insert (make_pair("H8", *black_piece[7]));

  position.insert (make_pair("A7", *black_piece[8]));
  position.insert (make_pair("B7", *black_piece[9]));
  position.insert (make_pair("C7", *black_piece[10]));
  position.insert (make_pair("D7", *black_piece[11]));
  position.insert (make_pair("E7", *black_piece[12]));
  position.insert (make_pair("F7", *black_piece[13]));
  position.insert (make_pair("G7", *black_piece[14]));
  position.insert (make_pair("H7", *black_piece[15]));

  position.insert (make_pair("A1", *white_piece[0]));
  position.insert (make_pair("B1", *white_piece[1]));
  position.insert (make_pair("C1", *white_piece[2]));
  position.insert (make_pair("D1", *white_piece[3]));
  position.insert (make_pair("E1", *white_piece[4]));
  position.insert (make_pair("F1", *white_piece[5]));
  position.insert (make_pair("G1", *white_piece[6]));
  position.insert (make_pair("H1", *white_piece[7]));

  position.insert (make_pair("A2", *white_piece[8]));
  position.insert (make_pair("B2", *white_piece[9]));
  position.insert (make_pair("C2", *white_piece[10]));
  position.insert (make_pair("D2", *white_piece[11]));
  position.insert (make_pair("E2", *white_piece[12]));
  position.insert (make_pair("F2", *white_piece[13]));
  position.insert (make_pair("G2", *white_piece[14]));
  position.insert (make_pair("H2", *white_piece[15]));
}

void ChessBoard::submitMove(const string source_square, const string destination_square) {
  if (position[source_square].is_valid_move(position, source_square, destination_square))
    cout << "true";
}

void ChessBoard::resetBoard() {
  cout << "hi";
}

