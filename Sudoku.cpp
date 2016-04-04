#include<iostream>
#include"Sudoku.h"
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

void Sudoku::giveQuestion()
{
	int board[9][9] =  {0,6,9,8,7,0,0,0,0,
						4,3,7,0,0,2,0,0,1,
						0,1,0,9,3,0,0,0,7,
						6,0,0,7,0,5,9,0,3,
						7,8,0,1,9,6,0,0,5,
						1,9,0,2,4,3,6,7,0,
						0,0,1,0,0,8,0,0,4,
						3,0,0,0,1,0,0,0,6,
						0,4,0,3,5,7,1,8,9};
}
void Sudoku::readIn()
{
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			cin >> sudo[i][j];
		}
	}
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			sudor[i][j] = sudo[i][j];
		}
	}
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			board[i][j] = sudo[i][j];
		}
	}
}
bool Sudoku::check_ini_row()
{
	int arr[9] = {0,0,0,0,0,0,0,0,0};
	for(int num = 1; num <= 9; num++)
	{
		for(j = 0; j < 9; j++)
		{
			if(sudo[0][j] == num)
				arr[num - 1]++;
			if(sudo[1][j] == num)
				arr[num - 1]++;
			if(sudo[2][j] == num)
				arr[num - 1]++;
			if(sudo[3][j] == num)
				arr[num - 1]++;
			if(sudo[4][j] == num)
				arr[num - 1]++;
			if(sudo[5][j] == num)
				arr[num - 1]++;
			if(sudo[6][j] == num)
				arr[num - 1]++;
			if(sudo[7][j] == num)
				arr[num - 1]++;
			if(sudo[8][j] == num)
				arr[num - 1]++;

			for(i = 0; i < 9; i++)
			{
				if(arr[i] > 1)
					return false;
				else
					arr[i] = 0;
			}
		}
	}
	return true;

}
bool Sudoku::check_ini_col()
{
	int arr[9] = {0,0,0,0,0,0,0,0,0};

	for(int num = 1; num <= 9; num++)
	{
		for(i = 0; i < 9; i++)
		{
			if(sudo[i][0] == num)
				arr[num - 1]++;
			if(sudo[i][1] == num)
				arr[num - 1]++;
			if(sudo[i][2] == num)
				arr[num - 1]++;
			if(sudo[i][3] == num)
				arr[num - 1]++;
			if(sudo[i][4] == num)
				arr[num - 1]++;
			if(sudo[i][5] == num)
				arr[num - 1]++;
			if(sudo[i][6] == num)
				arr[num - 1]++;
			if(sudo[i][7] == num)
				arr[num - 1]++;
			if(sudo[i][8] == num)
				arr[num - 1]++;

			for(j = 0; j < 9; j++)
			{
				if(arr[j] > 1)
					return false;
				else
					arr[j] = 0;
			}
		}	
	}
	return true;
}
void Sudoku::solve()
{
	if(check_ini_row() == false || check_ini_col() == false)
	{
		cout << "0"<<endl;
		exit(1);
	}
	if(place_num(0) == 1 && place_numr(0) == 1)
	{	
		for(i = 0; i < 9; i++)
		{
			for(j = 0; j < 9; j++)
			{
				if(sudo[i][j] != sudor[i][j]){
					cout << "2" << endl;
					exit(1);
				}
			}
		}
		cout << "1" << endl;
	
		for(i = 0; i < 9; i++)
		{
			for(j = 0; j < 9; j++)
			{
				cout << sudo[i][j] << " ";
			}
			cout << endl;
		}
	}else
	{
		cout << "0" << endl;
	}
}
int Sudoku::place_num(int n)
{
	int conflict, t;
	int row, col, block_row, block_col;

	if(n == 81)
	{
		return 1;
	}

	row = n / 9;
	col = n % 9;
	block_row = row / 3;
	block_col = col / 3;

	if(sudo[row][col] != 0)
		return(place_num(n + 1));

	for(t= 9; t > 0; t--)
	{
		conflict = 0;
		for(i = 0; i < 9 && !conflict; i++)
			if(((col != i) && (sudo[row][i] == t)) || ((row != i) && (sudo[i][col] == t)))
				conflict = 1;
		if(!conflict)
		{
			for(i = 0; i < 3 && !conflict; i++)
				for(j = 0; j < 3 && !conflict; j++)
					if(sudo[3 * block_row + i][3 * block_col + j] == t)
						conflict = 1;
			if(!conflict)
			{
				sudo[row][col] = t;
				if(place_num(n + 1))
					return 1;
			}
		}
	}
	sudo[row][col] = 0;
	return 0;
}
int Sudoku::place_numr(int u)
{
	int conflict, t;
	int row, col, block_row, block_col;

	if(u == 81)
	{
		return 1;
	}

	row = u / 9;
	col = u % 9;
	block_row = row / 3;
	block_col = col / 3;

	if(sudor[row][col] != 0)
		return(place_numr(u + 1));
	
	for(t= 1; t <= 9; t++)
	{
		conflict = 0;
		for(i = 0; i < 9 && !conflict; i++)
			if(((col != i) && (sudor[row][i] == t)) || ((row != i) && (sudor[i][col] == t)))
				conflict = 1;
		if(!conflict)
		{
			for(i = 0; i< 3 && !conflict; i++)
				for(j = 0; j < 3 && !conflict; j++)
					if(sudor[3 * block_row + i][3 * block_col + j] == t)
						conflict = 1;
			if(!conflict)
			{
				sudor[row][col] = t;
				if(place_numr(u + 1))
					return 1;
			}
		}
	}
	sudor[row][col] = 0;
	return 0;

}
void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand() % 9 + 1, rand() % 9 + 1);
	changeRow(rand() % 3, rand() % 3);
	changeCol(rand() % 3, rand() % 3);
	rotate(rand() % 101);
	flip(rand() % 2);
}
void Sudoku::changeNum(int a, int b)
{
	for(i = 0; i < 9; i++)
		for(j = 0; j < 9; j++)
		{
			if(board[i][j] == a)
				board[i][j] = b;
			else if(sudo[i][j] == b)
				board[i][j] = a;
		}
}
void Sudoku::changeRow(int a, int b)
{
	int temp1[9], temp2[9], temp3[9];
	
	if((a == 0 && b == 1) || (a == 1 && b == 0))
	{	
		for(j = 0; j < 9; j++)
		{
			temp1[j] = board[0][j];
			temp2[j] = board[1][j];
			temp3[j] = board[2][j];

			board[0][j] = board[3][j];
			board[1][j] = board[4][j];
			board[2][j] = board[5][j];

			board[3][j] = temp1[j];
			board[4][j] = temp2[j];
			board[5][j] = temp3[j];
		}
	}else if((a == 0 && b == 2) || (a == 2 && b == 0))
	{
		for(j = 0; j < 9; j++)
		{
			temp1[j] = board[0][j];
			temp2[j] = board[1][j];
			temp3[j] = board[2][j];

			board[0][j] = board[6][j];
			board[1][j] = board[7][j];
			board[2][j] = board[8][j];

			board[6][j] = temp1[j];
		    board[7][j] = temp2[j];
		    board[8][j] = temp3[j];
		}
	}else if((a == 1 && b == 2) || (a == 2 && b == 1))
	{
		for(j = 0; j < 9; j++)
		{
			temp1[j] = board[3][j];
			temp2[j] = board[4][j];
			temp3[j] = board[5][j];
			   
			board[3][j] = board[6][j];
			board[4][j] = board[7][j];
			board[5][j] = board[8][j];

			board[6][j] = temp1[j];
		    board[7][j] = temp2[j];
		    board[8][j] = temp3[j];
		}
	}
}
void Sudoku::changeCol(int a, int b)
{
	int tempa[9], tempb[9], tempc[9];

	if((a == 0 && b == 1) || (a == 1 && b == 0))
	{
		for(i = 0; i < 9; i++)
		{
			tempa[i] = board[i][0];
			tempb[i] = board[i][1];
			tempc[i] = board[i][2];

			board[i][0] = board[i][3];
			board[i][1] = board[i][4];
			board[i][2] = board[i][5];

			board[i][3] = tempa[i];
			board[i][4] = tempb[i];
			board[i][5] = tempc[i];
		}
	}else if((a == 0 && b == 2) || (a == 2 && b == 0))
	{
		for(i = 0; i < 9; i++)
		{
			tempa[i] = board[i][0];
			tempb[i] = board[i][1];
			tempc[i] = board[i][2];
			
			board[i][0] = board[i][6];
			board[i][1] = board[i][7];
			board[i][2] = board[i][8];

			board[i][6] = tempa[i];
			board[i][7] = tempb[i];
			board[i][8] = tempc[i];
		}
	}else if((a == 1 && b == 2) || (a == 2 && b == 1))
	{
		for(i = 0; i < 9; i++)
		{
			 tempa[i] = board[i][3];
		     tempb[i] = board[i][4];
		     tempc[i] = board[i][5];
		 
		 	 board[i][3] = board[i][6];
		     board[i][4] = board[i][7];
		     board[i][5] = board[i][8];

			 board[i][6] = tempa[i];
			 board[i][7] = tempb[i];
			 board[i][8] = tempc[i];
		}
	}
}
void Sudoku::rotate(int n)
{
	int t, r_tmp[9][9];
	for(t = 0; t < n; t++)
	{
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			r_tmp[j][8 - i] = board[i][j];
		}
	}
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			board[i][j] = r_tmp[i][j];
		}
	}
	}
}
void Sudoku::flip(int n)
{
	int temp_v1[9], temp_v2[9], temp_v3[9], temp_v4[9];
	int temp_h1[9], temp_h2[9], temp_h3[9], temp_h4[9];
	
	if(n == 1)
	{
		for(j = 0; j < 9; j++)
		{
			temp_v1[j] = board[0][j];
			temp_v2[j] = board[1][j];
			temp_v3[j] = board[2][j];
			temp_v4[j] = board[3][j];

			board[0][j] = board[8][j];
			board[1][j] = board[7][j];
			board[2][j] = board[6][j];
			board[3][j] = board[5][j];

			board[8][j] = temp_v1[j];
			board[7][j] = temp_v2[j];
			board[6][j] = temp_v3[j];
			board[5][j] = temp_v4[j];
		}
	}else
	{
		for(i = 0; i < 9; i++)
		{
			temp_h1[i] = board[i][0];
			temp_h2[i] = board[i][1];
			temp_h3[i] = board[i][2];
			temp_h4[i] = board[i][3];

			board[i][0] = board[i][8];
			board[i][1] = board[i][7];
			board[i][2] = board[i][6];
			board[i][3] = board[i][5];

			board[i][8] = temp_h1[i];
			board[i][7] = temp_h2[i];
			board[i][6] = temp_h3[i];
			board[i][5] = temp_h4[i];
		}
	}
}
void Sudoku::printOut()
{
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void Sudoku::transform()
{
	change();
	printOut();
}
