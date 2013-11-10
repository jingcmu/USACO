/*
ID:wo__che1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
	int line, max=0;
	int i, j;
    int a[1001] = {0};
	int b[1001] = {0};
	fin>>line;
	for(i=1; i<=line; i++)
	{
		for(j=1; j<=i; j++)
		{
			if(i%2)	//odd line
			{
				fin>>a[j];
				a[j]+=(b[j-1]>b[j]?b[j-1]:b[j]);
			}
			else		//even line
			{
				fin>>b[j];
				b[j]+=(a[j-1]>a[j]?a[j-1]:a[j]);
			}	
		}
	}

	if(line%2)	//odd line
	{
		for(i=1; i<=line; i++)
		{
			if(max<a[i])
				max = a[i];
		}
	}
	else		//even line
	{
		for(i=1; i<=line; i++)
		{
			if(max<b[i])
				max = b[i];
		}
	}

	fout << max<<endl;
    return 0;
}