/*
ID:wo__che1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//1:R90,2:R180,3:R270,4:REFLACTION,5:REF_R90,6:REF_R180,7:REF_R270
void get_all_trans(vector<char> &orig, vector<vector<char> > &trans, int N)
{
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			trans[4][i*N+j] = orig[i*N+N-1-j];
		}
	}
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			trans[1][i*N+j] = orig[(N-1-j)*N+i];
			trans[2][i*N+j] = orig[(N-1-i)*N+N-1-j];
			trans[3][i*N+j] = orig[j*N+N-1-i];
			trans[5][i*N+j] = trans[4][(N-1-j)*N+i];
			trans[6][i*N+j] = trans[4][(N-1-i)*N+N-1-j];
			trans[7][i*N+j] = trans[4][j*N+N-1-i];
		}
	}
}

int choose_pattern(vector<char> &final, vector<vector<char> > &trans, int N) {
		int i, j, pattern;
		for(pattern=1; pattern <=7; pattern++) {
			for(i=0; i<N; i++) {
				for(j=0; j<N; j++) {
					if(final[i*N+j] != trans[pattern][i*N+j]) {
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
	int N, i, j, pattern = 10, N_square;
	vector<char> orig, final;
	vector<vector<char> > trans(8);
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
    cin >> N;
	N_square = N*N;
	orig.resize(N_square);
	final.resize(N_square);
	for(i=1; i<=7; i++)	{
		trans[i].resize(N_square);
	}

	for(i=0; i<N_square; i++) {
		cin >> orig[i];	
	}

	for(i=0; i<N_square; i++) {
		cin >> final[i];	
	}

	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(orig[i*N+j] != final[i*N+j])
				break;
		}
		if(j!=N) break;
	}
	
	if(i == N) pattern = 6;  //no change
	get_all_trans(orig, trans, N);  
	pattern = min(pattern, choose_pattern(final, trans, N));

    if(pattern == 8 ) pattern = 7;
	else if(pattern >4) pattern = 5; //5 6 7代表4 + 1 2 3的一种

    cout << pattern << endl;
    return 0;
}