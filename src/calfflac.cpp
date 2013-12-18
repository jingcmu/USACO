/*
ID:wo__che1
PROG: calfflac
LANG: C++
*/
//思路: 用2个char数组，一个存原始字符串
//一个存去掉标点符号的字符串
//再用一个int数组存char数组的下标对应关系
#include <iostream>
#include <fstream>
using namespace std;
char str[20001], str_orig[20001], ch;  
int l, ls, index[20001];  
//判断是否是字符,若是,转为小写
int turn(char c){  
    if (c>='a' && c<='z') return c;  
    if (c>='A' && c<='Z') return c+'a'-'A';  
    return 0;  
}  
int main(){  
    freopen("calfflac.in", "r", stdin);  
    freopen("calfflac.out", "w", stdout);  
    str[0] = str_orig[0] = '#';  
    while (scanf("%c",&ch)!=EOF){  
        str_orig[++ls]=ch;  
        if (turn(ch)) {  
            str[++l]=turn(ch);  
            index[l] = ls;  
        }  
    }  
    int ans=1,ans_start=1,j1,j2;  
    for (int i=2;i<=l;i++){  
		//以位置i为中心向两边扩展
		//偶数
        if (str[i] == str[i+1]) {
			for (j1=i,j2=i+1;j1>1 && j2<l && str[j1-1]==str[j2+1];j1--,j2++); 
		}
		//奇数
		else{
			for (j1=i,j2=i; j1>1 && j2<l && str[j1-1]==str[j2+1];j1--,j2++);  
		}
        if (j2-j1+1> ans){  
            ans = j2-j1+1;  
            ans_start = j1;  
        }  
    }  
    cout << ans << endl;
    int p = 0;  
    for (int i=index[ans_start]; p<ans; i++){  
        cout << str_orig[i];
        if (turn(str_orig[i])) p++;  
    }  
    cout << endl;  
    return 0;  
}  