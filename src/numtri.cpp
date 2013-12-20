/*
ID:wo__che1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    freopen("numtri.out", "w", stdout);
    freopen("numtri.in", "r", stdin);
	int line;
    int a[1001] = {0};
	int b[1001] = {0};
	cin>>line;
	for(int i=1; i<=line; i++) {
		for(int j=1; j<=i; j++) {
			if(i%2)	{ //odd line
				cin>>a[j];
				a[j] += max(b[j-1], b[j]);
			}
			else {		//even line
				cin>>b[j];
				b[j] += max(a[j-1], a[j]);
			}	
		}
	}

	if(line%2) { //odd line
		cout<< *max_element(a+1, a+line+1) << endl;
	}
	else {	//even line
		cout<< *max_element(b+1, b+line+1) << endl;
	}
    return 0;
}