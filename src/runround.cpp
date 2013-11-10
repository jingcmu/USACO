/*
ID:wo__che1
PROG: runround
LANG: C++
*/
#include <fstream>
#include <iostream>

using namespace std;

int N_char[9];
bool digital[10], digital1[10];
	
bool is_rr(int n)
{
	int len = 0, i;
	int n_tmp = n;
	for(i=0; i<10; i++)
	{
		digital[i] = false;
	}
	while(n_tmp)
	{
		int dig_tmp;
		dig_tmp = n_tmp%10;
		if(digital[dig_tmp]||!dig_tmp) 
			return false; //重复了、或者dig_tmp为0
		digital[dig_tmp] = true;
		N_char[len++] = dig_tmp;
		n_tmp/=10;
	}
	for(i=0; i<10; i++)
	{
		digital1[i] = false;
	}
	for(i=0; i<len/2; i++) //reverse the array
	{
		char tmp;
		tmp = N_char[i];
		N_char[i] = N_char[len-i-1];
		N_char[len-i-1] = tmp;
	}
	int cur = 0;
	digital1[N_char[cur]] = true;
	for(i=1; i<len; i++)
	{
		cur = (cur+N_char[cur])%len;
		if(digital1[N_char[cur]]) return false;
		else
			digital1[N_char[cur]] = true;
	}
	cur = (cur+N_char[cur])%len;
	if(!cur)
		return true;  //finally come back to first number
	else 
		return false;
}

int main() {
	int i;
	unsigned int N;
	freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
	cin>>N;   //freopen("CON", "w", stdout);

	while(!is_rr(++N))
	{
		;
	}
	cout<<N<<endl;
	return 0;
}
