/*************************************************************************
	> File Name: MergeSort.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sun 14 Aug 2016 02:35:30 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
 

 //time:O(nlog2 N)
 //room:O(n)
//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = first+((last-first)>>1);
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}

bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

void test()
{
    int arr[10]={99,8,7,6,5,4,3,2,1,0};
    for(int i=0;i<10;++i)
    {
        cout<<arr[i]<<" ";
    }
	cout<<endl;
    MergeSort(arr,10);
    for(int i=0;i<10;++i)
    {
        cout<<arr[i]<<" ";
    }
	cout<<endl;
}


int main()
{
	test();
    return 0;
}

