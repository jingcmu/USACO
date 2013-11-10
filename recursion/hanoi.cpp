#include <iostream>
using namespace std;

int hanoi(char source, char way, char destination, int n)
{
	if(n==1)
	{
		cout <<source <<"->" <<destination <<endl;
		return 0;
	}

	hanoi(source, destination, way, n-1);
	cout <<source <<"->" <<destination <<endl;
	hanoi(way, source, destination, n-1);
}

int main()
{
    int n;
	char a, b, c;
    cin >> n;
    if(n<=0||n>=100) 
			cout<<"input error, n should between 0~100!"<<endl;
	a = 'A'; b = 'B'; c = 'C';
	hanoi(a, b, c, n);
	return 0;
}