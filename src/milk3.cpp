/*
ID:wo__che1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

typedef struct {
	int capacity;
	int milk;
} milk_bucket;

int c_milk[20];
int len_cmilk=0;
map<int, bool> m;

void pour_fromXtoY(milk_bucket *X, milk_bucket *Y){
	if((*X).milk<=(*Y).capacity-(*Y).milk){					
		(*Y).milk += (*X).milk;
		(*X).milk = 0;
	}
	else{
		(*X).milk -= ((*Y).capacity-(*Y).milk);
		(*Y).milk = (*Y).capacity;
	}
}

void calc_milk(milk_bucket A, milk_bucket B, milk_bucket C) {
	int status;
	int i;
	milk_bucket A_L, B_L, C_L;  //用来存储以备还原
	status = (A.milk<<10)+(B.milk<<5)+C.milk;  //记录状态
	
	if(m[status]) return;//已出现过该状态
	m[status] = true;
	if(!A.milk) {  //如果A桶此时为空，则记录下c桶现在的奶量
		c_milk[len_cmilk++] = C.milk;
	}
	if(A.milk) {
		//A->B
		A_L = A; B_L = B; C_L = C; //备份
		if(B.milk!=B.capacity) {
			pour_fromXtoY(&A, &B);
			calc_milk(A, B, C);
		}
		A = A_L; B = B_L; C = C_L; //还原
		//A->C
		if(C.milk!=C.capacity)
		{
			pour_fromXtoY(&A, &C);
			calc_milk(A, B, C);
		}
		A = A_L; B = B_L; C = C_L; //还原
	}
	
	if(B.milk)
	{
		A_L = A; B_L = B; C_L = C; //备份
		//B->A
		if(A.milk!=A.capacity) {
			pour_fromXtoY(&B, &A);
			calc_milk(A, B, C);
		}
		A = A_L; B = B_L; C = C_L; //还原
		//B->C
		if(C.milk!=C.capacity) {
			pour_fromXtoY(&B, &C);
			calc_milk(A, B, C);
		}
		A = A_L; B = B_L; C = C_L; //还原
	}
	if(C.milk) {
		A_L = A; B_L = B; C_L = C; //备份
		//C->A
		if(A.milk!=A.capacity) {
			pour_fromXtoY(&C, &A);
			calc_milk(A, B, C);
		}
		A = A_L; B = B_L; C = C_L; //还原
		//C->B
		if(B.milk!=B.capacity)
		{
			pour_fromXtoY(&C, &B);
			calc_milk(A, B, C);
		}
		A = A_L; B = B_L; C = C_L; //还原
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
	calc_milk(A, B, C);
	sort(c_milk, c_milk+len_cmilk);
	for(i=0; i<len_cmilk-1; i++)
		fout<<c_milk[i]<<" ";
	fout<<c_milk[len_cmilk-1]<<endl;
	return 0;
}