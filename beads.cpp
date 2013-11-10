/*
ID:wo__che1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	string S1;
	int N, a, b, c, flag1, flag2, i, ft;

	a=b=c=flag1=flag2=0;
	
	fin >> N;
	fin >> S1;
	S1= S1+S1;

	for(i=0; i<N*2; i++)
	{
		if(S1[i] == 'b') ft = 1;
		else if(S1[i] == 'r') ft = 2;
		else ft = 0;

		if(ft == 0)   //read a 'w'
		{
			if(flag2 == 0)    //a's turn
				a++;
			else			//b's turn
				b++;
		}
		else
		{
			if(ft == 1)  //read a 'b'
			{
				if(flag1 == 1)
				{
					if(flag2 == 0)    //a's turn
						a++;
					else			//b's turn
						b++;
				}
				else if(flag1 == 2)
				{
					int j = i;
					if(c<a+b) 
						c = a+b;
					flag1 = ft;
					flag2 = (flag2 + 1)%2;
					if(flag2 == 0)    //a's turn
					{							
						a = 1;
						while(S1[--j] == 'w')
						{
							a++;
							b--;
						}
					}
					else			//b's turn
					{
						b = 1;
						while(S1[--j] == 'w')
						{
							b++;
							a--;
						}
					}
				}
				else
				{
					flag1 = ft;
					if(flag2 == 0)    //a's turn
						a++;
					else			//b's turn
						b++;
				}
			}
			else           //read a 'r'
			{
				if(flag1 == 2)
				{
					if(flag2 == 0)    //a's turn
						a++;
					else			//b's turn
						b++;
				}
				else if(flag1 == 1)
				{
					int j = i;
					if(c<a+b) 
						c = a+b;
					flag1 = ft;
					flag2 = (flag2 + 1)%2;
					if(flag2 == 0)    //a's turn
					{	
						a = 1;
						while(S1[--j] == 'w')
						{
							a++;
							b--;
						}
					}
					else			//b's turn
					{
						b = 1;
						while(S1[--j] == 'w')
						{
							b++;
							a--;
						}
					}
				}
				else
				{
					flag1 = ft;
					if(flag2 == 0)    //a's turn
						a++;
					else			//b's turn
						b++;
				}
			}
		}					
	}
	if(c==0||c>N)
		c = N;
	fout << c <<endl;
	return 0;
}