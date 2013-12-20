/*
ID:wo__che1
PROG: checker
LANG: C++
*/
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

int row_dealing, num=0;

bool row_c[14];
short col_c[14];
bool diag_m[26];
bool diag_n[26];
int diag_table[14][14] =
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,2,3,4,5,6,7,8,9,10,11,12,13},
{0,2,3,4,5,6,7,8,9,10,11,12,13,14},
{0,3,4,5,6,7,8,9,10,11,12,13,14,15},
{0,4,5,6,7,8,9,10,11,12,13,14,15,16},
{0,5,6,7,8,9,10,11,12,13,14,15,16,17},
{0,6,7,8,9,10,11,12,13,14,15,16,17,18},
{0,7,8,9,10,11,12,13,14,15,16,17,18,19}, 
{0,8,9,10,11,12,13,14,15,16,17,18,19,20},
{0,9,10,11,12,13,14,15,16,17,18,19,20,21},
{0,10,11,12,13,14,15,16,17,18,19,20,21,22},
{0,11,12,13,14,15,16,17,18,19,20,21,22,23},
{0,12,13,14,15,16,17,18,19,20,21,22,23,24},
{0,13,14,15,16,17,18,19,20,21,22,23,24,25},
};


void put_checker(int len, int col)
{
	int row, i;
	if(col == len+1) 
	{	
		if(num++<3)
		{
			for(i=1; i<len; i++)
			{
				cout << col_c[i] << " ";
			}
			cout << col_c[len] << endl;
		}
		return;
	}
	for(row=1; row<=len; row++)
	{
		if(!row_c[row]&&!diag_m[len+row-col]&&!diag_n[diag_table[row][col]])  //row is ok, main diag and verus diag are ok
		{
			//mark queen placed at column,row;
			diag_n[diag_table[row][col]] = diag_m[len+row-col] = row_c[row] = true;
			col_c[col] = row;
			//placequeen(column+1);
			put_checker(len, col+1);
			//un-mark queen placed at column,row;
			diag_n[diag_table[row][col]] = diag_m[len+row-col] = row_c[row] = false;
		}
	}
		
}

int main() {
    freopen("checker.out", "w", stdout);
    freopen("checker.in", "r", stdin);
	int len;
	cin >> len;    
	put_checker(len, 1);	
	cout << num << endl;
	return 0;
}
