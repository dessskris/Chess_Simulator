CXX=g++ -Wall -g
EXE=ChessMain.o ChessBoard.o ChessPiece.o helper.o

chess: $(EXE)
	$(CXX) $(EXE) -o chess

%.o: %.cpp %.h ChessPiece.h helper.h
	$(CXX) -c $<


.PHONY: clean
clean:
	rm -f chess *.o
