#include <iostream>
using namespace std;

void combine1( int a[], int n, int m,  int b[], const int M )
{
	for(int i=n; i>=m; i--)   // ע�������ѭ����Χ:��ѡ���ģ�Ȼ��ڶ���ģ�Ȼ��������...
	{
		b[m-1] = i - 1;  //���һ��Ԫ��������,��ڶ���ģ���������...
		if (m == 1)                     // m == 1, ���һ�����
		{
			for(int j=M-1; j>=0; j--)
				cout << a[b[j]] << " ";
			cout << endl;
		}
		else
		{
			combine1(a,i-1,m-1,b,M); //�����ѭ��ֻѡ��һ��Ԫ�أ�Ȼ��ݹ飬��i-1��Ԫ����ѡm-1��Ԫ��
		                                          //����n-1��Ԫ��ѡm-1����Ȼ����n-2��Ԫ����ѡm-1��...�����m-1��Ԫ��
		}                                          //��ѡm-1��
	}
}

int main() 
{     
    int list[] = {4, 3, 2, 1};  
	int b[] = {0, 1, 2, 3};
    combine1(list, 4, 2, b, 2);     

    return 0; 
} 