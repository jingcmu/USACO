/*
ID:wo__che1
PROG: comehome
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;
#define INF 1000000
int N;
int adj[52][52];
bool visited[52];

void readData()
{
	int i, j, w;
	char src, dst;
	for(i=0; i<52; i++)
		for(j=0; j<52; j++)
			adj[i][j] = INF;
	for(i=0; i<N; i++)
	{
		int p1, p2;
		cin>>src>>dst>>w;
		if(src<'a') p1 = src - 65;
		else p1 = src - 71;
		if(dst<'a') p2 = dst - 65;
		else p2 = dst - 71;
		if(w<adj[p1][p2]) 
		{
			adj[p1][p2] = w;
			adj[p2][p1] = w;
		}
		if(p1 == p2)
			adj[p1][p2] = 0;
	}
}

void floyd()
{
	int i, j, k;
	for(k=0; k<52; k++)
		for(i=0; i<52; i++)
			for(j=0; j<52; j++)
			{
				if(adj[i][j]>adj[i][k]+adj[k][j])
					adj[i][j] = adj[i][k]+adj[k][j];
			}
}

int main() 
{   
	int i;
	char c;
	int min = INF, cur;
	freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>N;
	readData();
	floyd();
	for(i=0; i<=24; i++)
	{
		if(adj[i][25]<min)
		{
			min = adj[i][25];
			cur = i;
		}
	}
	c = (char)cur+65;
	cout<<c<<" "<<min<<endl;
	return 0;
}
