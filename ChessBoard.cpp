#include "ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard() {
  InitialisePieces();


  position.insert (pair<char, ChessPiece> ('A8', black_piece[0]));
  position.insert (pair<char, ChessPiece> ('B8', black_piece[1]));
}


void ChessBoard::InitialisePieces() {
  black_piece[0] = new Rook(Black);
  black_piece[1] = new Knight(Black);
}

void ChessBoard::submitMove(const string *source_square, const string *destination_square) {
  cout << "hi";

}
