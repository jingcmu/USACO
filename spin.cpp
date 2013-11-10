/*
ID:wo__che1
PROG: spin
LANG: C++
*/
#include<stdio.h>
const int MAXW=5;
struct lovekid{
 int speed;//速度
 int number;//缺口数
 int start[MAXW];//开始角度
 int length[MAXW];//缺口长度
 int currentStart[MAXW];//旋转后的开始角度
 int currentLength[MAXW];//旋转后的长度
}wheel[MAXW];
bool none;
int ans;
bool CheckAns(){
 /*检查每一分钟，看能不能出现满足题意的情况*/
 int i,j,k;
 /*这里检查循环，看是否跑回来初始化时候的状态，如果是
 的话，则说明none is true!*/
 for(i=0;i<5;i++)
  if(!(wheel[i].currentStart[0]==wheel[i].start[0]
  &&wheel[i].length[0]==wheel[i].currentLength[0]-wheel[i].currentStart[0]))
   break;
 if(i==5){
  return none=true;
 }
 bool check;
 /*从1---359检查，看是否满足情况*/
 for(i=0;i<360;i++){
  check=true;
  for(j=0;j<5&&check;j++){
   for(k=0;k<wheel[j].number;k++)
    if((i>=wheel[j].currentStart[k]&&i<=wheel[j].currentLength[k])||
     (i+360>=wheel[j].currentStart[k]&&i+360<=wheel[j].currentLength[k]))
     break;
   if(k==wheel[j].number)check=false;
  }
  if(check)return true;//满足就返回true!
 }
 return check;
}
void Solve(){
 int ans=0;
 while(true){
  if(CheckAns())break;
  ans++;
  /*更新数据，并且mod360,如果mod后currentLength[j]<currentStart[j],
  则+回360，方便上面CheckAns的检查*/
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
 /*输入数据，并且初始化数据*/
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
