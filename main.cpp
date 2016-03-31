#include<iostream>
#include<cstdlib>
#include"sudoku.h"
using namespace std;

int main()
{
	Sudoku tmr1;

	tmr1.giveQuestion();
	tmr1.readIn();
	tmr1.change();
	//tmr1.checkBlock(sudo[9][9], r, c, r-r%3, c-c%3)
    
}
