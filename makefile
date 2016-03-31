main : main.o sudoku.o
	g++ -o main main.o sudoku.o

main.o : main.cpp sudoku.h
	g++ -c main.cpp

sudoku.o : sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

clean:
	rm main main.o sudoku.o
