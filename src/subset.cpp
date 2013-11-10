/*
ID:wo__che1
PROG: subset
LANG: C++
*/
#include <fstream>
#include <iostream>

using namespace std;

unsigned int num[40][391];
int count(int n, int sum)
{
	int i, j;
	num[1][1] = 1;
	num[1][0] = 1;
	
	for(i=2; i<=n; i++)
		for(j=0; j<=sum; j++)
		{
			if(j-i>=0)
				num[i][j] = num[i-1][j] + num[i-1][j-i];
			else
				num[i][j] = num[i-1][j];
		}
		
	return num[n][sum]/2;
}

int main() {
	int N, i;
	freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
	cin>>N;   freopen("CON", "w", stdout);
	if(N*(N+1)%4) 
	{
		cout<<"0"<<endl;
	    return 0;
	}
	
	cout<<count(N, N*(N+1)/4)<<endl;
}
