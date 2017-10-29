/*************************************************************************
	> File Name: ShellSort.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sat 13 Aug 2016 07:44:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
 
 //O(n log2 N)
void ShellSort(int arr[],int d,int n)
{
    if(arr == NULL || d >=n || n<=0)
	{
		return ;
	}

	for(int i=d;i>0;i/=2)
	{
	   for(int j=i;j<n;++j)
		{
		  int tmp=arr[j];
		  int k=j-i;
		  for(;k>=0&& arr[k] > tmp; k-=i)
			{
		      arr[k+i]=arr[k]; 
		    }
	        arr[k+i]=tmp;
	   }
	 
	}
}

void test()
{
  int arr[10]={99,8,7,6,5,4,3,2,1,0};
    for(int i=0;i<10;++i)
    {
        cout<<arr[i]<<" ";
    }
	cout<<endl;
     ShellSort(arr,5,10);
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

