/*
ID:wo__che1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int result[7] = {0};
void calculate(int year) {
	int day = 0; //ÐÇÆÚÒ»
	for(int i=1900; i<1900+year; i++){
		if(i%100 == 0? (i%400 == 0):(i%4 == 0)) month_day[1]++;
		for(int j=0; j<12; j++) {
			result[day]++;
			day = (day+month_day[j])%7;
		}
		month_day[1] = 28;
	}
}

int main() {
	freopen ("friday.in", "r", stdin);
	freopen ("friday.out", "w", stdout);
	int N, i;
	cin >> N;
	calculate(N);
	for(i=0; i<6; i++) {
		cout << result[i] << " ";
	}
	cout<<result[6]<<endl;
	return 0;
}