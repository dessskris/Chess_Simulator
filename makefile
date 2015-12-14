CXX=g++ -Wall -g
EXE=ChessMain.o ChessBoard.o ChessPiece.o KingPiece.o QueenPiece.o BishopPiece.o KnightPiece.o RookPiece.o PawnPiece.o helper.o

chess: $(EXE)
	$(CXX) $(EXE) -o chess

%.o: %.cpp %.h ChessPiece.h helper.h
	$(CXX) -c $<

ChessMain.o: ChessBoard.h
ChessBoard.o: KingPiece.h QueenPiece.h BishopPiece.h KnightPiece.h RookPiece.h PawnPiece.h
ChessPiece.o: ChessBoard.h

.PHONY: clean
clean:
	rm -f chess *.o
