/*
ID:wo__che1
PROG: pprime
LANG: C++
*/
#include <math.h>
#include <iostream>
#include <fstream>


using namespace std;

int num = 0;

bool is_prime(int x)
{
	int i;
	int sq = sqrt((float)x);
	for(i=2; i<=sq; i++)
	{
		if(x%i==0) return false;
	}
	return true;
}

void set_dmax(int len, int dmax[])
{
	switch(len)
	{
	case 1:
	case 2:
		dmax[2] = 0;
		dmax[3] = 0;
		dmax[4] = 0;
		dmax[5] = 0;
		break;
	case 3:
	case 4:
		dmax[2] = 9;
		dmax[3] = 0;
		dmax[4] = 0;
		dmax[5] = 0;
		break;
	case 5:
	case 6:
		dmax[2] = 9;
		dmax[3] = 9;
		dmax[4] = 0;
		dmax[5] = 0;
		break;
	case 7:
	case 8:
		dmax[2] = 9;
		dmax[3] = 9;
		dmax[4] = 9;
		dmax[5] = 0;
		break;
	case 9:
		dmax[2] = 9;
		dmax[3] = 9;
		dmax[4] = 9;
		dmax[5] = 9;
	default:
		break;
	}
	return;
}

void get_side_p(int len, int max1, int d[], int pow[], int out[], int condition1, int condition2, int dmax[])
{
	int palindrome;
	int i;
	if(max1%2==0) return;

	set_dmax(len, dmax);
	
	if(len==1)
		palindrome = max1;
	else
		palindrome = max1*(pow[1]+pow[len]);
	if(len>2)
	{
		d[1] = max1;
		for(d[2]=0; d[2]<=dmax[2]; d[2]++)
			for(d[3]=0; d[3]<=dmax[3]; d[3]++)
				for(d[4]=0; d[4]<=dmax[4]; d[4]++)
					for(d[5]=0; d[5]<=dmax[5]; d[5]++)
					{
						switch(len)
						{
						case 3:
							palindrome = d[1]*(pow[1]+pow[3])+d[2]*pow[2];
							break;
						case 4:
							palindrome = d[1]*(pow[1]+pow[4])+d[2]*(pow[2]+pow[3]);
							break;
						case 5:
							palindrome = d[1]*(pow[1]+pow[5])+d[2]*(pow[2]+pow[4])+d[3]*pow[3];
							break;
						case 6:
							palindrome = d[1]*(pow[1]+pow[6])+d[2]*(pow[2]+pow[5])+d[3]*(pow[3]+pow[4]);
							break;
						case 7:
							palindrome = d[1]*(pow[1]+pow[7])+d[2]*(pow[2]+pow[6])+d[3]*(pow[3]+pow[5])+d[4]*pow[4];
							break;
						case 8:
							palindrome = d[1]*(pow[1]+pow[8])+d[2]*(pow[2]+pow[7])+d[3]*(pow[3]+pow[6])+d[4]*(pow[4]+pow[5]);
							break;
						case 9:
							palindrome = d[1]*(pow[1]+pow[9])+d[2]*(pow[2]+pow[8])+d[3]*(pow[3]+pow[7])+d[4]*(pow[4]+pow[6])+d[5]*pow[5];
							break;
						}
					
						if((palindrome>=condition1)&&(palindrome<=condition2)&&is_prime(palindrome))
						{
							out[num++] = palindrome;
						}
						}
					}
	
					else
					{
						if((palindrome>=condition1)&&(palindrome<=condition2)&&is_prime(palindrome))
						{
							out[num++] = palindrome;
						}
					}
					return;
}

void get_palindrome(int len, int dmin1,int dmax1, int d[], int pow[], int out[], int dmax[])
{
	int palindrome;
	
	set_dmax(len, dmax);
	
	for(d[1]=dmin1; d[1]<dmax1; d[1]+=2)
		for(d[2]=0; d[2]<=dmax[2]; d[2]++)
			for(d[3]=0; d[3]<=dmax[3]; d[3]++)
				for(d[4]=0; d[4]<=dmax[4]; d[4]++)
					for(d[5]=0; d[5]<=dmax[5]; d[5]++)
					{
						switch(len)
						{
						case 1:
							palindrome = d[1];
							break;
						case 2:
							palindrome = d[1]*pow[1]+d[1]*pow[2];
							break;
						case 3:
							palindrome = d[1]*(pow[1]+pow[3])+d[2]*pow[2];
							break;
						case 4:
							palindrome = d[1]*(pow[1]+pow[4])+d[2]*(pow[2]+pow[3]);
							break;
						case 5:
							palindrome = d[1]*(pow[1]+pow[5])+d[2]*(pow[2]+pow[4])+d[3]*pow[3];
							break;
						case 6:
							palindrome = d[1]*(pow[1]+pow[6])+d[2]*(pow[2]+pow[5])+d[3]*(pow[3]+pow[4]);
							break;
						case 7:
							palindrome = d[1]*(pow[1]+pow[7])+d[2]*(pow[2]+pow[6])+d[3]*(pow[3]+pow[5])+d[4]*pow[4];
							break;
						case 8:
							palindrome = d[1]*(pow[1]+pow[8])+d[2]*(pow[2]+pow[7])+d[3]*(pow[3]+pow[6])+d[4]*(pow[4]+pow[5]);
							break;
						case 9:
							palindrome = d[1]*(pow[1]+pow[9])+d[2]*(pow[2]+pow[8])+d[3]*(pow[3]+pow[7])+d[4]*(pow[4]+pow[6])+d[5]*pow[5];
							break;
						}
						if(is_prime(palindrome))
						{
							out[num++] = palindrome;
						}
					}
	return;
}

int main() {
    ofstream fout("pprime.out");
    ifstream fin("pprime.in");
	int a, b, c;
	int amax1, bmax1, len_a, len_b, palindrome=0, pow[10], pow_l=1; //d1-最高位  len-位数
	int d[10]={0}, time=1, out[1000], dmax[6];
	int i, j;
	fin >>a>>b;
	amax1 = c = a;
	len_a = 1;
	for(i=1; c/=10; i++) 
	{
		len_a++;
		amax1/=10;
	}
	
	bmax1 = c = b;
	len_b = 1;
	for(i=1; c/=10; i++) 
	{
		len_b++;
		bmax1/=10;
		pow[i] = pow_l;
		pow_l*=10;
	}
	pow[0] = 0;
	pow[i] = pow_l;
	for(j=i+1; j<=9; j++)
		pow[j] = 0;

	get_side_p(len_a, amax1, d, pow, out, a, b, dmax); //len = len_a, 最高位取最小

	if(len_a==len_b)
	{
		for(i=1; i<=bmax1-amax1; i++)
			get_side_p(len_a, amax1+i, d, pow, out, a, b, dmax); //len = len_a, 最高位取最小
	}
	
	if(len_a!=len_b)
	{
		get_palindrome(len_a, (amax1+1)/2*2+1, 10, d, pow, out, dmax);
		
		for(i=len_a+1; i<len_b; i++)
			get_palindrome(i, 1, 10, d, pow, out, dmax);

		get_palindrome(len_b, 1, bmax1, d, pow, out, dmax);

		get_side_p(len_b, bmax1, d, pow, out, a, b, dmax);
	}
	
	for(i=0; i<num; i++)
	{
		fout<<out[i]<<endl;
	}
    return 0;
}
