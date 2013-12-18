/*
ID:wo__che1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
//˼·: ʹ��������ľ����ľ���ܳ�����С, ̰�ķ�
int main() {
	freopen("barn1.out", "w", stdout);
    freopen("barn1.in", "r", stdin);
	int block_num, stall_num, cow_num, max;
	vector<int> stall_has_cow;
	vector<int> interval;
	cin >> block_num >> stall_num >> cow_num;
	for(int i=0; i<cow_num; i++) {
		int stall_index;
		cin >> stall_index;
		stall_has_cow.push_back(stall_index);
	}
	sort(stall_has_cow.begin(), stall_has_cow.end());
	//������ʹ��һ��ľ��
	max = stall_has_cow[stall_has_cow.size()-1] - stall_has_cow[0] + 1;
	//�õ����м�϶
	for(int i=1; i<stall_has_cow.size(); i++) {
		if(stall_has_cow[i] != stall_has_cow[i-1]+1) { //������
			interval.push_back(stall_has_cow[i] - stall_has_cow[i-1] - 1);
		}
	}
	//�Ѽ�϶����, ʹ�������������
	sort(interval.rbegin(), interval.rend());
	//��ȥ���ļ�϶
	for(int i=0; i < min(block_num-1, (int)interval.size()); i++) {
		max -= interval[i];
	}
	cout << max << endl;
}