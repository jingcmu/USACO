/*
ID:wo__che1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	char c=0;
	string s;
	int N,a=0,b=0,w=0,ans=0;
	cin>>N>>s;
	s = s+s;
	for (int i = 0; i < 2*N; i++) {
		if (s[i] == 'w') b++,w++;
		else if (s[i] == c) b++,w=0;
		else {
			c = s[i];
			ans = a+b>ans?a+b:ans; 
			a = b-w;  //a记录上一个字符串的长度
			b = w+1; //b记录这个字符串长度
			w = 0;
		}
	}
	ans = max(ans, a+b);
	cout<<min(ans, N)<<endl;
	return 0;
}