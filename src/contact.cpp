/*
ID:wo__che1
PROG: contact
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int result[13][4096];
int output[1000][3];  //number,length,value

int CLEAN[13]={
		0,0,1,3,7,15,31,63,127,255,511,1023,2047
};

void swap(int output[][3],int i,int j)
{
	int temp;
	temp=output[i][0];
	output[i][0]=output[j][0];
	output[j][0]=temp;
	temp=output[i][1];
	output[i][1]=output[j][1];
	output[j][1]=temp;
	temp=output[i][2];
	output[i][2]=output[j][2];
	output[j][2]=temp;
}

void sort(int output[][3],int n)
{
	//ц╟ещ
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			if(output[i][0]<output[j][0]
			  ||(output[i][0]==output[j][0]&&output[i][1]>output[j][1])
			  ||(output[i][0]==output[j][0]&&output[i][1]==output[j][1]&&output[i][2]>output[j][2])){
				swap(output,i,j);
			}
		}
}

void itoa(int a, char c[])
{
	char ct[20];
	int i,j;
	for(i=0;a>0;i++)
	{
		ct[i]=a%2?'1':'0';
		a>>=1;
	}
	for(j=0;j<i;j++)
	{
		c[j]=ct[i-j-1];
	}
	c[j]='\0';
}

int main(){
	int A, B, N;
	int i, j, k;
	char c;
	int c_int[13],c_int_t=0;
	ifstream fin("contact.in");
	ofstream fout("contact.out");
	fin>>A>>B>>N;
	for(i=0;i<13;i++)
		c_int[i]=0;
	for(i=1;i<A;i++)
	{
		fin>>c;
		c_int_t=(c_int_t<<1)+(c=='1');
	}
	if(A==1)
	{
		c_int_t=(c=='1');
	}
	c_int[A-1]=c_int_t;
	for(i=A,j=0;i<=B;i++,j++){
		if(!(fin>>c)) break;
		c_int[i]=(c_int[i-1]<<1)+(c=='1');
		result[i][c_int[i]]++;
		for(k=0;k<j;k++)
		{
			c_int[A+k]=((c_int[A+k]&CLEAN[A+k])<<1)+(c=='1');
			result[A+k][c_int[A+k]]++;
		}
	}

	while(fin>>c)
	{
		for(i=A,j=0;i<=B;i++,j++)
		{
			c_int[i]=((c_int[i]&CLEAN[i])<<1)+(c=='1');
			result[i][c_int[i]]++;
		}
	}

	int n=0;
	for(i=1;i<=12;i++)
			for(j=0;j<4096;j++){
				if(result[i][j]){
					output[n][0] = result[i][j];
					output[n][1] = i;
					output[n++][2] = j;
				}
			}
	sort(output,n);
	int len=0, NN=0, flag=1, num;
	for(i=0;i<n;i++)
	{
		char c[12];
		itoa(output[i][2],c);
		for(j=0;j<12;j++)
		{
			if(c[j]=='\0')
				break;
		}

		if(len!=output[i][0])
		{
			num=0;
			NN++;
			if(NN>N) break;
			if(!flag) fout<<endl;
			flag=0;
			fout<<output[i][0]<<endl;
			len=output[i][0];
			for(k=0;k<output[i][1]-j;k++)
				fout<<'0';
			fout<<c;
			num++;
		}
		else
		{
			if(num==6)
			{
				num=0;
				fout<<endl;
			}
			else
				fout<<" ";
			for(k=0;k<output[i][1]-j;k++)
				fout<<'0';
			fout<<c;
			num++;
		}
	}
	fout<<endl;
	return 0;
}
