/*
ID:wo__che1
PROG: calfflac
LANG: C++
*/
//˼·: ��2��char���飬һ����ԭʼ�ַ���
//һ����ȥ�������ŵ��ַ���
//����һ��int�����char������±��Ӧ��ϵ
#include <iostream>
#include <fstream>
using namespace std;
char str[20001], str_orig[20001], ch;  
int l, ls, index[20001];  
//�ж��Ƿ����ַ�,����,תΪСд
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
		//��λ��iΪ������������չ
		//ż��
        if (str[i] == str[i+1]) {
			for (j1=i,j2=i+1;j1>1 && j2<l && str[j1-1]==str[j2+1];j1--,j2++); 
		}
		//����
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