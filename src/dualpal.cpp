/*
ID:wo__che1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string convert(int Num, int base) {
	string s = "";
	do {
		int residue = (Num%base);
		s += residue+(residue<10?48:55);
		Num = (Num-residue)/base;
	} while(Num!=0);
	reverse(s.begin(), s.end());
	return s;
}

int main() {
    freopen("dualpal.out", "w", stdout);
    freopen("dualpal.in", "r", stdin);
	string str, tmp;
    int N, S, i, fn = 0;
    cin >> N >> S;
	i = S;
	while(i++) {
		int n = 0;
		for(int j=2; j<=10; j++) {		//base 2 to 10
			tmp = str = convert(i, j);	
			reverse(tmp.begin(), tmp.end());
			if(tmp == str) n++;
			if(n>=2) break;
		}

		if( n >= 2 ) {
			fn++;	
			cout << i << endl;
			if(fn >= N) break;
		}
	}    
    return 0;
}