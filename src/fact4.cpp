/*
ID:wo__che1
PROG: fact4
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N,i,mul=1;
	FILE *fin,*fout;
	fin=fopen("fact4.in","r");
	fout=fopen("fact4.out","w");
	fscanf(fin,"%d",&N);
	for(i=1;i<=N;i++)
	{
		mul*=i;
		while(!(mul%10))
		{
			mul/=10;
		}
		if(mul>99999)
		{
			mul%=100000;
		}
	}
	while(!(mul%10))
	{
		mul/=10;
	}
	fprintf(fout,"%d\n",mul%10);
	return 0;
}
