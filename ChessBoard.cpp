#include "ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard() {
  InitialisePosition();
  turn = White;
}

ChessBoard::~ChessBoard() {
  map<string, ChessPiece*>::iterator it = position.begin();
  while(it != position.end())
    {
      if (it->second != NULL) {
	delete it->second;
      }
      it++;
    }
}

void ChessBoard::InitialisePosition() {
  position.insert (make_pair("A8", new RookPiece(Black, this)));
  position.insert (make_pair("B8", new KnightPiece(Black, this)));
  position.insert (make_pair("C8", new BishopPiece(Black, this)));
  position.insert (make_pair("D8", new QueenPiece(Black, this)));
  position.insert (make_pair("E8", new KingPiece(Black, this)));
  position.insert (make_pair("F8", new BishopPiece(Black, this)));
  position.insert (make_pair("G8", new KnightPiece(Black, this)));
  position.insert (make_pair("H8", new RookPiece(Black, this)));

  char square[2];
  square[1] = '7';
  for (char file = 'A'; file <= 'H'; file++) {
    square[0] = file;
    position.insert (make_pair(square, new PawnPiece(Black, this)));
  }    

  for (char rank = '6'; rank <= '3'; rank--) {
    square[1] = rank;
    for (char file = 'A'; file <= 'H'; file++) {
      square[0] = file;
      position.insert (make_pair(square, (ChessPiece*)NULL));
    }
  }

  square[1] = '2';
  for (char file = 'A'; file <= 'H'; file++) {
    square[0] = file;
    position.insert (make_pair(square, new PawnPiece(White, this)));
  }   

  position.insert (make_pair("A1", new RookPiece(White, this)));
  position.insert (make_pair("B1", new KnightPiece(White, this)));
  position.insert (make_pair("C1", new BishopPiece(White, this)));
  position.insert (make_pair("D1", new QueenPiece(White, this)));
  position.insert (make_pair("E1", new KingPiece(White, this)));
  position.insert (make_pair("F1", new BishopPiece(White, this)));
  position.insert (make_pair("G1", new KnightPiece(White, this)));
  position.insert (make_pair("H1", new RookPiece(White, this)));

}

ChessPiece* ChessBoard::operator [](string pos) {
  return this->position[pos];
}

void ChessBoard::submitMove(const string source_square, const string destination_square) {
  if (position[source_square] != NULL)
    cout << (position[source_square]->is_valid_move(source_square, destination_square));



  // need to check if it's a pawn, first move needs to be updated if it has not moved yet
  //change turn
}

void ChessBoard::resetBoard() {
  cout << "hi";
}

