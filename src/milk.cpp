/*
ID:wo__che1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct 
{
	int price;
	int amount;
} farmer ;

int cmp(farmer f1, farmer f2)
{

	if(f1.price < f2.price)
	{
		return 1;
	}
	else return 0;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int N, M, i, P, A;
	long total = 0, amount_1  = 0;
	vector<farmer> v_farmer;
	farmer far;
    fin >> N >> M;
	for(i=0; i<M; i++)
	{
		fin >> P >> A;
		far.price = P;
		far.amount = A;
		v_farmer.push_back(far);
	}
	sort(v_farmer.begin(), v_farmer.end(), cmp);

	for(i=0; amount_1 < N; i++)
	{
		total += v_farmer[i].price * v_farmer[i].amount;
		amount_1 += v_farmer[i].amount;
	}
	i--;
	amount_1 = amount_1-N;
	if(amount_1>0)
	{
		total -= v_farmer[i].price * amount_1;
	}
	fout << total << endl;
    return 0;
}