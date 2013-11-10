/*
ID:wo__che1
PROG: castle
LANG: C++
*/
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

bool noeast, nowest, nonorth, nosouth;

typedef struct 
{
	int adjacent[4];
	bool visited;
}s_grid, *p_grid;

int room[10000];
int room_num = 0;
int a, b;
int final_max = 0;
int len  = 0;
int grid_g[10000][3], grid_final[3];

void check_grid(p_grid grid, int index)
{
	int i;
	if(grid[index].visited) return;
	else grid[index].visited = true;
	for(i=0; i<4; i++)
	{
		if((grid[index].adjacent[i] != -1)&&grid[grid[index].adjacent[i]].visited == false)
		{
			room[room_num]++;
			check_grid(grid, grid[index].adjacent[i]);
		}
	}
	return;
}

void find_room(p_grid grid, int gridnum)
{
	int i;
	for(i=0; i<gridnum; i++)
	{
		if(grid[i].visited == false)
		{
			room[room_num]=1;
			check_grid(grid, i);
			room_num++;
		}
	}
	return;
}

int main() {
    ofstream fout("castle.out");
    ifstream fin("castle.in");
	int gridnum, i, j, k, g, max_room = 0;
	fin>>a>>b;
	gridnum = a*b;
	p_grid grid = new s_grid[gridnum];
	for(i=0; i<gridnum; i++)
	{
		for(j=0; j<4; j++)
			grid[i].adjacent[j] = -1;
		grid[i].visited = false;
	}
	for(i=0; i<b; i++)
		for(j=0; j<a; j++)
		{
			fin>>g;
			switch(g)
			{
				case 0:
					grid[i*a+j].adjacent[0] = i*a+j-1;//west
					grid[i*a+j].adjacent[1] = (i-1)*a+j;//north
					grid[i*a+j].adjacent[2] = i*a+j+1;//east
					grid[i*a+j].adjacent[3] = (i+1)*a+j;//south
					break;
				case 1:
					grid[i*a+j].adjacent[1] = (i-1)*a+j;//north
					grid[i*a+j].adjacent[2] = i*a+j+1;//east
					grid[i*a+j].adjacent[3] = (i+1)*a+j;//south
					break;
				case 2:
					grid[i*a+j].adjacent[0] = i*a+j-1;//west
					grid[i*a+j].adjacent[2] = i*a+j+1;//east
					grid[i*a+j].adjacent[3] = (i+1)*a+j;//south
					break;
				case 3:
					grid[i*a+j].adjacent[2] = i*a+j+1;//east
					grid[i*a+j].adjacent[3] = (i+1)*a+j;//south
					break;
				case 4:
					grid[i*a+j].adjacent[0] = i*a+j-1;//west
					grid[i*a+j].adjacent[1] = (i-1)*a+j;//north
					grid[i*a+j].adjacent[3] = (i+1)*a+j;//south
					break;
				case 5:
					grid[i*a+j].adjacent[1] = (i-1)*a+j;//north
					grid[i*a+j].adjacent[3] = (i+1)*a+j;//south
					break;
				case 6:
					grid[i*a+j].adjacent[0] = i*a+j-1;//west
					grid[i*a+j].adjacent[3] = (i+1)*a+j;//south
					break;
				case 7:
					grid[i*a+j].adjacent[3] = (i+1)*a+j;//south
					break;
				case 8:
					grid[i*a+j].adjacent[0] = i*a+j-1;//west
					grid[i*a+j].adjacent[1] = (i-1)*a+j;//north
					grid[i*a+j].adjacent[2] = i*a+j+1;//east
					break;
				case 9:
					grid[i*a+j].adjacent[1] = (i-1)*a+j;//north
					grid[i*a+j].adjacent[2] = i*a+j+1;//east
					break;
				case 10:
					grid[i*a+j].adjacent[0] = i*a+j-1;//west
					grid[i*a+j].adjacent[2] = i*a+j+1;//east
					break;
				case 11:
					grid[i*a+j].adjacent[2] = i*a+j+1;//east
					break;
				case 12:
					grid[i*a+j].adjacent[0] = i*a+j-1;//west
					grid[i*a+j].adjacent[1] = (i-1)*a+j;//north
					break;
				case 13:
					grid[i*a+j].adjacent[1] = (i-1)*a+j;//north
					break;
				case 14:
					grid[i*a+j].adjacent[0] = i*a+j-1;//west
					break;
				case 15:
					break;
			}
		}

	find_room(grid, gridnum);
	for(i=0; i<room_num; i++)
	{
		if(max_room<room[i]) max_room = room[i];
	}

	fout<<room_num<<endl;	
	fout<<max_room<<endl;

	final_max = max_room;
	
	for(i=0; i<b; i++)
	{
		nonorth = (i == 0)?true:false;
		nosouth = (i == b-1)?true:false;
		for(j=0; j<a; j++)
		{
			nowest = (j==0)?true:false; 
			noeast = (j==a-1)?true:false;
			if(grid[i*a+j].adjacent[0]==-1&&!nowest)
			{
				grid[i*a+j].adjacent[0] = i*a+j-1;
				for(k=0; k<gridnum; k++)
				{
					grid[k].visited = false;
				}
				room[room_num] = 1;
				check_grid(grid, i*a+j);
				if(room[room_num]>=final_max) 
				{
					if(room[room_num]>final_max) len=0;
					grid_g[len][0] = i+1;
					grid_g[len][1] = j+1;
					grid_g[len][2] = 0;
					len++;
					final_max = room[room_num];
				}
				grid[i*a+j].adjacent[0] = -1;
			}
			if(grid[i*a+j].adjacent[1]==-1&&!nonorth)
			{
				grid[i*a+j].adjacent[1] = (i-1)*a+j;
				for(k=0; k<gridnum; k++)
				{
					grid[k].visited = false;
				}
				room[room_num] = 1;
				check_grid(grid, i*a+j);
				if(room[room_num]>=final_max) 
				{
					if(room[room_num]>final_max) len=0;
					grid_g[len][0] = i+1;
					grid_g[len][1] = j+1;
					grid_g[len][2] = 1;
					len++;
					final_max = room[room_num];
				}
				grid[i*a+j].adjacent[1] = -1;
			}
			if(grid[i*a+j].adjacent[2]==-1&&!noeast)
			{
				grid[i*a+j].adjacent[2] = i*a+j+1;
				for(k=0; k<gridnum; k++)
				{
					grid[k].visited = false;
				}
				room[room_num] = 1;
				check_grid(grid, i*a+j);
				if(room[room_num]>=final_max) 
				{
					if(room[room_num]>final_max) len=0;
					grid_g[len][0] = i+1;
					grid_g[len][1] = j+1;
					grid_g[len][2] = 2;
					len++;
					final_max = room[room_num];
				}
				grid[i*a+j].adjacent[2] = -1;
			}
			if(grid[i*a+j].adjacent[3]==-1&&!nosouth)
			{
				grid[i*a+j].adjacent[3] = (i+1)*a+j;
				for(k=0; k<gridnum; k++)
				{
					grid[k].visited = false;
				}
				room[room_num] = 1;
				check_grid(grid, i*a+j);
				if(room[room_num]>=final_max) 
				{
					if(room[room_num]>final_max) len=0;
					grid_g[len][0] = i+1;
					grid_g[len][1] = j+1;
					grid_g[len][2] = 3;
					len++;
					final_max = room[room_num];
				}
				grid[i*a+j].adjacent[3] = -1;
			}
		}
	}
	
	fout<<final_max<<endl;
	grid_final[0] = grid_g[0][0];
	grid_final[1] = grid_g[0][1];
	grid_final[2] = grid_g[0][2];
	for(i=1; i<len; i++)
	{
		if(grid_g[i][1]<grid_final[1]||(grid_g[i][1]==grid_final[1]&&grid_g[i][0]>grid_final[0]))
		{
			grid_final[0] = grid_g[i][0];
			grid_final[1] = grid_g[i][1];
			grid_final[2] = grid_g[i][2];
		}
	}
	fout<<grid_final[0]<<" "<<grid_final[1]<<" ";
	if(grid_final[2]==1)
		fout<<"N"<<endl;
	if(grid_final[2]==2)
		fout<<"E"<<endl;
	return 0;
}
