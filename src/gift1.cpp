/*
ID:wo__che1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	freopen ("gift1.in", "r", stdin);
	freopen ("gift1.out", "w", stdout);
	vector<string> name_v;
	map<string, int> money_amount;
	int size, i=0, j, money_orig, money_given_number;
	cin>>size;
	name_v.resize(size);
	while(i<size){
		cin>>name_v[i];
		money_amount[name_v[i]] = 0;
		i++;
	}
	for(i=0; i<size; i++){
		string name;
		int money_given_each;
		cin>>name;
		cin>>money_orig>>money_given_number;
		if(!money_orig || !money_given_number) continue;
		money_given_each = money_orig/money_given_number;
		money_amount[name] -= (money_orig - money_orig%money_given_number);
		for(j=0; j<money_given_number; j++){
			cin>>name;
			money_amount[name] += money_given_each;
		}
	}
	for(i=0; i<size; i++){
		cout<<name_v[i]<<" "<<money_amount[name_v[i]]<<endl;
	}
	return 0;
}