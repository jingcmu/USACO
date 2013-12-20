/*
ID:wo__che1
PROG: sprime
LANG: C++
*/
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

//������buffer����洢���Դ���queue������
//������Ҫ֪����ǰ���������ĸ�buffer
int a[1000];
int b[1000];
//���һλ��ż��������5�Ĳ�����������
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
	int len, num_a = 4, num_b = 0; //�ֱ�滺����a��b�ĳ���
	cin >> len;
	a[0] = 2; a[1] = 3; a[2] = 5; a[3] = 7;
	
	for(int i=1; i<len; i++) {
		if(i%2) { //��������b������
			num_b = 0; //b���������
			for(int j=0; j<num_a; j++) {
				for(int k=0; k<4; k++) {
					if(is_prime(a[j]*10+c[k])) {
						b[num_b++] = a[j]*10+c[k];
					}
				}
			}
		}
		else {	//ż������a������
			num_a = 0; //a���������
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
