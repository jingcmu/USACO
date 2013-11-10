#include <iostream>
//#include <fstream>
//#include <algorithm>

using namespace std;

int n, k1, k2, T;
int a[10000];
long long K;

void keepGrow()
{
	int i;
	int a0 = a[0]; 
	for(i=0; i<n-1; i++)
	{
		a[i] = k1*a[i]+k2*a[i+1];
	}
	a[n-1] = k1*a[n-1]+k2*a0;
	return;
}

int getWeight()
{
	int i, w=0;
	for(i=0; i<n; i++)
	{
		w+=a[i];
	}
	return w;
}

int main() {
	//freopen("weiwei.in", "r", stdin);
  //  freopen("weiwei.out", "w", stdout); 
	int lastWeight, weight;
	int i, j, day;
	cin>>T; //²âÊÔÓÃÀıÊı
	for(i=0; i<T; i++)
	{
		lastWeight=-10000;
		cin>>n>>k1>>k2>>K; // Æ÷¹ÙÊı,k1,k2,K
		for(j=0; j<n; j++)
		{
			cin>>a[j];
		}
		day = 0;
		while(1)
		{
			weight = getWeight();
			if( weight <=lastWeight)
			{
				cout<<"Case #"<<i<<": "<<"inf"<<endl;
				break;
			}
			else
				lastWeight = weight;
			if(lastWeight>K)
			{
				cout<<"Case #"<<i<<": "<<day<<endl;
				break;
			}			
			keepGrow();	
			day++;
		}
	}
	return 0;
}

