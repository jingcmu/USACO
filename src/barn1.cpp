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
//思路: 使用上最多的木板则木板总长度最小, 贪心法
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
	//最大就是使用一个木板
	max = stall_has_cow[stall_has_cow.size()-1] - stall_has_cow[0] + 1;
	//得到所有间隙
	for(int i=1; i<stall_has_cow.size(); i++) {
		if(stall_has_cow[i] != stall_has_cow[i-1]+1) { //不连续
			interval.push_back(stall_has_cow[i] - stall_has_cow[i-1] - 1);
		}
	}
	//把间隙排序, 使用了逆向迭代器
	sort(interval.rbegin(), interval.rend());
	//减去最大的间隙
	for(int i=0; i < min(block_num-1, (int)interval.size()); i++) {
		max -= interval[i];
	}
	cout << max << endl;
}