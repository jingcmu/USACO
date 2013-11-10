/*
ID:wo__che1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string s1, s2;
    long long group_num = 1;
    long long comet_num = 1;
    short group_mod;
    short comet_mod;
    int i;    
    fin >> s1 >> s2;
    for(i=0; i<s1.size(); i++)
    {
	  group_num *= (s1[i]-64);
    }
    group_mod = group_num % 47;
    for(i=0; i<s2.size(); i++)
    {
	  comet_num *= (s2[i]-64);
    }    
    comet_mod = comet_num % 47;
    if(comet_mod == group_mod)
        fout << "GO" <<endl;
    else
        fout << "STAY" <<endl;
    return 0;
}