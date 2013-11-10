/*
ID:wo__che1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

bool can[127000];
int bisquares[127000];
int out[1000][2];

int main()
{
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int a, b, a_minus1;
	int i, j, k, flag, num=0, sum=0;
	int diff, max_index;
	fin >>a >>b;
	a_minus1 = a-1;
	max_index = b*b*2;
	for(i=0; i<=b; i++)
		for(j=i; j<=b; j++)
			can[i*i+j*j] = true;
		
	for(i=0; i<=max_index; i++)
	{
		if(can[i]) bisquares[num++] = i;
	}

	for(i=0; i<num-a_minus1; i++)
	{
		for(j=i+1; j<num; j++)
		{
			flag = 1;
			diff = bisquares[j]-bisquares[i];
			if(i+diff*a_minus1>max_index)
				break;
			for(k=1; k<=a_minus1; k++)
			{
				if(!can[bisquares[i]+diff*k])
				{
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				out[sum][0] = bisquares[i];
				out[sum][1] = diff;
				sum++;
			}
		}
	}

	if(!sum) 
	{
		fout<<"NONE"<<endl;
		return 0;
	}
	for(i=0; i<sum; i++)
		for(j=sum-1; j>i; j--)
		{
			if(out[j-1][1]>out[j][1])
			{
				int temp;
				temp = out[j-1][1];
				out[j-1][1] = out[j][1];
				out[j][1] = temp;
				temp = out[j-1][0];
				out[j-1][0] = out[j][0];
				out[j][0] = temp;
			}
		}
	for(i=0; i<sum; i++)
	{
		fout <<out[i][0]<<" "<<out[i][1]<<endl;
	}
	return 0;
}