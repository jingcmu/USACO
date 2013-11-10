/*
ID:wo__che1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
char str_i[10], str_square[100];

int convert(int Num, int base, char str[])
{
	int i = 0, residue;
	do
	{
		residue = (Num%base);
		i++;
		if(residue<10)
		{
			str[i] = residue+48;
		}
		else
		{
			str[i] = residue+55;
		}
		Num -= residue;
		Num /= base;
	}while(Num!=0);
	
	return i;
}

void reverse(char str[], int length)
{
	int i;
	char temp;
	for(i=1; i<=length/2; i++)
	{
		temp = str[i];
		str[i] = str[length + 1 - i];
		str[length + 1 - i] = temp;
	}
	return;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
	int B, i, j, k, len_i, len_square, len_square_tmp, equal;
	long int i_square;
	fin >> B;
	
	for(i=1; i<=300; i++)
	{
		i_square = i*i;
		len_i = convert(i, B, str_i);
		len_square = convert(i_square, B, str_square);
		reverse(str_i, len_i);
		reverse(str_square, len_square);
		j = 1;
		equal = 1;
		len_square_tmp = len_square;
		while(len_square_tmp>=j)
		{
			if(str_square[j++]!=str_square[len_square_tmp--])
			{
				equal = 0;
				break;
			}	
		}
		if(equal)
		{
			for(k=1; k<=len_i; k++)
			{
				fout << str_i[k];
			}
			fout << " ";
			for(k=1; k<=len_square; k++)
			{
				fout << str_square[k];
			}
			fout << endl;
		}
	}
	return 0;
}