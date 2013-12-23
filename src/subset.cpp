/*
ID:wo__che1
PROG: subset
LANG: C++
*/
/*
动态规划 设分成的子集为set1,set2,sum=(n*(n+1)div 2)div 2. 设f[i,j]表示取前i个数，使set1总数和为j的方案数.第i个数的值为i
{其实就是01背包求方案数} 分析为什么它是0\1背包：将一个集合划分成 两个“元素总和相等”的集合，设原集合的元素总和为sum，则划分后的集合的元素综合都为sum/2。那么我们可以把sum/2看成背包的容量，原集合中的数字看为物品的重量及价值（这里价值维度可以淡化，就像装箱问题）。则原问题转化为 “从原集合中选出n个物品，使这n个物品恰好放满容量为sum/2的背包的方案总数”。
*/
#include <fstream>
#include <iostream>
using namespace std;

unsigned int num[40][391];
int count(int n, int sum)
{
	int i, j;
	num[1][1] = 1;
	num[1][0] = 1;
	
	for(i=2; i<=n; i++)
		for(j=0; j<=sum; j++) {
			if(j-i>=0)
				num[i][j] = num[i-1][j] + num[i-1][j-i]; //不选i + 选i的方案数
			else
				num[i][j] = num[i-1][j];
		}
		
	return num[n][sum]/2;
}

int main() {
	int N, i;
	freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
	cin>>N;   //freopen("CON", "w", stdout);
	//如果和不是偶数，则不存在这样的划分
	if(N*(N+1)%4) {
		cout << "0" << endl;
	    return 0;
	}
	
	cout<<count(N, N*(N+1)/4)<<endl;
}
