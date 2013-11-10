/*
ID:wo__che1
PROG: humble
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff

int K, N;
int hum_num[100001];
int S[100], record[100];

void readS()
{
	int i;
	for(i=0; i<K; i++)
	{
		cin>>S[i];
	}
}

void getNthHumNum()
{
	int i, j;
	hum_num[0] = 1;
	int p[100], min, index;
	for(i=1; i<=N; i++)
	{
		min = INF;
		for(j=0; j<K; j++)
		{
			while( (p[j]=S[j]*hum_num[record[j]])<=hum_num[i-1] )
			{
				record[j]++;
			}
			if(p[j]<min)
			{
				min = p[j];
				index = j;
			}
		}
		record[index]++;
		hum_num[i] = min;
	}
	return;
}

int main() 
{
	int i;
	freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>K>>N;
	readS();
	sort(S, S+K);	
	getNthHumNum();
	cout << hum_num[N] << endl;
	return 0;
}
