/*
ID:wo__che1
PROG: zerosum
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int operater[256][10];
int len[256], len_tmp;
int N, total;
char ch[20][50], ch_tmp[50];

void copy(char *ch_src, char *ch_dst)
{
	int i;
	for(i=0; ch_src[i]!='.'; i++)
	{
		ch_dst[i] = ch_src[i];
	}
	ch_dst[i] = '.';
	return;
}

void sort()
{
	int *index = new int[total];
	int i, j;
	for(i=0; i<total; i++)
	{
		index[i] = ch[i][1] - 30;
		for(j=3; ch[i][j]!='.'; j+=2)
		{
			index[i] = index[i]*10+ch[i][j] - 30;
		}
	}
	for(i=total-1; i>0; i--)
	for(j=0; j<i; j++)
	{
		if(index[j+1]<index[j])
		{
			int tmp; 
			tmp = index[j+1];
			index[j+1] = index[j];
			index[j] = tmp;
			copy(ch[j], ch_tmp);
			copy(ch[j+1], ch[j]);
			copy(ch_tmp, ch[j+1]);
		}
	}
	return;
}

int main() 
{   
	int N, i, j, N1, N2, result;
	freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>N;
	N1 = 1<<(N-1);
	
	for(i=0; i<N1; i++)
	{
		for(j=0; j<N; j++)
		{
			if((i>>j)&1)
			{
				if(!j)
					operater[i][len[i]] = (j+1)*10;
				else
					operater[i][len[i]] = (operater[i][len[i]]+(j+1))*10;
			}
			else
				operater[i][len[i]++] += (j+1);
		}
	}

	for(i=0; i<N1; i++)
	{
		for(j=0; j<(1<<(len[i]-1)); j++)
		{
			result = operater[i][0];
			for(int k=1; k<len[i]; k++)
			{
				if((j>>(k-1))&1)
					result += operater[i][k];
				else
					result -= operater[i][k];
			}
			if(!result) 
			{
				len_tmp = 0;
				for(int k=0; k<len[i]; k++)
				{
					int opte_tmp = operater[i][k];
					if(opte_tmp/100)
					{
						ch_tmp[len_tmp++] = opte_tmp/100+48;
						ch_tmp[len_tmp++] = ' ';
					}
					opte_tmp = opte_tmp%100;
					if(opte_tmp/10)
					{
						ch_tmp[len_tmp++] = opte_tmp/10+48;
						ch_tmp[len_tmp++] = ' ';
					}
					ch_tmp[len_tmp++] = opte_tmp%10+48;
					
					if(k!=len[i]-1)
					{
						if((j>>k)&1)
							ch_tmp[len_tmp++] = '+';
						else
							ch_tmp[len_tmp++] = '-';
					}
				}
				for(int k=0; k<len_tmp; k++)
				{
					ch[total][k] = ch_tmp[k];
				}
				ch[total++][len_tmp] = '.';
				//cout<<j<<endl;
			}
		}
	}
	sort();
	for(i=0; i<total; i++)
	{
		for(j=0; ch[i][j]!='.'; j++)
		{
			cout<<ch[i][j];
		}
		cout<<endl;
	}
	return 0;
}

