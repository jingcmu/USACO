/*
ID:wo__che1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N1, N2, N3;
int N1_2, N1_3, N2_1, N2_3, N3_1, N3_2;
int n[1000], n1[1000], n2[1000], n3[1000];

int count_swap() {
	int swap_time = 0;
	swap_time = min(N1_2, N2_1) + min(N1_3, N3_1) + min(N3_2, N2_3);
	swap_time += abs(N1_2-N2_1)*2;
	return swap_time;
}

int main() {
    ofstream fout("sort3.out");
    ifstream fin("sort3.in");
	int N, tmp;
	int i;
	fin >> N;
	for(i=0; i<N; i++) {
		fin>>tmp;
		if(tmp==1) 
			N1++;
		else if(tmp==2)
			N2++;
		else if(tmp==3)
			N3++;
		n[i] = tmp;
	}
	for(i=0; i<N1; i++) {
		n1[i] = n[i];
		if(n1[i]==2) N1_2++;
		else if(n1[i]==3) N1_3++;
	}
	for(i=0; i<N2; i++) {
		n2[i] = n[i+N1];
		if(n2[i]==1) N2_1++;
		else if(n2[i]==3) N2_3++;
	}
	for(i=0; i<N3; i++) {
		n3[i] = n[i+N1+N2];
		if(n3[i]==1) N3_1++;
		else if(n3[i]==2) N3_2++;
	}
	fout<<count_swap()<<endl;
	return 0;
}
