/*
ID:wo__che1
PROG: lamps
LANG: C++
*/
#include <fstream>
#include <iostream>

using namespace std;

int lamps[4] =
{0x1ffffff, 0x1ffffff, 0x1ffffff, 0x1ffffff};
int buttons0[4] =
{0xffffffff, 0x55555555, 0xaaaaaaaa, 0x1249249};
int buttons1[4] =
{0xffffffff, 0xaaaaaaaa, 0x55555555, 0x492492};
int buttons2[4] =
{0xffffffff, 0x55555555, 0xaaaaaaaa, 0x924924};
int buttons3[4] =
{0xffffffff, 0xaaaaaaaa, 0x55555555, 0x1249249};
int lampstate[4][16];
int state_num;
int test_on[4], test_off[4];
int table_on[26] =
{	0,
	1<<24, 1<<23, 1<<22, 1<<21, 1<<20,  
	1<<19, 1<<18, 1<<17, 1<<16, 1<<15,  
	1<<14, 1<<13, 1<<12, 1<<11, 1<<10,  
	1<<9, 1<<8, 1<<7, 1<<6, 1<<5,  
	1<<4, 1<<3, 1<<2, 1<<1, 1,  
};
int table_off[26] =
{	0,
	1<<24, 1<<23, 1<<22, 1<<21, 1<<20,  
	1<<19, 1<<18, 1<<17, 1<<16, 1<<15,  
	1<<14, 1<<13, 1<<12, 1<<11, 1<<10,  
	1<<9, 1<<8, 1<<7, 1<<6, 1<<5,  
	1<<4, 1<<3, 1<<2, 1<<1, 1,  
};
/*	
{
	  0xFFFFFF, 0x17FFFFF, 0x1BFFFFF, 0x1DFFFFF, 0x1EFFFFF,
	0x1F7FFFF, 0x1FBFFFF, 0x1FDFFFF, 0x1FEFFFF, 0x1FF7FFF,
	0x1FFBFFF, 0x1FFDFFF, 0x1FFEFFF, 0x1FFF7FF, 0x1FFFBFF,
	0x1FFFDFF, 0x1FFFEFF, 0x1FFFF7F, 0x1FFFFBF, 0x1FFFFDF,
	0x1FFFFEF, 0x1FFFFF7, 0x1FFFFFB, 0x1FFFFFD, 0x1FFFFFE,
};*/

void copy_lamp()
{
	lampstate[0][state_num] = lamps[0];
	lampstate[1][state_num] = lamps[1];
	lampstate[2][state_num] = lamps[2];
	lampstate[3][state_num++] = lamps[3];
}

void sort(int lamp_num)
{
	int i, j, k;
	for(i=state_num-1; i>0; i--)
		for(j=0; j<i; j++)
		{
			if(lampstate[0][j+1]<lampstate[0][j])
			{
				for(k=0; k<lamp_num; k++)
				{
					int temp;
					temp = lampstate[k][j+1];
					lampstate[k][j+1] = lampstate[k][j];
					lampstate[k][j] = temp;
				}
			}
		}
	
}

void remove_lamp(int n)
{
	int i;
	for(i=n; i<state_num-1; i++)
	{
		lampstate[0][i] = lampstate[0][i+1];
		lampstate[1][i] = lampstate[1][i+1];
		lampstate[2][i] = lampstate[2][i+1];
		lampstate[3][i] = lampstate[3][i+1];
	}
	state_num--;
}

void set_lamps()
{
	lamps[0] = 0xffffffff;
	lamps[1] = 0xffffffff;
	lamps[2] = 0xffffffff;
	lamps[3] = 0xffffffff;
}

void turn_button_sub(int a)
{
	int i, j;
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if((a>>i)&1)
			{
				if(j==0)
					lamps[j]^=buttons0[i];
				if(j==1)
					lamps[j]^=buttons1[i];
				if(j==2)
					lamps[j]^=buttons2[i];
				if(j==3)
					lamps[j]^=buttons3[i];
			}
		}
	}
}

void turn_button(int c)
{
	int i;
	if(!c) 
	{
		copy_lamp();
		return;
	}
	if(c==1)
	{
		turn_button_sub(1); copy_lamp(); set_lamps();
		turn_button_sub(2); copy_lamp(); set_lamps();
		turn_button_sub(4); copy_lamp(); set_lamps();
		turn_button_sub(8); copy_lamp(); set_lamps();
		return;
	}
	if(c==2)
	{
		turn_button_sub(3); copy_lamp(); set_lamps();
		turn_button_sub(5); copy_lamp(); set_lamps();
		turn_button_sub(6); copy_lamp(); set_lamps();
		turn_button_sub(9); copy_lamp(); set_lamps();
		turn_button_sub(10); copy_lamp(); set_lamps();
		turn_button_sub(12); copy_lamp(); set_lamps();
		return;
	}
	if(c%2)
	{
		turn_button_sub(1); copy_lamp(); set_lamps();
		turn_button_sub(2); copy_lamp(); set_lamps();
		turn_button_sub(4); copy_lamp(); set_lamps();
		turn_button_sub(7); copy_lamp(); set_lamps();
		turn_button_sub(8); copy_lamp(); set_lamps();
		turn_button_sub(11); copy_lamp(); set_lamps();
		turn_button_sub(13); copy_lamp(); set_lamps();
		turn_button_sub(14); copy_lamp(); set_lamps();
		return;
	}
	else
	{
		turn_button_sub(0); copy_lamp(); set_lamps();
		turn_button_sub(3); copy_lamp(); set_lamps();
		turn_button_sub(5); copy_lamp(); set_lamps();
		turn_button_sub(6); copy_lamp(); set_lamps();
		turn_button_sub(9); copy_lamp(); set_lamps();
		turn_button_sub(10); copy_lamp(); set_lamps();
		turn_button_sub(12); copy_lamp(); set_lamps();
		turn_button_sub(15); copy_lamp(); set_lamps();
		return;
	}
}
	
int main() {
	int l, i, j, on, off;
	int N, C, lamp_num;
	freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
	cin>>N;   //freopen("CON", "w", stdout);
	lamp_num = (N-1)/25+1;
	cin>>C;
	turn_button(C);
	while((cin>>on)&&on!=-1)
	{
		int ii, jj;
		ii = (on-1)/25;
		jj = on%25;
		test_on[ii]|=table_on[jj];
	}
	while((cin>>off)&&off!=-1)
	{
		int ii, jj;
		ii = (off-1)/25;
		jj = off%25;
		test_off[ii]|=table_off[jj];
	}
	
	for(l=0; l<state_num; l++)
	{
		for(i=0; i<lamp_num; i++)
		{
			lampstate[i][l]&=0x1ffffff;
			if(((lampstate[i][l]&test_on[i])!=test_on[i])||((lampstate[i][l]&test_off[i])!=0))
			{
				remove_lamp(l); l--; break;
			}
		}
	}
	sort(lamp_num);

	if(!state_num) cout<<"IMPOSSIBLE"<<endl;
	
	for(l=0; l<state_num; l++)
	{
		for(i=0; i<lamp_num; i++)
		{
			if((i+1!=lamp_num)||(N%25==0))
			{
				for(j=0; j<25; j++)
					if((lampstate[i][l]<<j)&0x1000000)
						cout<<"1";
					else cout<<"0";
			}
			else
			{
				for(j=0; j<N%25; j++)
					if((lampstate[i][l]<<j)&0x1000000)
					cout<<"1";
					else cout<<"0";
			}			
		}
		cout<<endl;
	}
	return 0;
}
