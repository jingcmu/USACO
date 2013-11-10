/*
ID:wo__che1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class giftor
{
	public:
		giftor();
		string get_name();
		int  get_account();		
		int get_money_flow();
		void read_name(string name);
		void  read_account(int account);
		void money_flow(int mf);
	private:
		string name;
		int account;
		int moneyflow;
};

giftor::giftor():account(0), moneyflow(0) {}

string giftor::get_name()
{
	return this->name;
}

int  giftor::get_account()
{
	return account;
}

void giftor::read_name(string name)
{
	this->name = name;
	return;
}

void  giftor::read_account(int account)
{
	this->account = account;
	return;
}

int  giftor::get_money_flow()
{
	return this->moneyflow;	
}

void  giftor::money_flow(int mf)
{
	this->moneyflow += mf;
	return;	
}

int main() {
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	int i, j, k, p, NP, NG;   
	string name;
	int account;
	giftor *g = new giftor();
	vector<giftor> v_giftor;
	fin >> NP;
	for(i=0; i<NP; i++)
	{
		fin >> name;
		(*g).read_name(name);
		v_giftor.push_back(*g);
	}	
	
	for(i=0; i<NP; i++)
	{
		fin >> name;
		for(j=0; j<NP; j++)
		{
			if(v_giftor[j].get_name() == name)
			{		
				int division = 0;
				fin >> account;
				v_giftor[j].read_account(account);				
				fin >> NG;
				if(NG!=0)
					division = v_giftor[j].get_account()/NG;
				v_giftor[j].money_flow(0-division*NG);
				for(k=0; k<NG; k++)
				{
					fin >> name;
					for(p=0; p<NP; p++)
					{
						if(v_giftor[p].get_name() == name)
						{
							v_giftor[p].money_flow(division);
							break;
						}
					}
				}
				break;
			}			
		}
	}
	for(i=0; i<NP; i++)
	{
		fout << v_giftor[i].get_name() << " " << v_giftor[i].get_money_flow() << endl;
	}
	return 0;
}