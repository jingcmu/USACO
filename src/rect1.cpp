/*
ID:wo__che1
PROG: rect1
LANG: C++
*/

#include <fstream>//��һ������һ��Ĵ��룬̫��������������
#include <algorithm>//����ʹ��cstdioȻ��max��min��д��������ߵ��ٶ�
using namespace std;
ifstream fin("rect1.in");
ofstream fout("rect1.out");
int x1[1001],y1[1001],x2[1001],y2[1001],color[1001]={1},cnt[2501],N;//��¼������Ϣ��cnt����ͳ�Ƹ�����ɫ���������0�ž��ξ��ǵذ�
void cover(int lx,int ly,int rx,int ry,int c,int h)//�����и��ϸ���˼�룬�ݹ�汾����˵����������ص��Ƕ̶����ǿ�- -����c����ɫ��h�Ǹ߶�
{
	if (lx==rx || ly==ry) return;//�Ż������Ϊ0�ľ���Ҫ����������TLE����6�����1.6���ˣ�
	if (h>N) cnt[c]+=(ry-ly)*(rx-lx);//�ϸ�����ߺ����������������һ�����ᱻ��������ֱ�Ӽ���ȥ�ͺ���
	else{//�ԳƵķ�Ϊ�Ŀ飬�ž���Сѧ����ʱ��������Ǹ��С���ͼ�������ⶫ��������֪���ǲ��Ƕ���˵��
		if (ly<y1[h]) cover(min(x2[h],lx),ly,min(x2[h],rx),min(y1[h],ry),c,h+1);
		if (rx>x2[h]) cover(max(x2[h],lx),min(y2[h],ly),rx,min(y2[h],ry),c,h+1);
		if (ry>y2[h]) cover(max(x1[h],lx),max(y2[h],ly),max(x1[h],rx),ry,c,h+1);
		if (lx<x1[h]) cover(lx,max(y1[h],ly),min(x1[h],rx),max(y1[h],ry),c,h+1);
	}//ע������Ծ���λ�õ�����˼���ǣ�ֻҪ͹�����͡��С�����ע��Ƚϱ߽���������1��ȷ���и�ظ���2��ȷ�����в����ڵ�����
}//���������������λ���������桱���ε����Ͻǣ�ֱ���жϻ����ע��������֮���п����г������Ϊ0�ľ��Σ������֦��
int main()
{
	fin>>x2[0]>>y2[0]>>N;//�������ݣ�ֱ�Ӵ��ڵذ��ǿ���ε�������
	for (int i=1;i<=N;++i) fin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>color[i];//�������ݶ������ݡ���
	cnt[color[N]]+=(x2[N]-x1[N])*(y2[N]-y1[N]);//�������ǿ�ֱ����
	for (int i=N-1;i>=0;--i) cover(x1[i],y1[i],x2[i],y2[i],color[i],i+1);//�������´���ÿһ�����
	for (int i=1;i<=2500;++i) if (cnt[i]) fout<<i<<" "<<cnt[i]<<endl;//���
	return 0;
}//����ȫ��ע�ͺͻ�����31��= =�����ٶȣ���8��9����0.011sec����11����0.130sec������0.000sec��
