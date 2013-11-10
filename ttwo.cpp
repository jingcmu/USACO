/*
ID:wo__che1
PROG: ttwo
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

typedef struct
{
	int i;
	int j;
	int direction;
}status;
status F, C;
bool forest[10][10];
int minutes;

void update(status *FC)
{
	switch(FC->direction)
	{
		case 0:
			if(FC->i&&forest[FC->i-1][FC->j])
				FC->i--;
			else
				FC->direction = 1;
			break;
		case 1:
			if(FC->j<9&&forest[FC->i][FC->j+1])
				FC->j++;
			else
				FC->direction = 2;
			break;
		case 2:
			if(FC->i<9&&forest[FC->i+1][FC->j])
				FC->i++;
			else
				FC->direction = 3;
			break;
		case 3:
			if(FC->j&&forest[FC->i][FC->j-1])
				FC->j--;
			else
				FC->direction = 0;
			break;
	}
}
	
void MOVE()
{
	if((F.i==C.i&&F.j==C.j)||minutes>160000)
		return;
	else
	{
		minutes++;
		update(&F);
		update(&C);
		MOVE();
	}
}

int main() 
{   
	int i, j, k;
	char c;
	freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);  //freopen("CON", "w", stdout);
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			cin>>c;
			forest[i][j] = (c=='*'?0:1);
			if(c=='F') 
			{
				F.i = i;
				F.j = j;
				F.direction = 0;
			}
			if(c=='C')
			{
				C.i = i;
				C.j = j;
				C.direction = 0;
			}
		}
	}

	MOVE();
	if(minutes<=160000)
		cout<<minutes<<endl;
	else
		cout<<"0"<<endl;
	return 0;
}

