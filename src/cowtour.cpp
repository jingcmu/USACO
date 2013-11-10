/*
ID:wo__che1
PROG: cowtour
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

#define INF 1000000

typedef struct
{
	int x; int y;
}vertex;
vertex V[150];
bool adj[150][150], visit[150];
double shortPath[150][150];
double largePath[150];
double max_diameter = INF;
int visited;
double diameters[150];
int num_of_field, belongField[150];

void readData(int n)
{
	int i, j;
	char c;
	for(i=0; i<n; i++)
	{
		cin>>V[i].x>>V[i].y;
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cin>>c;
			if(i==j)
			{
				shortPath[i][j] = 0;
			}
			else if(c=='1')
			{
				adj[i][j] = true;
				shortPath[i][j] = sqrt((double)(V[i].x-V[j].x)*(V[i].x-V[j].x) + (V[i].y-V[j].y)*(V[i].y-V[j].y));
			}
			else
			{
				adj[i][j] = false;
				shortPath[i][j] = INF;
			}
		}
	}
}

void Floyd(int n)
{
	int i, j, k;
	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
			{
				if(shortPath[i][j]>shortPath[i][k]+shortPath[k][j])
					shortPath[i][j] = shortPath[i][k]+shortPath[k][j];
			}
}

void getLargepath(int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if((largePath[i]<shortPath[i][j])&&(shortPath[i][j]<INF))
				largePath[i] = shortPath[i][j];
		}
	}
}

void check_field(int index, int n)
{
	if(visit[index]) return;
	else 
	{
		visit[index] = true;
		belongField[index] = num_of_field;
	}
	if(diameters[num_of_field]<largePath[index])
		diameters[num_of_field] = largePath[index];
	for(int i=0; i<n; i++)
	{
		if(adj[index][i])
			check_field(i, n);
	}
}

void getDiameter(int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		if(!visit[i])
		{
			check_field(i, n);
			num_of_field++;
		}
	}
}

int main() 
{   
	int i, j, k;
	int N;
	double diameter;
	freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);  freopen("CON", "w", stdout);
	cin>>N;
	readData(N);
	Floyd(N);
	getLargepath(N);
	getDiameter(N);
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			if(belongField[i]!=belongField[j])
			{
				shortPath[i][j] = sqrt((double)(V[i].x-V[j].x)*(V[i].x-V[j].x) + (V[i].y-V[j].y)*(V[i].y-V[j].y));
				diameter = largePath[i] + largePath[j] + shortPath[i][j];
				if(diameter>diameters[belongField[i]]&&diameter>diameters[belongField[j]]) 
				{
					int flag = true;
					for(k=0; k<num_of_field; k++)
					{
						if(diameters[k]&&k!=belongField[i]&&k!=belongField[j])
						{  
							if(diameter>diameters[k])
								flag = false;
							max_diameter = max_diameter>diameters[k]? diameters[k]:max_diameter;
						}
					}
					if(flag)
						max_diameter = max_diameter>diameter? diameter:max_diameter;
				}
				else
				{
					double max;
					max = diameters[belongField[i]]>diameters[belongField[j]]? diameters[belongField[i]]:diameters[belongField[j]];
					max_diameter = max_diameter>max? max:max_diameter;
				}
				shortPath[i][j] = INF;
			}
		}
		
	if(max_diameter<10)
		cout<<showpoint<<setprecision(7)<<max_diameter<<endl;
	else if(max_diameter<100)
		cout<<showpoint<<setprecision(8)<<max_diameter<<endl;
	else if(max_diameter<1000)
		cout<<showpoint<<setprecision(9)<<max_diameter<<endl;
	else if(max_diameter<10000)
		cout<<showpoint<<setprecision(10)<<max_diameter<<endl;
	else if(max_diameter<100000)
		cout<<showpoint<<setprecision(11)<<max_diameter<<endl;
	return 0;
}
