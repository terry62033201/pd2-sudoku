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
			cin >> sudo[i][j];
		}
	}
}
void Sudoku::solve()
{

}
int Sudoku::checkRow(int sudo[9][9], int r)
{
	for(j = 0; j < 9; j++)
	{
		if(sudo[r][j] == 0)
			continue;
		if(sudo[r][j] == num)
			return 0;
	}
	return 1;
}
int Sudoku::checkCol(int sudo[9][9], int c)
{
	for(i = 0; i < 9; i++)
	{
		if(sudo[i][c] == 0)
			continue;
		if(sudo[i][c] == num)
			return 0;
	}
	return 1;
}
int Sudoku::checkBlock(int sudo[9][9], int r, int c, int setR, int setC)
{
	for(r = 0; r < 3; r++)
	{
		for(c = 0; c < 3; c++)
		{
			if(sudo[r + setR][c + setC] == num)
				return 1;
		}
	}
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
