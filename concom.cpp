/*
ID:wo__che1
PROG: concom
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool control[101][101];
short company[101][101];

int main() 
{   
	int i, j, k, p;
	int A, B, N, percent, max=0;
	freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>N;
	for(i=0; i<N; i++)
	{
		cin>>A>>B>>percent;
		if(A!=B)
			company[A][B] = percent;
		if(percent>50) 
			control[A][B] = true;
		if(A>max) max=A;
		if(B>max) max=B;
	}

	for(i=1; i<=max; i++)
	{
		int flag;
		
		for(j=1; j<=max; j++)
		{
			if(control[i][j])
			{
				for(k=1; k<=max; k++)
				{
					company[i][k]+=company[j][k];
					if(company[i][k]>100) company[i][k] = 100;
				}
			}
		}
		
		while(1)
		{
			flag = 0;
			for(j=1; j<=max; j++)
			{
				if(company[i][j]>50&&!control[i][j])
				{
					control[i][j] = true;
					flag = 1;
					for(k=1; k<=max; k++)
					{
						company[i][k]+=company[j][k];
						if(company[i][k]>100) company[i][k] = 100;
					}
					for(k=1; k<=max; k++)
					{
						if(control[k][i])
						{
							for(p=1; p<=max; p++)
							{
								company[k][p]+=company[j][p];
								if(company[k][p]>100) company[k][p] = 100;
							}
						}
					}
				}
			}
			if(!flag)
				break;
		}
	}

	for(i=1; i<=100; i++)
		for(j=1; j<=100; j++)
		{
			if(company[i][j]>50&&i!=j)
				cout<<i<<" "<<j<<endl;
		}
		
	return 0;
}

