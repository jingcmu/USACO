#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if(n==1||n==2) return 1;
	else 
		return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n;
    cin >> n;
    if(n<=0||n>=1000) 
			cout<<"input error, n should between 0~1000!"<<endl;

	cout<<"the number of rabbit in nth month is:"
		<<fibonacci(n)<<endl;
}