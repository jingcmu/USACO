/*
ID:wo__che1
PROG: sprime
LANG: C++
*/
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

//用两个buffer交替存储可以代替queue操作，
//但是需要知道当前操作的是哪个buffer
int a[1000];
int b[1000];
//最后一位是偶数或者是5的不可能是素数
int c[4] = {1, 3, 7, 9};

bool is_prime(int x)
{
	int i;
	int sq = sqrt((float)x); 
	for(i=2; i<=sq; i++) {
		if(x%i==0) return false;
	}
	return true;
}

int main() {
    freopen("sprime.out", "w", stdout);
    freopen("sprime.in", "r", stdin);
	int len, num_a = 4, num_b = 0; //分别存缓冲区a和b的长度
	cin >> len;
	a[0] = 2; a[1] = 3; a[2] = 5; a[3] = 7;
	
	for(int i=1; i<len; i++) {
		if(i%2) { //奇数操作b缓冲区
			num_b = 0; //b缓冲区清掉
			for(int j=0; j<num_a; j++) {
				for(int k=0; k<4; k++) {
					if(is_prime(a[j]*10+c[k])) {
						b[num_b++] = a[j]*10+c[k];
					}
				}
			}
		}
		else {	//偶数操作a缓冲区
			num_a = 0; //a缓冲区清掉
			for(int j=0; j<num_b; j++) {
				for(int k=0; k<4; k++) {
					if(is_prime(b[j]*10+c[k])) {
						a[num_a++] = b[j]*10+c[k];
					}
				}
			}
		}
	}
	if(len%2) {
		for(int i=0; i<num_a; i++)
			cout << a[i] << endl;
	}
	else {
		for(int i=0; i<num_b; i++)
			cout << b[i] << endl;
	}
    return 0;
}
