/*
ID:wo__che1
PROG: maze1
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

typedef struct
{
	int x; int y;
}vertex;

vertex source[2];
int src_index, max_step;
int maze[100][38];
int step[2][100][38], step_final[100][38];
bool visited[2][100][38];
vertex que[3800];
int start, end;

void getSteps(int w, int h, int x, int y, int flag)
{
	int i, j;
	if(start == end) return;
	else
	{
		visited[flag][x][y] = true;
		start++;
		if((!visited[flag][x+1][y])&&(maze[x][y]&4)&&(x<h-1))
		{
			step[flag][x+1][y] = step[flag][x][y]+1;
			visited[flag][x+1][y] = true;
			que[end].x = x+1;
			que[end++].y = y;
		}
		if((!visited[flag][x][y+1])&&(maze[x][y]&1)&&(y<w-1))
		{
			step[flag][x][y+1] = step[flag][x][y]+1;
			visited[flag][x][y+1] = true;
			que[end].x = x;
			que[end++].y = y+1;
		}
		if((!visited[flag][x][y-1])&&(maze[x][y]&2)&&y>0)
		{
			step[flag][x][y-1] = step[flag][x][y]+1;
			visited[flag][x][y-1] = true;
			que[end].x = x;
			que[end++].y = y-1;
		}
		if((!visited[flag][x-1][y])&&(maze[x][y]&8)&&x>0)
		{
			step[flag][x-1][y] = step[flag][x][y]+1;
			visited[flag][x-1][y] = true;
			que[end].x = x-1;
			que[end++].y = y;
		}
	}
}			

void readData(int w, int h)
{
	int i, j;
	char c;
	for(i=0; i<2*h+1; i++)
	{
		for(j=0; c=getchar(), j<2*w+1; j++)
		{
			if((!i||i==2*h)&&c==32)
			{
				source[src_index].x = (!i? 0 : h-1);
				source[src_index].y = j/2;
				src_index++;
			}
			else if(i%2)
			{
				if((!j||j==2*w)&&c!='|')
				{
					source[src_index].x = i/2;
					source[src_index].y = (j-1)/2;
					src_index++;
				}
				else if(!(j%2)&&c==32)
				{
					maze[i/2][j/2-1] |= 1;  	//右联通
					maze[i/2][j/2] |= 2;       //左联通
				}
			}
			else if(i%2==0)
			{
				if((j%2)&&c==32)
				{
					maze[i/2-1][j/2] |= 4;	//下联通
					maze[i/2][j/2] |= 8;		//上联通
				}
			}
		}
	}
}

int main() 
{   
	char c;
	int i, j, k, w, h;
	freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);  //freopen("CON", "w", stdout);
	cin>>w>>h;
	c = getchar();
	readData(w, h);
	start = end = 0;
	step[0][source[0].x][source[0].y] = 1;	
	que[end].x = source[0].x;
	que[end++].y = source[0].y;
	while(start!=end)
		getSteps(w, h, que[start].x, que[start].y, 0);
	//getSteps(w, h, source[0].x, source[0].y, 0);	

	start = end = 0;
	que[end].x = source[1].x;
	que[end++].y = source[1].y;
	step[1][source[1].x][source[1].y] = 1;
	while(start!=end)
		getSteps(w, h, que[start].x, que[start].y, 1);
	//getSteps(w, h, source[1].x, source[1].y, 1);

	for(i=0; i<h; i++)
		for(j=0; j<w; j++)
		{
			step_final[i][j] = step[0][i][j]>step[1][i][j]? step[1][i][j] : step[0][i][j];
			if(max_step<step_final[i][j]) max_step = step_final[i][j];
		}
	cout<<max_step<<endl;
	return 0;
}

