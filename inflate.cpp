/*
ID:wo__che1
PROG: inflate
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;
#define INF 0x7fffffff

int M, N;
int catelog[10000][2];  
int score[10001];

int max(int a, int b)
{
	return a>b?a:b;
}

void readData()
{
	int i;
	for(i=0; i<N; i++)
	{
		cin>>catelog[i][0]>>catelog[i][1]; 	//score and cost
	}
}

void getScore()
{
	int i, j;
	score[0] = 0;
	for(i=0; i<N; i++)
	{
		for(j=catelog[i][1]; j<=M; j++)
		{
			score[j] = max(score[j], score[j-catelog[i][1]]+catelog[i][0]);
		}
	}
}

int main() 
{
	int i;
	freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>M>>N;
	readData();
	getScore();
	cout<<score[M]<<endl;
	return 0;
}
