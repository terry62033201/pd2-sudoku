#include<iostream>
#include"sudoku.h"
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;

void Sudoku::giveQuestion()
{
	int board[9][9] =  {0,1,0,0,0,9,2,7,0,
						9,0,0,0,2,0,0,0,5,
						4,0,0,6,0,0,0,0,0,
						5,0,0,0,3,0,8,0,0,
						0,3,0,4,0,7,0,6,0,
						0,0,1,0,8,0,0,0,4,
						0,0,0,0,0,2,0,0,3,
						1,0,0,0,5,0,0,0,6,
						0,6,3,8,0,0,0,5,0};
}
void Sudoku::readIn()
{
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}
}
bool Sudoku::solve(int sudo[9][9])
{
	int r, c, num;
	if(!FindUnassignedLocation(sudo, r, c))
		return true;

	for(num = 1; num <= 9; num++)
	{
		if(valid(sudo, r, c, num))
		{
			sudo[r][i] = num;
			
			if(solve(sudo))
				return true;
			sudo[r][c] = 0;
		}
	}
	return false;
}
/*int Sudoku::place_num(int n)
{
	int conflict, t;
	int row, col, block_row, block_col;

	if(n == 81)
	{
		for(i = 0; i < 9; i++)
		{
			for(j = 0; j < 9; j++)
			{
				sudo[i][j] = board[i][j];
			}
			cout << endl;
		}
		for(i = 0; i < 9; i++)
		{
			for(j = 0; j < 9; j++)
			{
				cout << sudo[i][j] << " ";
			}
			cout << endl;
		}
		return 1;
	}

	row = n / 9;
	col = n % 9;
	block_row = row / 3;
	block_col = col / 3;

	if(board[row][col] != 0)
		return(place_num(n + 1));

	for(t= 1; t <= 9; t++)
	{
		conflict = 0;
		for(i = 0; i < 9 && !conflict; i++)
			if(((col != i) && (board[row][i] == t)) || ((row != i) && (board[i][col] == t)))
				conflict = 1;
		if(!conflict)
		{
			for(i = 0; i < 3 && !conflict; i++)
				for(j = 0; j < 3 && !conflict; j++)
					if(board[3 * block_row + i][3 * block_col + j] == t)
						conflict = 1;
			if(!conflict)
			{
				board[row][col] = t;
				if(place_num(n + 1))
					return 1;
			}
		}
	}
	board[row][col] = 0;
	return 0;
}*/
bool Sudoku::FindUnassignedLocation(int sudoku[9][9], int &r, int &c)
{
	for(r = 0; r < 9; r++)
		for(c = 0; c < 9; c++)
			if(sudo[r][c] == 0)
				return true;
		return false;
}
bool Sudoku::checkRow(int sudo[9][9], int r, int num)
{
	for(j = 0; j < 9; j++)
	{
		if(sudo[r][j] == 0)
			continue;
		if(sudo[r][j] == num)
			return true;
	}
	return false;
}
bool Sudoku::checkCol(int sudo[9][9], int c, int num)
{
	for(i = 0; i < 9; i++)
	{
		if(sudo[i][c] == 0)
			continue;
		if(sudo[i][c] == num)
			return true;
	}
	return false;
}
bool Sudoku::checkBlock(int sudo[9][9], int setR, int setC, int num)
{
	for(int r = 0; r < 3; r++)
	{
		for(int c = 0; c < 3; c++)
		{
			if(sudo[r + setR][c + setC] == num)
				return true;
		}
	}
	return false;
}
bool Sudoku::valid(int sudo[9][9], int r, int c, int num)
{
	return  !checkRow(sudo, r, num)&&
			!checkCol(sudo, c, num)&&
			!checkBlock(sudo, r - r % 3, c - c % 3, num);
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
			else if(board[i][j] == b)
				board[i][j] = a;
		}
}
void Sudoku::changeRow(int a, int b)
{
	int temp1[9], temp2[9], temp3[9];
	
	if(a == 0 && b == 1)
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
	}else if(a == 0 && b == 2)
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
	}else if(a == 1 && b == 2)
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
	int temp1[9], temp2[9], temp3[9];

	if((a == 0 && b == 1) || (a == 1 && b == 0))
	{
		for(i = 0; i < 9; i++)
		{
			temp1[i] = board[i][0];
			temp2[i] = board[i][1];
			temp3[i] = board[i][2];

			board[i][0] = board[i][3];
			board[i][1] = board[i][4];
			board[i][2] = board[i][5];

			board[i][3] = temp1[i];
			board[i][4] = temp2[i];
			board[i][5] = temp3[i];
		}
	}else if((a == 0 && b == 2) || (a == 2 && b == 0))
	{
		for(i = 0; i < 9; i++)
		{
			temp1[i] = board[i][0];
			temp2[i] = board[i][1];
			temp3[i] = board[i][2];
			
			board[i][0] = board[i][6];
			board[i][1] = board[i][7];
			board[i][2] = board[i][8];

			board[i][3] = temp1[i];
			board[i][4] = temp2[i];
			board[i][5] = temp3[i];
		}
	}else if((a == 1 && b == 2) || (a == 2 && b == 1))
	{
		for(i = 0; i < 9; i++)
		{
			 temp1[i] = board[i][0];
		     temp2[i] = board[i][1];
		     temp3[i] = board[i][2];
		 
		 	 board[i][3] = board[i][6];
		     board[i][4] = board[i][7];
		     board[i][5] = board[i][8];

			 board[i][3] = temp1[i];
			 board[i][4] = temp2[i];
			 board[i][5] = temp3[i];
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
void transform()
{
}
