/*
ID:wo__che1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
using namespace std;

#define CLEAR 57521883
const long moveTable[9] = //
{18911232, 19136512, 2363904, 16810048, 2134536, 262657, 36936, 73, 4617};

map<int, int> m;
long move(queue<int> &q_time){
	while£¨!q_time.empty()) {
		int time = q_time.front();
		for(int i=0; i<9; i++) {
			int time_tmp = (time+moveTable[i])&CLEAR;
			q_time.push(time_tmp);
		}
	}
}

int main() 
{  
	freopen("clocks.out", "w", stdout);
    freopen("clocks.in", "r", stdin);
    int init_time = 56697994;
	queue<int> q_time;
	q_time.push(init_time);
	
    return 0;
}

