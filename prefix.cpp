/*
ID:wo__che1
PROG: prefix
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

char str[200][10];
char str_s[11][200][10];
int len, len_tmp, len_s[11], len_S, max_len, longest;

bool table[200000];
char S[200000];
long call;

void copy_str(int len, int len_tmp)
{
	int i, j;
	for(i=0; i<len_tmp; i++)
	{
		str_s[len_tmp][len_s[len_tmp]][i] = str[len][i];
	}
	len_s[len_tmp]++;
	if(len_tmp>max_len) max_len = len_tmp;
	return;
}

void find_prefix(int current_len)
{
	int i, j, k;
	call++;
	table[current_len] = true;
	for(i=1; i<=max_len; i++)
	{
		if(table[current_len+i])
			continue;
		for(j=0; j<len_s[i]; j++)
		{
			for(k=0; k<i; k++)
			{
				if(S[current_len+k] != str_s[i][j][k])
				{
					break;			
				}
			}
			if(k==i)
			{
				find_prefix(current_len+i);
			}
		}
	}
	if(current_len>longest) longest = current_len;
}

int main() {
	char c;
	int i, j, k, p;
	bool flag;
	freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);  freopen("CON", "w", stdout);
	while(1)
	{
		c = getchar();
		if(c=='.') 
		{
			if(flag)
			{
				//str[len][len_tmp++] = '@';
				copy_str(len, len_tmp);
				len++;
			}
			break;
		}
		if(c!=' '&&c!='\r'&&c!='\n')
		{
			flag = 1;
			str[len][len_tmp++] = c;
		}
		else
		{
			//str[len][len_tmp++] = '@';
			copy_str(len, len_tmp);
			len++;
			len_tmp=0;
			flag = 0;
		}
	}

	while(cin>>c) S[len_S++] = c;

	find_prefix(0);

	cout<<longest<<endl;
	cout<<"call : "<<call<<endl;
	return 0;
}
