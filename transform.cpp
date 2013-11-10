/*
ID:wo__che1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum trans_pattern 
{
	R90 = 1,
	R180,
	R270,
	REFLACTION,
	REF_R90,
	REF_R180,
	REF_R270
};

void get_all_trans(char *orig, char **trans, int N)
{
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			trans[REFLACTION][i*N+j] = orig[i*N+N-1-j];
		}
	}
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			trans[R90][i*N+j] = orig[(N-1-j)*N+i];
			trans[R180][i*N+j] = orig[(N-1-i)*N+N-1-j];
			trans[R270][i*N+j] = orig[j*N+N-1-i];
			trans[REF_R90][i*N+j] = trans[REFLACTION][(N-1-j)*N+i];
			trans[REF_R180][i*N+j] = trans[REFLACTION][(N-1-i)*N+N-1-j];
			trans[REF_R270][i*N+j] = trans[REFLACTION][j*N+N-1-i];
		}
	}
}

int choose_pattern(char *final, char **trans, int N)
{
		int i, j, pattern;
		for(pattern=1; pattern <=7; pattern++)
		{
			for(i=0; i<N; i++)
			{
				for(j=0; j<N; j++)
				{
					if(final[i*N+j] != trans[pattern][i*N+j])
					{
						break;
					}					
				}
				if(j!=N) break;
			}
			if(i == N) break;
		}
		return pattern;
}

int main() {
    ofstream fout;
    ifstream fin;
	int N, i, j, pattern, N_square, final_pattern = 10;
	char *orig, *final;
	char *trans[8];
	fin.open("transform.in");
	fout.open("transform.out");
    fin >> N;
	N_square = N*N;
	orig = new char[N_square];
	final = new char[N_square];
	for(i=1; i<=7; i++)
	{
		trans[i] = new char[N_square];
	}

	for(i=0; i<N_square; i++)
	{
		fin >> orig[i];	
	}

	for(i=0; i<N_square; i++)
	{
		fin >> final[i];	
	}

	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(orig[i*N+j] != final[i*N+j])
				break;
		}
		if(j!=N) break;
	}
	
	if(i == N)
	{
		final_pattern = 6;
	}

	get_all_trans(orig, trans, N);

	pattern = choose_pattern(final, trans, N);

    if(pattern == 8 ) pattern = 7;
	else if(pattern >4) pattern = 5;

	if(final_pattern > pattern) final_pattern = pattern;
	
	delete(orig);
	delete(final); 
	for(i=1; i<=7; i++) 
		delete(trans[i]);     
	
    fout << final_pattern << endl;
    return 0;
}