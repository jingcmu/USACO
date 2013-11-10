/*
ID:wo__che1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef struct 
{
	int value;
	int index;
} L1;

int compare(L1 l1, L1 l2)
{
	if(l1.value > l2.value)
	{

		return 1;
	}
	else
		return 0;
}

int main()
{
	ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
	int M, S, C, total = 0;
	int *l, *M1, i;
	L1 *l1;
	fin >> M >> S >> C;
	M--;
	l = new int[C];
	l1 = new L1[C];
	if(M)
	{
		M1 = new int[M];
	}

	for(i=0; i<C; i++)
	{
		fin >> l[i];
	}

	sort(l, l+C);
	if(M>=C)  total = C;
	else if(M)
	{			
		l1[0].value = 0;
		l1[0].index = 0;
		
		for(i=1; i<C; i++)
		{		
			l1[i].value = l[i] - l[i-1];
			l1[i].index = i-1;
		}

		sort(l1, l1+C, compare);
		for(i=0; i<M; i++)
		{
			M1[i] = l1[i].index;
		}

		sort(M1, M1+M);

		total += (l[M1[0]] - l[0] + 1);
		for(i=1; i<M; i++)
		{
			total += (l[M1[i]]-l[M1[i-1]+1] + 1);
		}
		total += (l[C-1] - l[M1[M-1]+1] + 1);
	}
	else
	{
		total = (l[C-1] - l[0] + 1);
	}
	fout << total << endl;
	delete(l);
	delete(l1);
	if(M)
	{
		delete(M1);
	}
}