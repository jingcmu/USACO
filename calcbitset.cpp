#include <iostream>
using namespace std;

int iterNum;

int method1(int v)
{ 
	int c;
	for (c = 0; v; v >>= 1)
	{
		c += v & 1;
		iterNum++;
	}
	return c;
}

int method2(int v)
{
	static const unsigned char BitsSetTable256[256] = 
	{
		#define B2(n) n,     n+1,     n+1,     n+2
		#define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
		#define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)    
		B6(0), B6(1), B6(1), B6(2)
	};
	int c;
	// Option 1:
#if 0
	c = BitsSetTable256[v & 0xff] +     
	BitsSetTable256[(v >> 8) & 0xff] +     
	BitsSetTable256[(v >> 16) & 0xff] +     
	BitsSetTable256[v >> 24]; 
#else
	// Option 2:
	unsigned char * p = (unsigned char *) &v;
	c = BitsSetTable256[p[0]] +     
		BitsSetTable256[p[1]] +     
		BitsSetTable256[p[2]] +         
		BitsSetTable256[p[3]];
#endif
	return c;
}

int method3(int v)
{
	int c;
	for (c = 0; v; c++)
	{  
		v &= v - 1; // clear the least significant bit set
	}
	return c;
}

int main()
{
	int v, c;
	int i;
	cin>>v;

	c = method2(v);
	/*
	for(i=1; i<=256; i++)
	{
		cout<<(int)BitsSetTable256[i-1]<<" ";
		if(i%16==0) cout<<endl;
	}*/

	//cout<<"bits="<<c<<endl;
	
	return 0;
}
