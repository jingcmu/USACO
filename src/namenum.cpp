/*
ID:wo__che1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define MAX_LENGTH 12
bool IS_NONE = 1;
char map[10][3] = 
{
		{' ', ' ', ' '}, 		// 0
		{' ', ' ', ' '}, 		// 1
		{'A', 'B', 'C'},	// 2
		{'D', 'E', 'F'},		// 3
		{'G', 'H', 'I'},		// 4
		{'J', 'K', 'L'},		// 5
		{'M', 'N', 'O'},	// 6
		{'P', 'R', 'S'},		// 7
		{'T', 'U', 'V'},	// 8
		{'W', 'X', 'Y'},	// 9
};

int search(string str, vector<string> dict_name)
{
	int i;
	for(i=0; i<dict_name.size(); i++)
	{
		if(!str.compare(dict_name[i]))
		{
			return 1;
		}
	}
	return 0;
}

void	check_name(string number, int *p_int, vector<string> dict_name, int length, int level, bool flag)
{
	int i, total = 0;
	string str;

	level++;
	if(level < length) 
	{
		for(i=0; i< 3; i++)
		{
			p_int[level] = i;
			check_name(number, p_int, dict_name, length, level, 1);
		}			
	}

	if(level == length)
	{
		for(i=0; i<length; i++)
			str += map[number[i]-'0'][p_int[i]];
	
		if(search(str, dict_name))
		{
			ofstream fout ("namenum.out", ios::app);
			fout << str << endl;
			IS_NONE = 0;
			fout.close();
		}
	}		
		
	return;
}


int main() {    
    ifstream fin ("namenum.in");
	ifstream fdict("dict.txt");
	int i, j, length;
	int *p_int;
	string name, number, name_candidate;
	vector<string> dict_name[13];
    while( fdict >> name )   			//creat name vector
  	{
  		dict_name[name.size()].push_back(name);
  	}
	fin >> number;
	length = number.size();
	p_int = new int[length];
	for(i=0; i<length; i++)
	{
		p_int[i] =0;
	}
	check_name(number, p_int, dict_name[length], length, -1, 0);
	if(IS_NONE)
	{
		ofstream fout ("namenum.out");
		fout << "NONE" << endl;
		fout.close();
	}
    return 0;
}
