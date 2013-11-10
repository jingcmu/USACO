/*
ID:wo__che1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef struct
{
	int capacity;
	int milk;
}milk_bucket;

int status[8000];
int len = 0;
int c_milk[20];
int len_cmilk=0;

void pour_fromXtoY(milk_bucket *X, milk_bucket *Y)
{
	if((*X).milk<=(*Y).capacity-(*Y).milk)
	{					
		(*Y).milk += (*X).milk;
		(*X).milk = 0;
	}
	else
	{
		(*X).milk -= ((*Y).capacity-(*Y).milk);
		(*Y).milk = (*Y).capacity;
	}
	return;
}

void pour_milk(milk_bucket A, milk_bucket B, milk_bucket C)
{
	int flag, status_l;
	int i;
	milk_bucket A_L, B_L, C_L;
	status_l = (A.milk<<10)+(B.milk<<5)+C.milk;  //记录状态
	//cout << A.milk << " "  << B.milk << " "  <<  C.milk << endl;
	
	flag = 1;
	
	for(i=0; i<len; i++)
	{
		if(status_l == status[i])//已出现过该状态
		{
			flag = 0;
			return;
		}
	}
	
	if(flag)//未出现过该状态
	{
		if(!A.milk)
		{
			c_milk[len_cmilk++] = C.milk;
		}
		status[len++] = status_l;    //记录该状态
		if(A.milk)
		{
			//A->B
			A_L = A; B_L = B; C_L = C;
			if(B.milk!=B.capacity)
			{
				pour_fromXtoY(&A, &B);
				pour_milk(A, B, C);
			}
			A = A_L; B = B_L; C = C_L;
			//A->C
			if(C.milk!=C.capacity)
			{
				pour_fromXtoY(&A, &C);
				pour_milk(A, B, C);
			}
			A = A_L; B = B_L; C = C_L;
		}
		
		if(B.milk)
		{
			A_L = A; B_L = B; C_L = C;
			//B->A
			if(A.milk!=A.capacity)
			{
				pour_fromXtoY(&B, &A);
				pour_milk(A, B, C);
			}
			A = A_L; B = B_L; C = C_L;
			//B->C
			if(C.milk!=C.capacity)
			{
				pour_fromXtoY(&B, &C);
				pour_milk(A, B, C);
			}
			A = A_L; B = B_L; C = C_L;
		}
		if(C.milk)
		{
			A_L = A; B_L = B; C_L = C; 
			//C->A
			if(A.milk!=A.capacity)
			{
				pour_fromXtoY(&C, &A);
				pour_milk(A, B, C);
			}
			A = A_L; B = B_L; C = C_L;
			//C->B
			if(B.milk!=B.capacity)
			{
				pour_fromXtoY(&C, &B);
				pour_milk(A, B, C);
			}
			A = A_L; B = B_L; C = C_L;
		}
	}
}

int main()
{
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	milk_bucket A, B, C;
	int i;
	fin>>A.capacity>>B.capacity>>C.capacity;
	//INIT
	C.milk = C.capacity; 
	A.milk = B.milk = 0;
	pour_milk(A, B, C);
	sort(c_milk, c_milk+len_cmilk);
	for(i=0; i<len_cmilk-1; i++)
		fout<<c_milk[i]<<" ";
	fout<<c_milk[len_cmilk-1]<<endl;
	return 0;
}