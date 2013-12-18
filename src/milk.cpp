/*
ID:wo__che1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int price;
	int amount;
} farmer ;

int cmp(farmer f1, farmer f2) {
	return f1.price < f2.price;
}

int main() {
    freopen("milk.out", "w", stdout);
    freopen("milk.in", "r", stdin);
    int total_milk, M, i, P, A;
	long total_price = 0, amount  = 0;
	vector<farmer> v_farmer;
	farmer f;
    cin >> total_milk >> M;
	for(i=0; i<M; i++) {
		cin >> P >> A;
		f.price = P;
		f.amount = A;
		v_farmer.push_back(f); //把所有farmer放入vector
	}
	sort(v_farmer.begin(), v_farmer.end(), cmp); //对farmer进行排序
	for(i=0; amount < total_milk; ++i) {
		total_price += v_farmer[i].price * v_farmer[i].amount;
		amount += v_farmer[i].amount;
	}
	if(amount - total_milk > 0) {
		total_price -= v_farmer[--i].price * (amount - total_milk);
	}
	cout << total_price << endl;
    return 0;
}