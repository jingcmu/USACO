/*
ID:wo__che1
PROG: ratios
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	int goal[3],mix[3][3],i,j,k,flag=0;
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");
	for(i=0;i<3;i++)
		fin>>goal[i];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			fin>>mix[i][j];
	}
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			for(k=0;k<100;k++)
			{
				int t0,t1=(i*mix[0][0]+j*mix[1][0]+k*mix[2][0])%goal[0];
				if(t1)
					continue;
				else
					t0=(i*mix[0][0]+j*mix[1][0]+k*mix[2][0])/goal[0];
				if((i*mix[0][1]+j*mix[1][1]+k*mix[2][1])!=goal[1]*t0)
					continue;
				if((i*mix[0][2]+j*mix[1][2]+k*mix[2][2])!=goal[2]*t0)
					continue;
				if(!i&&!j&&!k) continue;
				fout<<i<<" "<<j<<" "<<k<<" "<<t0<<endl;
				return 0;
			}
	if(!flag) fout<<"NONE"<<endl;
	return 0;
}
