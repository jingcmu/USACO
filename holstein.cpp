/*
ID:wo__che1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int min_time=15;
int min_seq[1000];
int len, min_seq1;
int v_require[25];
int feed[15][25];
const int loop_time[15] = 
{1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767};
int main() {
    ofstream fout("holstein.out");
    ifstream fin("holstein.in");
	int V, G;
	int v_get[25];
	int i, j;
	int now, num;
	fin>>V;
	for(i=0; i<V; i++)
	{
		fin>>v_require[i];
	}
	fin>>G;
	for(i=0; i<G; i++)
		for(j=0; j<V; j++)
		{
			fin>>feed[i][j];
		}
	for(i=1; i<=loop_time[G-1]; i++)
	{
		int temp_i = i;
		now = G-1;
		num = 0;
		for(j=0; j<V; j++)
		{
			v_get[j] = 0;
		}
		while(temp_i)
		{
			if(temp_i%2)
			{
				for(j=0; j<V; j++)
				{
					v_get[j]+=feed[now][j];
				}
				num++;
			}
			temp_i>>=1;
			now--;
		}
		for(j=0; j<V; j++)
		{
			if(v_get[j]<v_require[j]) 
			{
				break;
			}
		}
		if(j==V)
		{
			if(num<min_time)
			{
				min_time = num;
				len = 0;
				min_seq[len++] = i;
			}
			else if(num==min_time)
			{
				min_seq[len++] = i;
			}
		}
	}
	min_seq1 = min_seq[0];
	for(i=1; i<len; i++)
	{
		if(min_seq[i]>min_seq1)
			min_seq1  = min_seq[i];
	}

	int out[15], l1=0;

	int temp = G;
	while(min_seq1)
	{
		if(min_seq1%2)
		{
			out[l1++] = temp;
		}
		min_seq1>>=1;
		temp--;
	}
	fout<<min_time<<" ";
	for(i=min_time-1; i>0; i--)
	{
		fout<<out[i]<<" ";
	}
	fout<<out[0]<<endl;
	return 0;
}
