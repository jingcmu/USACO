/*
ID:wo__che1
PROG: spin
LANG: C++
*/
#include<stdio.h>
const int MAXW=5;
struct lovekid{
 int speed;//�ٶ�
 int number;//ȱ����
 int start[MAXW];//��ʼ�Ƕ�
 int length[MAXW];//ȱ�ڳ���
 int currentStart[MAXW];//��ת��Ŀ�ʼ�Ƕ�
 int currentLength[MAXW];//��ת��ĳ���
}wheel[MAXW];
bool none;
int ans;
bool CheckAns(){
 /*���ÿһ���ӣ����ܲ��ܳ���������������*/
 int i,j,k;
 /*������ѭ�������Ƿ��ܻ�����ʼ��ʱ���״̬�������
 �Ļ�����˵��none is true!*/
 for(i=0;i<5;i++)
  if(!(wheel[i].currentStart[0]==wheel[i].start[0]
  &&wheel[i].length[0]==wheel[i].currentLength[0]-wheel[i].currentStart[0]))
   break;
 if(i==5){
  return none=true;
 }
 bool check;
 /*��1---359��飬���Ƿ��������*/
 for(i=0;i<360;i++){
  check=true;
  for(j=0;j<5&&check;j++){
   for(k=0;k<wheel[j].number;k++)
    if((i>=wheel[j].currentStart[k]&&i<=wheel[j].currentLength[k])||
     (i+360>=wheel[j].currentStart[k]&&i+360<=wheel[j].currentLength[k]))
     break;
   if(k==wheel[j].number)check=false;
  }
  if(check)return true;//����ͷ���true!
 }
 return check;
}
void Solve(){
 int ans=0;
 while(true){
  if(CheckAns())break;
  ans++;
  /*�������ݣ�����mod360,���mod��currentLength[j]<currentStart[j],
  ��+��360����������CheckAns�ļ��*/
  for(int i=0;i<5;i++)
   for(int j=0;j<wheel[i].number;j++){
    wheel[i].currentStart[j]+=wheel[i].speed;
    wheel[i].currentStart[j]%=360;
    wheel[i].currentLength[j]=wheel[i].currentStart[j]+wheel[i].length[j];
    wheel[i].currentLength[j]%=360;
    if(wheel[i].currentLength[j]<=wheel[i].currentStart[j])
     wheel[i].currentLength[j]+=360;
   }
 }
 if(none)printf("none\n");
 else printf("%d\n",ans);
}
void Read_Solve(){
 /*�������ݣ����ҳ�ʼ������*/
 for(int i=0;i<5;i++){
  scanf("%d%d",&wheel[i].speed,&wheel[i].number);
  for(int j=0;j<wheel[i].number;j++){
   scanf("%d%d",&wheel[i].start[j],&wheel[i].length[j]);
   wheel[i].currentStart[j]=wheel[i].start[j];
   wheel[i].currentLength[j]=wheel[i].length[j];
  }
 }
 Solve();
}
int main(){
 freopen("spin.in","r",stdin);
 freopen("spin.out","w",stdout);
 Read_Solve();
 return 0;
}
