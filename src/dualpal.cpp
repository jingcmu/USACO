/*
ID:wo__che1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
char str[100];

int convert(int Num, int base)
{
	int i = 0, residue;
	do
	{
		residue = (Num%base);
		i++;
		str[i] = residue+48;
		Num -= residue;
		Num /= base;
	}while(Num!=0);
	
	return i;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int N, S, i, j, k, fn, len, n, equal;
    fin >> N >> S;

	fn = 0;
	
	for(i=S+1; i<32767; i++)
	{
		n = 0;
		for(j=2; j<=10; j++)
		{
			len = convert(i, j);
			k = 1;
			equal = 1;
			while(len>=k)
			{
				if(str[k++]!=str[len--])
				{
					equal = 0;
					break;
				}					
			}
			if(equal) n++;
			if(n>=2) break;
		}

		if( n >= 2 )				//condition
		{
			fn++;
			fout << i << endl;
			if(fn >= N)
			{
				break;
			}
		}
	}
    
    return 0;
}