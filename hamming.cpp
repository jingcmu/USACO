/*
ID:wo__che1
PROG: hamming
LANG: C++
*/
#include <bitset>
#include <fstream>
#include <iostream>

using namespace std;

short hamming[64];
short len;

int main() {
    int N, B, D;
	int i, j, xor_1, max, cur_num = 1;
	freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
	cin>>N>>B>>D;   //freopen("CON", "w", stdout);
	hamming[len++] = 0; 
	max = (1<<B)-1;
	while(len<N)
	{
		for(i=0; i<len; i++)
		{
			xor_1 = cur_num^hamming[i];
			bitset<8> b(xor_1);
			if(b.count()<D) break;
		}
		if(i==len) 
		{
			hamming[len++] = cur_num;
		}
		cur_num++;
	}
	for(i=0; i<len-1; i++)
	{
		cout<<hamming[i];
		if((i+1)%10) cout<<" ";
		else cout<<endl;
	}
	cout<<hamming[len-1]<<endl;
    return 0;
}