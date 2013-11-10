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

int complete(int trans_clock[], long clock_l)
{
	int i, j;
	for(i=1; i<=9; i++)
	{
		for(j=0; j<trans_clock[i]; j++)
		{
			clock_l += moveTable[i];
			clock_l &= CLEAR;
		}
	}
	if(!clock_l)
		return 1;
	else
		return 0;
}

void try_all(long clock_l, ofstream &fout)
{
	int i, j, length = 0;
	int t[10];
	int result[28];
	int trans_clock[10];
	for(t[9]=0; t[9]<=3; t[9]++)
	for(t[8]=0; t[8]<=3; t[8]++)
	for(t[7]=0; t[7]<=3; t[7]++)
	for(t[6]=0; t[6]<=3; t[6]++)
	for(t[5]=0; t[5]<=3; t[5]++)
	for(t[4]=0; t[4]<=3; t[4]++)
	for(t[3]=0; t[3]<=3; t[3]++)
	for(t[2]=0; t[2]<=3; t[2]++)
	for(t[1]=0; t[1]<=3; t[1]++)
	{
		trans_clock[1] = t[1];
		trans_clock[2] = t[2];
		trans_clock[3] = t[3];
		trans_clock[4] = t[4];
		trans_clock[5] = t[5];
		trans_clock[6] = t[6];
		trans_clock[7] = t[7];
		trans_clock[8] = t[8];
		trans_clock[9] = t[9];
		if(complete(trans_clock, clock_l))
		{
			for(i=1; i<=9; i++)
			{
				for(j=0; j<t[i]; j++)
				{
					result[length++] = i;
				}
			}
			for(i=0; i<length-1; i++)
				fout <<result[i] <<" ";
			fout <<result[length-1]<<endl;
			goto FLAG;
		}
	}
FLAG:
	return;
}
	
int main() 
{  
	ofstream fout("clocks.out");
    ifstream fin("clocks.in");
    int a;
	int i, j;
	
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
	
	try_all(clocks, fout);
    return 0;
}
