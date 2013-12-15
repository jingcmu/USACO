/*
ID:wo__che1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int month_day[12] = {31,31,28,31,30,31,30,31,31,30,31,30};
int month_day_leap[12] = {31,31,29,31,30,31,30,31,31,30,31,30};
int result[7] = {0};

bool is_leapyear(int year) {
	return year%100 == 0? (year%400 == 0):(year%4 == 0);
}

void calculate(int year) {
	int *m;
	int day = 2; //ÐÇÆÚÈý
	for(int i=0; i<year; i++){
		m = is_leapyear(1900+i)? month_day_leap : month_day;
		for(int j=0; j<12; j++) {
			day = (day+m[j])%7;
			result[day]++;
		}
	}
}

int main() {
	freopen ("friday.in", "r", stdin);
	freopen ("friday.out", "w", stdout);
	int N, i, first_day;

	cin >> N;
	calculate(N);
	for(i=0; i<6; i++) {
		cout << result[(i+5)%7] << " ";
	}
	cout << result[(i+5)%7] << endl;
	return 0;
}