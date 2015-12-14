#include "ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard() {
  initialise_board();
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

void ChessBoard::initialise_board() {
  initialise_position();
  turn = White;
  capture_sign = 0;
  black_king_pos = "D8";
  white_king_pos = "D1";
  captured_piece = NULL;
  piece_checking_black = NULL;
  piece_checking_black_pos = "00";
  piece_checking_white = NULL;
  piece_checking_white_pos = "00";
  cout << "A new chess game is started!\n";
}

void ChessBoard::initialise_position() {
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

void ChessBoard::switch_turn() {
  if (turn == Black)
    turn = White;
  else
    turn = Black;
}

void ChessBoard::move(const string source_square, const string destination_square) {
  ChessPiece *temp_piece = position[source_square];
  position[source_square] = NULL;
  position[destination_square] = temp_piece;
}

void ChessBoard::move_capture(const string source_square, const string destination_square) {
  ChessPiece *temp_piece = position[source_square];
  captured_piece = position[destination_square];
  position[source_square] = NULL;
  position[destination_square] = temp_piece;
}

void ChessBoard::undo_capture(const string old_source_square, const string old_destination_square) {
  position[old_source_square] = position[old_destination_square];
  position[old_destination_square] = captured_piece;
  captured_piece = NULL;
}

bool ChessBoard::pretend_move_king_ok(string source_square, string destination_square, Colour colour) {
  capture_sign = 0;
  position[source_square]->is_valid_move(source_square, destination_square);
  if (capture_sign) {
    move_capture(source_square, destination_square);
    if (!king_in_check(colour)) {
      undo_capture(source_square, destination_square);
      return 1;
    } else {
      undo_capture(source_square, destination_square);
    }
  } else {
    move(source_square, destination_square); 
    if (!king_in_check(colour)) {
      move(destination_square, source_square);
      return 1;
    } else {
      move(destination_square, source_square);
    }
  }
  return 0;
}

void ChessBoard::capture() {
  capture_sign = (capture_sign) ? 0 : 1;
}

bool ChessBoard::find_king(Colour colour) {
  map<string, ChessPiece*>::iterator it = position.begin();
  while(it != position.end()) {
    if (it->second != NULL) {
      if ((it->second->get_type() == King) && (it->second->get_colour() == colour)) {
	if (colour == Black) {
	  black_king_pos = it->first;
	} else {
	  white_king_pos = it->first;
	}
	return 1;
      }
    }
    it++;
  }
  return 0;
}

bool ChessBoard::king_in_check(Colour colour) {
  find_king(colour);
  map<string, ChessPiece*>::iterator it = position.begin();
  string king_position = (colour == Black) ? black_king_pos : white_king_pos;
  while (it != position.end()) {
    if (it->second != NULL) {
      if ((it->second->get_colour() != colour) &&
	  (it->second->is_valid_move(it->first, king_position))) {
	capture();
	return 1;
      }
    }
    it++;
  }
  return 0;
}

bool ChessBoard::any_valid_move(Colour colour) {
  char square[3];
  square[2] = '\0';
  map<string, ChessPiece*>::iterator it = position.begin();
  while (it != position.end()) {
    if (it->second != NULL) {
      if (it->second->get_colour() == colour) {
	for (char file = 'A'; file <= 'H'; file++) {
	  square[0] = file;
	  for (char rank = '1'; rank <= '8'; rank++) {
	    square[1] = rank;
	    if ((it->second->is_valid_move(it->first, square)) &&
		(pretend_move_king_ok(it->first, square, colour)))
	      return 1;
	  }
	}
	// This piece has no valid move in response to a check
      }
    }
    it++;
  }
  return 0;
}

Type ChessBoard::get_piece_type(string pos) {
  return position[pos]->get_type();
}

Colour ChessBoard::get_piece_colour(string pos) {
  return position[pos]->get_colour();
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

void ChessBoard::submitMove(const string source_square, const string destination_square) {
  if (!valid_square(source_square) || !valid_square(destination_square)) {
    cerr << "Square invalid!\n";
    return;
  }
  if (position[source_square] == NULL) {
    cout << "There is no piece at position " << source_square << "!\n";
    return;
  }
  if (source_square == destination_square) {
    cout << "The destination square has to be different "
	 << "from the source square!\n";
    return;
  }
  if (position[source_square]->get_colour() != turn) {
    cout << "It is not " << position[source_square]->print_colour() 
	 << "'s turn to move!\n";
    return;
  }

  capture_sign = 0;
  captured_piece = NULL;

  if (!position[source_square]->is_valid_move(source_square, destination_square)) {
    capture_sign = 0;
    cout << position[source_square]->print_colour() << "'s "
	 << position[source_square]->print_type() << " cannot move to "
	 << destination_square << "!\n";
    return;
  }

  // It is illegal to make a move that would put your own king in check
  if (capture_sign) {
    move_capture(source_square, destination_square);
    if (king_in_check(turn)) {
      undo_capture(source_square, destination_square);
      cout << position[source_square]->print_colour() << "'s "
	   << position[source_square]->print_type() << " cannot move to "
	   << destination_square << "!\n";
      return;
    }
  } else {
    move(source_square, destination_square); 
    if (king_in_check(turn)) {
      move(destination_square, source_square);
      cout << position[source_square]->print_colour() << "'s "
	   << position[source_square]->print_type() << " cannot move to "
	   << destination_square << "!\n";
      return;
    }
  }

  // Reaching this point means it is a valid move
  cout << position[destination_square]->print_colour() << "'s "
       << position[destination_square]->print_type() << " moves from "
       << source_square << " to " << destination_square;
  if (capture_sign) {
    cout << " taking " << captured_piece->print_colour() << "'s "
	 << captured_piece->print_type() << endl;
  } else {
    cout << endl;
  }

  // Check if the other player's King is in check or a stalemate
  capture_sign = 0;
  switch (turn) {
  case Black:
    if (king_in_check(White)) {
      piece_checking_white = position[destination_square];
      piece_checking_white_pos = destination_square;
      if (any_valid_move(White)) {
	cout << "White is in check\n";
      } else {
	cout << "White is in checkmate\n";
      }
    } else if (!any_valid_move(White)) {
      cout << "White is in a stalemate\n";
    }
    break;
  case White:
    if (king_in_check(Black)) {
      piece_checking_black = position[destination_square];
      piece_checking_black_pos = destination_square;
      if (any_valid_move(Black)) {
	cout << "Black is in check\n";
      } else {
	cout << "Black is in checkmate\n";
      }
    } else if (!any_valid_move(Black)) {
      cout << "Black is in a stalemate\n";
    }
    break;
  }

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
  initialise_board();
}

