/*************************************************************************
	> File Name: SelectSort.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sat 13 Aug 2016 10:02:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
 

void SelectSort(int arr[],int n)
{
  if(arr == NULL || n<=0)
	{
      return ;
    }
	for(int i=0;i<n;++i)
	{
	  int min = i;
	  for(int j=i+1;j<n;++j)
		{
	      if(arr[min] > arr[j])
			{
		       min=j;
		    } 
	    }
		if(min !=i )
		{
		  std::swap(arr[min],arr[i]);
		}
	}
  
}


void test()
{
  	int arr[10]={99,7,5,4,3,5,34,5,24,56};
	for(int i=0;i<10;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	 SelectSort(arr,10);
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

