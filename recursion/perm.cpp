#include <iostream>
using namespace std;

int n = 0;  

void swap(int *a, int *b) 
{     
    int m;     
    m = *a;     
    *a = *b;     
    *b = m; 
}  
void perm(int list[], int k, int m) 
{     
    int i;     
    if(k == m)     
    {          
        for(i = 0; i <= m; i++)             
            cout<< list[i] << " ";         
		cout << endl;        
        n++;     
    }     
    else     
    {         
        for(i = k; i <= m; i++)     //序号为从k到m元素的全排列
        {             
            swap(&list[k], &list[i]);   // r1 perm(p1) ...  rn perm(pn) 
            perm(list, k + 1, m);      // 序号为从k+1到m元素的全排列 
            swap(&list[k], &list[i]);    // 交换回来, 顺序不能乱
        }     
    } 
} 
int main() 
{     
    int list[] = {1, 2, 3, 4};     
    perm(list, 0, 3);     
    cout <<"total:"<<n<<endl;     
    return 0; 
} 