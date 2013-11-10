/*
ID:wo__che1
PROG: agrinet
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;
#define INF 0x7fffffff
int N, treesize, treecost;
int adj[100][100];
int dist[100];
int source[100];
bool intree[100];
int mindistance[2] = {INF, -1};

void readData()
{
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			cin>>adj[i][j];
			if(!adj[i][j]) adj[i][j] = INF;
		}
		dist[i] = INF;
		source[i] = -1;
		intree[i] = false;
	}
}

void MST()
{
	int i, j;
	treesize = 1;
	intree[0] = true;
	for(i=0; i<N; i++)
	{
		if(adj[0][i]!=INF) 
		{
			dist[i] = adj[0][i];
		}
		source[i] = 0;
	}
	while(treesize<N)
	{
		for(i=1; i<N; i++)
		{
			if(dist[i]<mindistance[0])
			{
				mindistance[0] = dist[i];
				mindistance[1] = i;
			}
		}
		treesize++;
		intree[mindistance[1]] = true;
		treecost += dist[mindistance[1]];
		dist[mindistance[1]] = INF;
		mindistance[0] = INF;
		for(i=1; i<N; i++)
		{
			if(!intree[i]&&adj[mindistance[1]][i]!=INF)
			{
				if(dist[i]>adj[mindistance[1]][i])
				{
					dist[i] = adj[mindistance[1]][i];
					source[i] = mindistance[1];
				}
			}
		}
	}
}

int main() 
{   
	
	freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>N;
	readData();
	MST();
	cout<<treecost<<endl;
	return 0;
}
