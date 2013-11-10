/*
ID:wo__che1
PROG: butter
LANG: C
*/

#include <stdio.h>
#define MAXLEN 2001
int N_M[MAXLEN][MAXLEN];
int n,m,x,y;

void preProcess()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			N_M[i][j]=N_M[i-1][j]+N_M[i][j-1]-N_M[i-1][j-1]+N_M[i][j];
		}
}

int cover()
{
	int i,j,num=0,area=x*y;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i+x-1>n||j+y-1>m) {}
			else if(N_M[i+x-1][j+y-1]-N_M[i+x-1][j-1]-N_M[i-1][j+y-1]+N_M[i-1][j-1]==area)
				num++;
			if(i+y-1>n||j+x-1>m) {}
			else if(x!=y&&N_M[i+y-1][j+x-1]-N_M[i+y-1][j-1]-N_M[i-1][j+x-1]+N_M[i-1][j-1]==area)
				num++;
		}
	}
	return num;
}

int main(void)
{
	int i,j;
	char t;
	scanf("%d %d",&n,&m);
	while(n&&m)
	{
		scanf("%d %d",&x,&y);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%c",&t);
				while((t=='\n')||(t==' '))
					scanf("%c",&t);
				if(t=='*')
				{
					N_M[i][j]=1;
				}
			}
		}
		preProcess();
		printf("%d\n",cover());
		scanf("%d %d",&n,&m);
	}
	return 0;
}
