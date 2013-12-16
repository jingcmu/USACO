/*
ID:wo__che1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
ifstream fin("namenum.in");
ifstream dict("dict.txt");
ofstream fout("namenum.out");
 
int main(){
	vector<long long> dci;
	vector<string> dc;
	string name;

	while(dict>>name){
		dc.push_back(name);
	}
	dci.resize(dc.size());
	for(int i=0; i < dc.size(); i++) {
		for(int j=0; j < dc[i].size(); j++){
			dci[i] = dci[i]*10+2+(int(dc[i][j]-'A')+(dc[i][j]<'Q'?0:-1))/3;
		}
	}
	long long result;
	fin>>result; 
	bool flag = false;
	for(int i=0 ;i < dc.size();i++) {
	    if(result == dci[i]) {
	        fout << dc[i] << endl;
	        flag = true;
	    }
	}
	if(!flag) fout<<"NONE"<<endl;
	fin.close();
	fout.close();
    return 0;
}