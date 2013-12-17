/*
ID:wo__che1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
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

bool is_pal(string &str) {
	string temp = str;
	reverse(str.begin(), str.end());
	return temp == str;
}

int main() {
    freopen("palsquare.out", "w", stdout);
    freopen("palsquare.in", "r", stdin);
	int B, square;
	string str_i, str_square;
	cin >> B;
	
	for(int i=1; i<=300; i++) {
		square = i*i;
		str_i = convert(i, B);
		str_square = convert(square, B);
		if(is_pal(str_square)) {
			cout << str_i << " " << str_square << endl;
		}
	}
	return 0;
}