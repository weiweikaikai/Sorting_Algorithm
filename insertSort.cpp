/*************************************************************************
	> File Name: insertSort.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sat 13 Aug 2016 06:52:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
 
//时间复杂度  比较 +后移次数

void InsertSort(int arr[],int n)
{
	 if(arr == NULL || n<=1)
	{
		 return ;
	}
	for(int i=1;i<n;++i)
	{
		int j=i;
        int tmp = arr[i];
		while(j && arr[j-1] > tmp)
		{
		  arr[j]=arr[j-1];
		  --j;
		}
		arr[j]=tmp;
	}
   
}

void test_arr()
{
	int arr[10] = { 1, 6, 0, 99, 77, 23, 56, 22, 12, 8 };
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout<<endl;
	InsertSort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	test_arr();
    return 0;
}

