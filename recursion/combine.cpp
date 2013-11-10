#include <iostream>
using namespace std;

void combine1( int a[], int n, int m,  int b[], const int M )
{
	for(int i=n; i>=m; i--)   // 注意这里的循环范围:先选最大的，然后第二大的，然后第三大的...
	{
		b[m-1] = i - 1;  //最后一个元素是最大的,或第二大的，或第三大的...
		if (m == 1)                     // m == 1, 输出一个组合
		{
			for(int j=M-1; j>=0; j--)
				cout << a[b[j]] << " ";
			cout << endl;
		}
		else
		{
			combine1(a,i-1,m-1,b,M); //上面的循环只选了一个元素，然后递归，在i-1个元素中选m-1个元素
		                                          //先是n-1个元素选m-1个，然后是n-2个元素中选m-1个...最后是m-1个元素
		}                                          //中选m-1个
	}
}

int main() 
{     
    int list[] = {4, 3, 2, 1};  
	int b[] = {0, 1, 2, 3};
    combine1(list, 4, 2, b, 2);     

    return 0; 
} 