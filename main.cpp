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
	tmr1.transform();
	tmr1.solve();
    
	return 0;
}
