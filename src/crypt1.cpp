/*
ID:wo__che1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int judge(int *digital, int number, int n)
{
	int i, flag = 0;
	int a, b, c, d;
	if(n>999)
	{
		d = n/1000;
		n%=1000;
		for(i=0; i<number; i++)
		{
			if(d == digital[i]) flag = 1;
		}
		if(!flag) 
		{
			return flag;
		}
	}
	
	a = n/100;
	n%=100;
	b = n/10;
	c = n%10;
	flag = 0;
	for(i=0; i<number; i++)
	{
		if(a == digital[i]) flag = 1;
	}
	if(!flag) 
	{
		return flag;
	}
	flag = 0;
	for(i=0; i<number; i++)
	{
		if(b == digital[i]) flag = 1;
	}
	if(!flag) 
	{
		return flag;
	}
	flag = 0;
	for(i=0; i<number; i++)
	{
		if(c == digital[i]) flag = 1;
	}
	return flag;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int number, i, j, k, p, q;
	int *digital;
	int a, b, c, d, e, max_c, max_d, max_e, num=0;
	fin >> number;
	digital = (int *)malloc(number*sizeof(int));
	for(i=0; i<number; i++)
    {
    	fin >> digital[i];
	}
	sort(digital, digital+number);
	
	max_d = max_c = (digital[number-1]*100) +(digital[number-1]*10) + digital[number-1];
		
	max_e = (digital[number-1]*1000) + (digital[number-1]*100)
		       	+(digital[number-1]*10) + digital[number-1];

	for(i=0; i<number; i++)
	for(j=0; j<number; j++)
	for(k=0; k<number; k++)
	for(p=0; p<number; p++)
	for(q=0; q<number; q++)
	{
		a = digital[i]*100 + digital[j]*10 + digital[k];
		b = digital[p]*10 + digital[q];
		c = digital[q]*a;
		d = digital[p]*a;
		e = a*b;
		if((e>max_e)||(c>max_c)||digital[p]*a>max_d)
		{
			continue;
		}
		if(judge(digital, number, c)&&judge(digital, number, d)&&judge(digital, number, e))
		{
			num++;
			//fout << "c = " << c << endl;
			//fout << "d = " << d << endl;
			//fout << "e = " << e << endl;
		}
	}
	
	fout << num << endl;
	
    return 0;
}