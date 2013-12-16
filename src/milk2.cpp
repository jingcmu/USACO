/*
ID:wo__che1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

struct farmer{
	int start;
	int end;
	bool operator < (const farmer &f) const{ return start < f.start; }
};

int main(){
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	int N, i, max_time = 0, max_interval = 0;
	set<farmer> s;
	cin >> N;
	for(i=0; i<N; i++){
		farmer f;
		cin >> f.start >> f.end;
		s.insert(f);
	}
	i = 0;
	farmer last;
	for(set<farmer>::iterator it = s.begin(); it != s.end(); it++, i++){
		if(i == 0){
			last.start = (*it).start;
			last.end = (*it).end;
			max_time = last.end - last.start;
			continue;
		}
		if((*it).start <= last.end){
			last.start = min((*it).start, last.start);
			last.end = max((*it).end, last.end);
			max_time = max(max_time, last.end - last.start);
		}
		else {
			max_time = max(max_time, (*it).end - (*it).start);
			max_interval = max(max_interval, (*it).start - last.end);
			last.start = (*it).start;
			last.end = (*it).end;
		}
	}
	cout << max_time << " " << max_interval << endl;
	return 0;
}