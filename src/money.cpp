/*
ID:wo__che1
PROG: money
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int coin[26];
long long combine[26][10001];
int main() 
{   
	int V, ALL, i, j, k;
	freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>V>>ALL;
	for(i=1; i<=V; i++)
	{
		cin>>coin[i];
	}
	for(j=1; j<=ALL; j++)
	{
		if((j%coin[1])==0)
			combine[1][j] = 1;
	}
	for(i=2; i<=V; i++)
		for(j=1; j<=ALL; j++)
		{
			combine[i][j] = combine[i-1][j];
			for(k=1; k*coin[i]<=ALL; k++)
			{
				if(j-k*coin[i]>0)
					combine[i][j] += combine[i-1][j-k*coin[i]];
				else if(j-k*coin[i]==0)
					combine[i][j]++;
				else
					break;
			}
		}
	cout<<combine[V][ALL]<<endl;
	return 0;
}

