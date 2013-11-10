/*
ID:wo__che1
PROG: rect1
LANG: C++
*/

#include <fstream>//来一个紧凑一点的代码，太长的容易吓走人
#include <algorithm>//这里使用cstdio然后max和min手写可能能提高点速度
using namespace std;
ifstream fin("rect1.in");
ofstream fout("rect1.out");
int x1[1001],y1[1001],x2[1001],y2[1001],color[1001]={1},cnt[2501],N;//记录各种信息，cnt数组统计各种颜色的面积，第0号矩形就是地板
void cover(int lx,int ly,int rx,int ry,int c,int h)//矩形切割上浮的思想，递归版本（啊说了这个代码特点是短而不是快- -），c是颜色，h是高度
{
	if (lx==rx || ly==ry) return;//优化：面积为0的矩形要舍掉，否则会TLE（第6个点就1.6秒了）
	if (h>N) cnt[c]+=(ry-ly)*(rx-lx);//上浮到最高后计算面积，由于面积一定不会被覆盖所以直接加上去就好了
	else{//对称的分为四块，嗯就是小学奥数时候见过的那个叫“弦图”的奇葩东西……不知道是不是都听说过
		if (ly<y1[h]) cover(min(x2[h],lx),ly,min(x2[h],rx),min(y1[h],ry),c,h+1);
		if (rx>x2[h]) cover(max(x2[h],lx),min(y2[h],ly),rx,min(y2[h],ry),c,h+1);
		if (ry>y2[h]) cover(max(x1[h],lx),max(y2[h],ly),max(x1[h],rx),ry,c,h+1);
		if (lx<x1[h]) cover(lx,max(y1[h],ly),min(x1[h],rx),max(y1[h],ry),c,h+1);
	}//注意这里对矩形位置的讨论思想是：只要凸出来就“切”开，注意比较边界坐标来：1、确保切割不重复。2、确保不切不存在的内容
}//例如如果矩形整个位于它“上面”矩形的左上角，直接判断会出错。注意这样子之后有可能切出来面积为0的矩形，必须剪枝！
int main()
{
	fin>>x2[0]>>y2[0]>>N;//读入数据，直接存在地板那块矩形的数据里
	for (int i=1;i<=N;++i) fin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>color[i];//读入数据读入数据……
	cnt[color[N]]+=(x2[N]-x1[N])*(y2[N]-y1[N]);//最上面那块直接算
	for (int i=N-1;i>=0;--i) cover(x1[i],y1[i],x2[i],y2[i],color[i],i+1);//依次向下处理每一块矩形
	for (int i=1;i<=2500;++i) if (cnt[i]) fout<<i<<" "<<cnt[i]<<endl;//输出
	return 0;
}//加上全部注释和花括号31行= =至于速度，第8，9个点0.011sec，第11个点0.130sec，其余0.000sec过
