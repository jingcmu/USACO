/*
ID:wo__che1
PROG: sprime
LANG: C++
*/
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

int num_a = 0, num_b = 0;
int a[1000];
int b[1000];
int c[4] = {1, 3, 7, 9};

bool is_prime(int x)
{
	int i;
	int sq = sqrt((float)x);
	for(i=2; i<=sq; i++)
	{
		if(x%i==0) return false;
	}
	return true;
}

int main() {
    ofstream fout("sprime.out");
    ifstream fin("sprime.in");
	int i, j, k, len;
	fin>>len;
	a[0] = 2; a[1] = 3; a[2] = 5; a[3] = 7;
	num_a = 4;
	
	for(i=1; i<len; i++)
	{
		if(i%2)
		{
			num_b = 0;
			for(j=0; j<num_a; j++)
			{
				for(k=0; k<4; k++)
				{
					if(is_prime(a[j]*10+c[k]))
					{
						b[num_b++] = a[j]*10+c[k];
					}
				}
			}
		}
		else
		{
			num_a = 0;
			for(j=0; j<num_b; j++)
			{
				for(k=0; k<4; k++)
				{
					if(is_prime(b[j]*10+c[k]))
					{
						a[num_a++] = b[j]*10+c[k];
					}
				}
			}
		}
	}
	if(len%2)
	{
		for(i=0; i<num_a; i++)
			fout<<a[i]<<endl;
	}
	else
	{
		for(i=0; i<num_b; i++)
			fout<<b[i]<<endl;
	}
    return 0;
}
