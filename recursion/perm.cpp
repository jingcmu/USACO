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
        for(i = k; i <= m; i++)     //���Ϊ��k��mԪ�ص�ȫ����
        {             
            swap(&list[k], &list[i]);   // r1 perm(p1) ...  rn perm(pn) 
            perm(list, k + 1, m);      // ���Ϊ��k+1��mԪ�ص�ȫ���� 
            swap(&list[k], &list[i]);    // ��������, ˳������
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