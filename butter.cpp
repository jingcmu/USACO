/*
ID:wo__che1
PROG: butter
LANG: C
*/

#include <stdio.h>
#define INF 32767
int N,P,C;
int pastures[501];
int path[1451][3];
int dist[801][801];
int shortest[801];
FILE *fin,*fout;

void input()
{
	int i,j;
	fin=fopen("butter.in","r");
	fout=fopen("butter.out","w");
	fscanf(fin,"%d %d %d",&N,&P,&C);
	for(i=1;i<=N;i++)
	{
		fscanf(fin,"%d",&pastures[i]);
	}
	for(i=1;i<=C;i++)
	{
		fscanf(fin,"%d %d %d",&path[i][0],&path[i][1],&path[i][2]);
		dist[path[i][0]][path[i][1]]=path[i][2];
		dist[path[i][1]][path[i][0]]=path[i][2];
	}
	for(i=1;i<=P;i++)
		for(j=1;j<=P;j++)
		{
			if(i==j)
				dist[i][j]=0;
			else if(!dist[i][j])
			{
				dist[i][j]=INF;
			}
		}

}

void Floyd()
{
	int i,j,k;
    for (k=1; k<=P; ++k )
    {
        for (i=1; i<=P; ++i )
        {
            for (j=i+1; j<=P; ++j )
            {
                if ( k==i || k==j ) continue;
                if ( dist[i][k]+dist[k][j]<dist[i][j] )
                {
                	dist[j][i]=dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
}// Floyd

void getShortest()  //用最短路径算法求出每个点到所有点的最短路径和
{
	int i,j;
	for(i=1;i<=P;i++)
	{
		for(j=1;j<=N;j++)
		{
			shortest[i]+=dist[i][pastures[j]];
		}
	}
}

int main(void)
{
	int i,shortPath=2147483647;
	input();
	Floyd();
	getShortest();
	for(i=1;i<=P;i++)
	{
		if(shortPath>shortest[i])
			shortPath=shortest[i];
	}
	fprintf(fout,"%d\n",shortPath);
	return 0;
}
