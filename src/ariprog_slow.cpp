/*
ID:wo__che1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
/*
void ariprog(long *bisquares, int length, int a)
{
	int i;
	long *bisquares_l = new long[length];
	for(i=0; i<length; i++)
	{
		bisquares_l[i] = bisquares[i]+4;
	}
	for(i=0; i<length; i++)
	{
		fout<<bisquares[i]<<" ";
		if((i+1)%10==0)
			fout<<endl;
	}
	fout<<endl;
	fout<<endl;
	for(i=0; i<length; i++)
	{
		fout<<bisquares_l[i]<<" ";
		if((i+1)%10==0)
			fout<<endl;
	}
}*/
/*
int in_sequence(long *bisquares, int *index, int number)
{
	int flag;
	int i, j;
	for(j=*index; ; j++)
	{
		if(bisquares[j]>number)
		{
			flag = 0;
			break;
		}
		else if(bisquares[j]==number)
		{
			flag = 1;
			*index = j;
			break;
		}
	}
	return flag;
}*/

int search_ariprog(long *bisquares, int index, int diff, int a)
{
	int i, j, flag;
	int index_l = index, bisq;
	for(i=1; i<a; i++)
	{
		bisq = bisquares[index]+i*diff;
		for(j=index_l; ; j++)
		{
			if(bisquares[j]>bisq)
			{
				flag = 0;
				goto FLAG;
			}
			else if(bisquares[j]==bisq)
			{
				flag = 1;
				index_l = j;
				break;
			}
		}
		//flag = in_sequence(bisquares, &index_l, bisquares[index]+i*diff);
FLAG:		
		if(!flag)
			break;
	}
	return flag;
}

int ariprog(long *bisquares, int length, int a, ofstream &fout)
{
	int i, j, flag, none = 1;
	int diff, diff_max, step;
	if(a>4) 
	{
		step = 4;
		diff = 4;
	}
	else
	{
		step = 1;
		diff = 1;
	}
	diff_max = bisquares[length-1]/(a-1);
	for(; diff<=diff_max; diff+=step)
	{
		for(i=0; bisquares[i]<=bisquares[length-1] -(a-1)*diff; i++)
		{
			flag = search_ariprog(bisquares, i, diff, a);
			if(flag)
			{
				fout<<bisquares[i]<<" ";
				fout<<diff<<endl;
				none = 0;
			}
		}
	}
	return none;
}

int main() 
{  
	ofstream fout("ariprog.out");
    ifstream fin("ariprog.in");
    int a, b, i;
	int p, q, none;
	long *bisquares_temp, *bisquares, length_temp, length;
	fin>>a>>b;
	if(a<3||a>25||b<1||b>250)
	{
		fout<<"error input!"<<endl;
	}
	length = length_temp = 0;
	bisquares_temp = new long[(b+1)*(b+1)];
	bisquares = new long[(b+1)*(b+1)];
	for(p=0; p<=b; p++)
		for(q=p; q<=b; q++)
		{
			bisquares_temp[length_temp++] = q*q + p*p;
		}
	sort(bisquares_temp, &bisquares_temp[length_temp-1]);
	bisquares[0] = bisquares_temp[0];
	length++;
	for(i=1; i<length_temp; i++)
	{
		if(bisquares_temp[i]!=bisquares_temp[i-1])
		{
			bisquares[length++] = bisquares_temp[i];
		}
	}
	
	/*
	for(i=1; i<=length; i++)
	{
		fout<<bisquares[i-1]<<" ";
		if(i%10==0)
			fout<<endl;
	}*/

	none = ariprog(bisquares, length, a, fout);
	if(none) 
		fout<<"NONE"<<endl;
    return 0;
}
