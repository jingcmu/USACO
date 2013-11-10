/*
ID:wo__che1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class farmer
{
	public:
		farmer();
		void set_status();
		bool read_status();
		void read_time(int start, int end);
		int continue_to_milk(int someone_end);
		int get_start_time();
		int get_end_time();
	private:
		bool milked;
		int start_point;
		int end_point;
};

farmer::farmer()
{
	milked = 0;
	start_point = 0;
	end_point = 0;
}

void farmer::set_status()
{
	this->milked = true;
	return;
}

bool farmer::read_status()
{
	return this->milked;
}

void farmer::read_time(int start, int end)
{
	this->start_point = start;
	this->end_point = end;
	return;
}

int farmer::continue_to_milk(int someone_end)
{
	if(someone_end>=this->start_point && someone_end<=this->end_point)
		return this->end_point;
	else 
		return someone_end;
}

int farmer::get_start_time()
{
	return this->start_point;
}

int farmer::get_end_time()
{
	return this->end_point;
}

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	vector<farmer> l_farmer;
	static int start_calc, end_calc, old_end_calc, milk_continue, unmilk_continue;
	int N, i, j, index1, min_start_time = 1000000;
	fin >> N;
	for(i=0; i<N; i++)
	{
		int start, end;
		farmer *pf = new(farmer);
		fin >> start >> end;
		(*pf).read_time(start, end);
		l_farmer.push_back(*pf);
	}

	for(i=0; i<N; i++)
	{	
		int temp ; 
		temp = l_farmer[i].get_start_time();
		if(temp < min_start_time)
		{
			min_start_time  = temp;
			index1 = i;
		}			
	}
	
	start_calc = l_farmer[index1].get_start_time();
	old_end_calc = end_calc = l_farmer[index1].get_end_time();
	milk_continue = end_calc - start_calc;
	unmilk_continue = 0;
	l_farmer[index1].set_status();
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(!l_farmer[j].read_status())
			{
				end_calc = l_farmer[j].continue_to_milk(end_calc);
				if(end_calc != old_end_calc)
				{
					old_end_calc = end_calc;
					if(milk_continue < end_calc - start_calc)
						milk_continue = end_calc - start_calc;
					l_farmer[j].set_status();
					break;
				}
			}
		}
		if( j == N ) 
		{
			int index = -1;
			min_start_time = 1000000;
			start_calc = end_calc; 
			for(j=0; j<N; j++)
			{								
				if(!l_farmer[j].read_status())
				{
					int temp; 
					temp = l_farmer[j].get_start_time();
					if(temp >=start_calc
						&& temp < min_start_time)
					{
						min_start_time  = temp;
						index = j;
					}
				}				
			}
			if(index == -1) continue;   //对最后一次循环
			end_calc = l_farmer[index].get_start_time();
			l_farmer[index].set_status();
			if(unmilk_continue < end_calc - start_calc)
				unmilk_continue = end_calc - start_calc;
			start_calc = end_calc;
			old_end_calc = end_calc = l_farmer[index].get_end_time();
		}
	}
	fout << milk_continue << " " << unmilk_continue << endl;
	return 0;
}