/*
ID:wo__che1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
#define MONTH_NUM 12

enum year_month
{
	JAN = 31,
  	FEB = 28, 
  	Leap_FEB = 29, 
  	MAR = 31,
  	APR = 30,
  	MAY = 31,
  	JUNE =30,
  	JULY = 31,
  	AUG = 31,
  	SEP = 30,
  	OCT = 31,
  	NOV = 30,
  	DEC = 31
};

class YEAR
{
	public:
		YEAR();
		short read_day13_belong(short n);
		short get_day13_belong(short weekday);  //return frist weekday of next year
		void leap_year_judgement(int year);
	private:
		bool is_leap_year;
		short day13_belong[7];
		short day13_belong_index;
};

YEAR::YEAR()
{
	int i;
	for(i=0; i<7; i++)
	{
		day13_belong[i] = 0;
	}
}

short YEAR::read_day13_belong(short n)
{
	if(n>=0&&n<7)
		return day13_belong[n];
	else
		return 0;
}

void YEAR::leap_year_judgement(int year)
{
	if(year%100 == 0)
	{
		this->is_leap_year = (year%400 == 0);
		return;
	}
	else
	{
		this->is_leap_year = (year%4 == 0);
		return;
	}
}

short YEAR::get_day13_belong(short weekday)
{
	int i;
	short day13_belong_t;
	for(i=0; i<MONTH_NUM; i++)
	{
		switch(i)
		{
			case 0:
				day13_belong_index = (weekday+12)%7;
				break;
			case 1:				
				day13_belong_index = (day13_belong_index+JAN)%7;
				break;
			case 2:
				if(this->is_leap_year)
				{
					day13_belong_index = (day13_belong_index+Leap_FEB)%7;
				}
				else
				{
					day13_belong_index = (day13_belong_index+FEB)%7;
				}
				break;
			case 3:
				day13_belong_index = (day13_belong_index+MAR)%7;
				break;
			case 4:
				day13_belong_index = (day13_belong_index+APR)%7;
				break;
			case 5:
				day13_belong_index = (day13_belong_index+MAY)%7;
				break;
			case 6:
				day13_belong_index = (day13_belong_index+JUNE)%7;
				break;
			case 7:
				day13_belong_index = (day13_belong_index+JULY)%7;
				break;
			case 8:
				day13_belong_index = (day13_belong_index+AUG)%7;
				break;
			case 9:
				day13_belong_index = (day13_belong_index+SEP)%7;
				break;
			case 10:
				day13_belong_index = (day13_belong_index+OCT)%7;
				break;
			case 11:
				day13_belong_index = (day13_belong_index+NOV)%7;
				break;		
		}
		day13_belong[day13_belong_index]++;
	}

	return (day13_belong_index+31-13+1)%7;
}

int main()
{
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
	int N, i, j, first_day;
	int statistic_result[7] = {0};

	fin >> N;
	first_day = 0; //monday
	for(i=0; i<N; i++)
	{
		YEAR *y = new(YEAR);
		(*y).leap_year_judgement(1900+i);
		first_day = (*y).get_day13_belong(first_day);
		for(j=0; j<7; j++)
		{
			statistic_result[j] += (*y).read_day13_belong(j);
		}
		delete(y);
	}
	for(j=0; j<6; j++)
	{
		fout << statistic_result[(j+5)%7] << " ";
	}
	fout << statistic_result[(j+5)%7] << endl;
	return 0;
}