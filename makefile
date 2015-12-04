CXX=g++ -Wall -g
EXE=ChessMain.o ChessBoard.o ChessPiece.o

chess: $(EXE)
	$(CXX) $(EXE) -o chess

%.o: %.cpp %.h ChessPiece.h
	$(CXX) -c $<


.PHONY: clean
clean:
	rm -f chess *.o
