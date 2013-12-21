/*
ID:wo__che1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

typedef struct
{
	int nr;
	int dr;
}faction;

faction output[12800];
int len = 0;


inline int find_mcd(int a, int b) //a>b
{
	return b==0? a:find_mcd(b, a%b);
}

int cmp(faction a, faction b)
{
	return a.nr*b.dr>a.dr*b.nr?0:1;
}


int main() {
    ofstream fout("frac1.out");
    ifstream fin("frac1.in");
	int N, i , j, x = -1;
	fin>>N;
	output[0].nr = 0; output[0].dr = 1;
	len++;
	for(i=1; i<N; i++)
	{
		for(j=i+1; j<=N; j++)
		{
			if(find_mcd(j, i)==1) //非最简直接丢掉就行了
			{
				output[len].nr = i;
				output[len++].dr = j;
			}
		}
	}
	output[len].nr = 1;
	output[len++].dr = 1;
	sort(output, output+len, cmp);
	for(i=0; i<len; i++)
	{
		fout<<output[i].nr<<"/"<<output[i].dr<<endl;
	}
	return 0;
}
