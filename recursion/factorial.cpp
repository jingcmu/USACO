#include <iostream>
using namespace std;

long factorial(int n)
{
	if(n==1) return 1;
	else 
		return factorial(n-1)*n;
}

int main()
{
    int n;
    cin >> n;
    if(n<=0||n>=50) 
			cout<<"input error, n should between 0~50!"<<endl;

	cout<<"n's factorial is:"
		<<factorial(n)<<endl;
}