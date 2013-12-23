/*
ID:wo__che1
PROG: preface
LANG: C++
*/
#include <fstream>
#include <iostream>
using namespace std;
//num存 I V X L C D M 的个数
int num[7];
//table1存个位数上IVX的个数
int table1[10] = 
{0x0, 0x1, 0x2, 0x3, 0x11, 0x10, 0x11, 0x12, 0x13, 0x101};// 1-I 2-II 3-III 4-IV 5-V 6-VI 7-VII 8-VIII 9-IX  
//table2存十位数上XLC的个数
int table2[10] = 
{0x0, 0x100, 0x200, 0x300, 0x1100, 0x1000, 0x1100, 0x1200, 0x1300, 0x10100};
//10-X 20-XX 30-XXX 40-XL 50-L 60-LX 70-LXX 80-LXXX 90-XC
//table3存百位数上CDM的个数
int table3[10] = 
{0x0, 0x10000, 0x20000, 0x30000, 0x110000, 0x100000, 0x110000, 0x120000, 0x130000, 0x1010000};
//100-C 200-CC 300-CCC 400-CD 500-D 600-DC 700-DCC 800-DCCC 900-CM
//table4存千位数上M的个数
int table4[4] =
{0x0, 0x1000000, 0x2000000, 0x3000000};
//1000-M 2000-MM 3000-MMM

void add_num(int i)
{
	int temp, j;
	//分解并查表得到罗马字符的个数
	temp = table1[i%10]+table2[(i/10)%10]+table3[(i/100)%10]+table4[i/1000];
	for(j=0; j<7; j++)
	{
		num[j] += temp&0xf;
		temp>>=4;
	}
}

int main() {
	int N, i;
	freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
	cin>>N;   //freopen("CON", "w", stdout);
	for(i=1; i<=N; i++)
		add_num(i);
	if(num[0]) cout<<"I "<<num[0]<<endl;
	if(num[1]) cout<<"V "<<num[1]<<endl;
	if(num[2]) cout<<"X "<<num[2]<<endl;
	if(num[3]) cout<<"L "<<num[3]<<endl;
	if(num[4]) cout<<"C "<<num[4]<<endl;
	if(num[5]) cout<<"D "<<num[5]<<endl;
	if(num[6]) cout<<"M "<<num[6]<<endl;
    return 0;
}
