#include "ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard() {
  initialisePosition();
  turn = White;
  capture_sign = 0;
  cout << "A new chess game is started!\n\n";
  printBoard();
}

ChessBoard::~ChessBoard() {
  map<string, ChessPiece*>::iterator it = position.begin();
  while(it != position.end()) {
    if (it->second != NULL) {
      delete it->second;
    }
    it++;
  }
}

ChessPiece* ChessBoard::operator [](string pos) {
  return this->position[pos];
}


void ChessBoard::initialisePosition() {
  position.insert (make_pair("A8", new RookPiece(Black, this)));
  position.insert (make_pair("B8", new KnightPiece(Black, this)));
  position.insert (make_pair("C8", new BishopPiece(Black, this)));
  position.insert (make_pair("D8", new QueenPiece(Black, this)));
  position.insert (make_pair("E8", new KingPiece(Black, this)));
  position.insert (make_pair("F8", new BishopPiece(Black, this)));
  position.insert (make_pair("G8", new KnightPiece(Black, this)));
  position.insert (make_pair("H8", new RookPiece(Black, this)));

  char square[3];
  square[2] = '\0';
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

void ChessBoard::printBoard() {
  cout << "    ";
  char mysquare[3];
  mysquare[2]='\0';
  for (char file = 'A'; file <= 'H'; file++) 
    cout << file << "   ";
  cout << endl;
  for (char rank='8'; rank > '0'; rank--) {
    mysquare[1] = rank;
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    cout << rank << " ";
    for (char file = 'A'; file <= 'H'; file++) {
      mysquare[0] = file;
      cout << '|' << " ";
      if (position[mysquare] != NULL)
	cout << position[mysquare]->get_symbol() << " ";
      else
	cout << "  ";
    }
    cout << "|" << endl;
  }
  cout << "  +---+---+---+---+---+---+---+---+" << endl;
}

void ChessBoard::move(const string source_square, const string destination_square) {
  ChessPiece *temp_piece = position[source_square];
  position[source_square] = NULL;
  position[destination_square] = temp_piece;
}

void ChessBoard::capture() {
  capture_sign = (capture_sign) ? 0 : 1;
}

void ChessBoard::switch_turn() {
  if (turn == Black)
    turn = White;
  else
    turn = Black;
}

void ChessBoard::submitMove(const string source_square, const string destination_square) {
  if (!valid_square(source_square) || !valid_square(destination_square)) {
    cerr << "Square invalid!\n";
    return;
  }
  if (position[source_square] == NULL) {
    cout << "There is no piece at position " << source_square << "!\n";
    return;
  }
  if (position[source_square]->get_colour() != turn) {
    cout << "It is not " << position[source_square]->print_colour() << "'s turn to move!\n";
    return;
  }



  if (!position[source_square]->is_valid_move(source_square, destination_square)) {
    cout << position[source_square]->print_colour() << "'s "
	 << position[source_square]->print_type() << " cannot move to "
	 << destination_square << "!\n";
    return;
  }

  // Reaching this point means it is a valid move
  
  cout << position[source_square]->print_colour() << "'s "
       << position[source_square]->print_type() << " moves from "
       << source_square << " to " << destination_square;
  if (capture_sign) {
    cout << " taking " << position[destination_square]->print_colour() << "'s "
	 << position[destination_square]->print_type() << endl;
    capture();
  } else {
    cout << endl;
  }

  move(source_square, destination_square); 
  switch_turn();
}

void ChessBoard::resetBoard() {
  map<string, ChessPiece*>::iterator it = position.begin();
  while(it != position.end()) {
    if (it->second != NULL) {
      delete it->second;
    }
    position.erase(it);
    it++;
  }
  initialisePosition();
  turn = White;
  capture_sign = 0;
  cout << "A new chess game is started!\n\n";
  printBoard();

}

