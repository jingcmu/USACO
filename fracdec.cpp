/*
ID:wo__che1
PROG: fracdec
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int remainder[100000];
char out[1000000];
int len=1;

int main() 
{   
	int i, flag=0, cycle_start=0;
	int N, D, r;
	int print_len;
	freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>N>>D;
	if(N%D == 0)
		cout<<N/D<<".0";
	else
	{
		cout<<N/D<<".";
		if(N/D<10) print_len = 2;
		else if(N/D<100) print_len = 3;
		else if(N/D<1000) print_len = 4;
		else if(N/D<10000) print_len = 5;
		else if(N/D<100000) print_len = 6;
		remainder[N%D] = 100000;
		N = (N%D)*10;
		while(N%D)
		{
			if(remainder[N%D])
			{
				cycle_start = remainder[N%D];
				break;
			}
			remainder[N%D] = len;
			out[len++] = N/D;	
			N = (N%D)*10;
		}
		if(N%D == 0)
			out[len++] = N/D;
		else
		{
			flag = 1;
			out[len++] = N/D;
		}
	}
	if(cycle_start==100000)
	{
		cout<<"(";
		cycle_start = 0;
		print_len++;
	}
	for(i=1; i<len; i++)
	{
		if(!flag)
			cout<<(int)out[i];
		else
		{
			if(i==cycle_start)
			{
				cout<<(int)out[i]<<"(";
				print_len++;
			}
			else
				cout<<(int)out[i];
		}
		if((i+print_len)%76==0) cout<<endl;
	}
	if(flag)
		cout<<")"<<endl;
	else
		cout<<endl;
	return 0;
}
