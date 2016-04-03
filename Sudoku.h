#include<iostream>
#include<cstdio>
#define sudokuSize 81
using namespace std;
class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void change();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		bool check_ini_row();
		bool check_ini_col();
		int place_num(int n);
		int place_numr(int n);
		void printOut();
		int board[9][9];
		int sudo[9][9];
		int sudor[9][9];
	private:
		int i, j, r, c;
};
