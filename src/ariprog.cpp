/*
ID:wo__che1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> can(250*250*2, false);
int bisquares[250*250*2];
struct out_s {
	int start;
	int diff;
	bool operator < (const struct out_s &a) const {return diff < a.diff; }
} out[1000];

int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	int a, b, a_minus1;
	int i, j, k, flag, num=0, sum=0;
	int diff, max_index;
	vector<out_s> v;
	cin >> a >> b;
	a_minus1 = a-1;
	max_index = b*b*2;
	for(i=0; i<=b; i++)
		for(j=i; j<=b; j++)
			can[i*i+j*j] = true;
		
	for(i=0; i<=max_index; i++)
	{
		if(can[i]) bisquares[num++] = i;
	}
	for(i=0; i<num-a_minus1; i++)
	{
		for(j=i+1; j<num; j++)
		{
			flag = 1;
			diff = bisquares[j]-bisquares[i];
			if(i+diff*a_minus1 > max_index)
				break;
			for(k=1; k <= a_minus1; k++) {
				if(!can[bisquares[i]+diff*k]) {
					flag = 0; //是否you连续的a个元素
					break;
				}
			}
			if(flag) {  //如果找到了连续的数列则记录下来
				out_s o;
				o.start = bisquares[i];
				o.diff = diff;
				v.push_back(o);
			}
		}
	}
	if(v.empty()) {  //如果没有找到连续数列
		cout<<"NONE"<<endl;
		return 0;
	}
	sort(v.begin(), v.end());
	for(i=0; i<(int)v.size(); i++) {
		cout <<v[i].start<<" "<<v[i].diff<<endl;
	}
	return 0;
}