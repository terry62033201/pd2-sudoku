#include<iostream>
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
		int checkRow(int sudo[9][9], int r);
		int checkCol(int sudo[9][9], int c);
		int checkBlock(int sudo[9][9], int r, int c, int setR, int setC);
	private:
		int i, j, num;
		int board[9][9];
		int sudo[9][9];
};
