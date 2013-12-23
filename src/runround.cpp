/*
ID:wo__che1
PROG: runround
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
	
bool is_rr(int n) {
	int len = 0, i, N_char[9];
	int n_tmp = n;
	vector<bool> digital(10, false), digital1(10, false);
	while(n_tmp) {  //��ÿλ�����
		int dig_tmp = n_tmp%10;
		if(digital[dig_tmp] || !dig_tmp) 
			return false; //�ظ��ˡ�����dig_tmpΪ0
		digital[dig_tmp] = true;
		N_char[len++] = dig_tmp;
		n_tmp/=10;
	}
	reverse(N_char, N_char+len);//reverse the array
	int cur = 0;
	digital1[N_char[cur]] = true;
	for(i=1; i<len; i++) {
		cur = (cur+N_char[cur])%len;
		if(digital1[N_char[cur]]) return false;
		else
			digital1[N_char[cur]] = true;
	}
	cur = (cur+N_char[cur])%len;
	return !cur;  //����ֻص����
}

int main() {
	int i;
	unsigned int N;
	freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
	cin>>N;   //freopen("CON", "w", stdout);
	while(!is_rr(++N)) {} //����ѭ��ֱ���ҵ�
	cout << N << endl;
	return 0;
}