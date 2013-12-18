/*
ID:wo__che1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

map<int, bool> m;
//hash搜索法判断一个数是否属于集合
bool judge(int res, int a, int b) {
	return (m[res%10]&&m[(res/10)%10]&&m[(res/100)%10]&&m[res/1000]
			&&m[a%10]&&m[(a/10)%10]&&m[a/100]
			&&m[b%10]&&m[(b/10)%10]&&m[b/100]);
}
int main() {
    freopen("crypt1.out", "w", stdout);
    freopen("crypt1.in", "r", stdin);
	int N, num = 0;
	cin >> N;
	for(int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		m[tmp] = true;
	}
	for(int x=100; x<=999; x++) {
		for(int y=10; y<=99; y++) {
			int a, b, res;
			if(m[x%10]&&m[(x/10)%10]&&m[x/100]
				&&m[y%10]&&m[y/10]) {
				res = x*y; 
				a = (y%10)*x; 
				b = (y/10)*x;
				//若res大于4位数或ab大于3位数则y无需再试
				if(res > 9999 || a > 999 || b > 999 || a < 100 || b < 100) continue; 
				if(judge(res, a, b)) num++;
			}
		}
	}
	cout << num << endl;
}