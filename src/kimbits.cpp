/*
ID:wo__che1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

unsigned int t[32][32];

void init()
{
	int i,j;
	for(j=0;j<32;j++) t[0][j]=1;
	for(j=0;j<32;j++) t[j][0]=1;
	for(i=1;i<32;i++)
		for(j=1;j<32;j++)
		{
			t[i][j]=t[i-1][j]+t[i-1][j-1];//start with 0 + start with 1
		}
}

int main(void)
{
	unsigned int N,L,I;
    int i;
	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");
	fin>>N>>L>>I;
	init();
	for(i=N;i>=1;i--)
	{
		if(I>t[i-1][L])
		{
			fout<<'1';
			I-=t[i-1][L];
			L--;
		}
		else
		{
			fout<<'0';
		}
	}
	fout<<endl;
	return 0;
}
