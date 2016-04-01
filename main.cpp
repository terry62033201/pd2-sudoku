#include<iostream>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;

int main()
{
	int i, j;
	Sudoku tmr1;

	tmr1.giveQuestion();
	tmr1.readIn();
	tmr1.change();
	tmr1.solve();
	tmr1.transform();
	//tmr1.checkBlock(sudo[9][9], r, c, r-r%3, c-c%3)
	/*for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			cout << tmr1.board[i][j] << " ";
		}
		cout << endl;
	}*/
    return 0;
}
