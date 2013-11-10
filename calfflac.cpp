/*
ID:wo__che1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

char str[20001];
char palindrome[2000];
int type = 0;
int g_start, g_end;

bool isalphabetic(char c)
{
	if(c<='Z'&&c>='A') return 1;
	else if(c<='z'&&c>='a') return 1;
	else return 0;
}

int process(int length, int start, int end, int t, int *start1, int *end1)
{
	int p, q, len;
	p = start;
	q = end;
	if(t == 1)
	{
		len = 0;
	}
	else
	{
		len = 1;
	}
	while(1)
	{
		while(!isalphabetic(str[p])) 
		{
			if(p>0)
				p--;
			else
				return len;
		}
		while(!isalphabetic(str[q])) 
		{
			if(q<length)
				q++;
			else
				return len;
		}
		if((str[p] == str[q]) ||((str[p] - str[q]) == 32 ) || ((str[q] - str[p]) == 32 ))
		{
			len+=2;
			*start1 = p;
			*end1 = q;
			if(p>0&&q<length)
			{
				p--;
				q++;
			}
			else break;
		}
		else break;
	}	
	return len;
}

void copy(int start, int end)
{
	int i;
	for(i=start; i<=end; i++)
	{
		palindrome[i-start] = str[i];
	}
	return;
}

int main() {
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
	int i, j, k, length, len=0, old_len = 0, start, end;
	char c;
	for(i=0; (fin.get(c))&&(i<20000); i++)
	{
		str[i] = c;		
	}
	length = i;

	if(length == 1)
	{
		fout << length << endl;
		fout << str[0] << endl;
		return 0;
	}

	if(length == 2)
	{
		if((str[0] == str[1]) ||((str[0] - str[1]) == 32 ) || ((str[1] - str[0]) == 32 ))
		{
			fout << length << endl;
			fout << str[0] << str[1] << endl;
		}
		else
		{
			fout << length-1 << endl;
			fout << str[0] << endl;
		}
		return 0;
	}

	for(i=0; i<length; i++)
	{
		while(!isalphabetic(str[i])) i++;
		j = i+1;
		while(!isalphabetic(str[j])&&j<length) j++;
		k = j+1;
		while(!isalphabetic(str[k])&&k<length) k++;
		if((j==length)||(k==length)) break;
		if((str[i] == str[j]) ||((str[i] - str[j]) == 32 ) || ((str[j] - str[i]) == 32 )) 
		{
			type = 1;
			len = process(length, i, j, type, &start, &end);
			if(len > old_len) 
			{
				copy(start, end);
				old_len = len;
				g_start = start;
				g_end = end;
			}
		}
		if((str[i] == str[k]) ||((str[i] - str[k]) == 32 ) || ((str[k] - str[i]) == 32 ))
		{
			type = 2;
			len = process(length, i, k, type, &start, &end);
			if(len > old_len) 
			{
				copy(start, end);
				old_len = len;
				g_start = start;
				g_end = end;
			}
		}
	}

	fout << old_len << endl;
	
	for(i=0; i<g_end - g_start + 1; i++)
	{
		fout << palindrome[i];
	}
	fout << endl;
		
    return 0;
}
