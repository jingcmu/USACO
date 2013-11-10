/*
ID:wo__che1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define CLEAR 57521883
const long moveTable[10] = 
{0, 18911232, 19136512, 2363904, 16810048, 2134536, 262657, 36936, 73, 4617};

long clocks = 0;

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return;
}

void combine(int a[], int n, int m,  int b[], int out[], int M, 
							long clock_l, ofstream& fout)
{
	int i, j, k;
	int index, i_clock;
	int clock_ll;
	for(i=n; i>=m; i--)
	{
		b[m-1] = i - 1;
		if (m == 1)
		{
			for(j=M-1, k=0; j>=0; j--,k++)
			{	
				out[k] = a[b[j]];   
			}

			{
				clock_ll = clock_l;
				for(j=0; j<=M-1; j++)
				{
					index = out[j];
					clock_ll += moveTable[index];
					clock_ll &= CLEAR;
				}
				
				if(!clock_ll)
				{
					for(j=0; j<M-1; j++)
					{
						fout <<out[j] <<" ";
					}
					fout <<out[M-1] <<endl;
					exit(0);
				}
			}
		}
		else
		{
			combine(a, i-1, m-1, b, out, M, clock_l, fout);
		}
	}
}
	
int main() {  
	ofstream fout("clocks.out");
    ifstream fin("clocks.in");
    int a;
	int i, j;
	int seq[27] = {9,9,9,8,8,8,7,7,7,6,6,6,5,5,5,4,4,4,3,3,3,2,2,2,1,1,1}, seq_l[27], b[27];

	for(i=0; i<9; i++)
    {
    	long temp;
    	fin >> a;
		if(a==3) temp = 1;
		else if(a==6) temp = 2;
		else if(a==9) temp = 3;
		else if(a==12) temp = 0;
		if(i)
		clocks <<= 3;
		clocks |= temp;		
	}

	for(i=1; i<=12; i++)
	{
		combine(seq, 27, i, b, seq_l, i, clocks, fout);
	}
    return 0;
}
