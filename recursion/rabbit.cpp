#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class rabbit
{
	private:
		int age;
		bool alive;
	public:
		rabbit();
		bool isAlive();
		int grow();
};

rabbit::rabbit()
{
	this->age = 0;
	this->alive = true;
}

bool rabbit::isAlive()
{
	return this->alive;
}

int rabbit::grow()
{
	if(this->alive == false) return 0;
	this->age++;
	if(this->age == 12) 
	{
		this->alive = false;
		return 0;
	}
	else if(this->age>2 && this->age<=10)
		return 1;
	else return 0;
}

int main()
{
    int n, i, j, rabbit_num;
	vector<rabbit> v_rabbit;
    cin >> n;
    if(n<=0||n>100) 
			cout<<"input error, n should between 1~100!"<<endl;
	
	rabbit *r=new rabbit();
	v_rabbit.push_back(*r);
	for(i=1; i<=2*n; i++)
	{
		for(j=0; j<v_rabbit.size(); j++)
		{
			if(v_rabbit[j].grow())
			{
				rabbit *r_new = new rabbit();
				v_rabbit.push_back(*r_new);
			}
		}
	}
	rabbit_num = 0;
	for(i=0; i<v_rabbit.size(); i++)
	{
		if(v_rabbit[i].isAlive()) rabbit_num++;
	}
	cout <<"the number of rabbit at the end of " <<n <<"years is: " <<rabbit_num <<endl;
}