CXX=g++ -Wall -g
EXE=ChessMain.o ChessBoard.o ChessPiece.o helper.o

chess: $(EXE)
	$(CXX) $(EXE) -o chess

%.o: %.cpp %.h helper.h
	$(CXX) -c $<

ChessMain.o: ChessBoard.h
ChessBoard.o: ChessPiece.h
ChessPiece.o: ChessBoard.h

.PHONY: clean
clean:
	rm -f chess *.o
