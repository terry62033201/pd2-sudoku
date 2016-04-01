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
		int place_num(int n);
		bool FindUnassignedLocation(int sudo[9][9], int &r, int &c);
		bool valid(int sudo[9][9], int r, int c, int num);
		bool checkRow(int sudo[9][9], int r, int num);
		bool checkCol(int sudo[9][9], int c, int num);
		bool checkBlock(int sudo[9][9], int r, int c, int num);
		int board[9][9];
		int sudo[9][9];
	private:
		int i, j;
};
