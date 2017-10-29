/*************************************************************************
	> File Name: HeapSort.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sat 13 Aug 2016 10:02:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
 

void MinHeap_Sift(int arr[],int pos,int sz)
{
	if(arr == NULL || pos <0 || sz <0)
	{
       return ;
     } 
   int i=pos;
   int j=2*i+1;
   int tmp = arr[i];

   while(j <= sz)
	{
      if(j<sz && arr[j] > arr[j+1])
		{
	     ++j;
	    }
		if(tmp <= arr[j])
		{
		  break;
		}
        else
		{
		  arr[i]=arr[j];
		  i=j;
		  j=2*i+1;
		}
    }
	arr[i]=tmp;
}

void MinHeap_Sort(int arr[],int n)
{
  for(int i=n/2-1;i>=0;--i)
  {
     MinHeap_Sift(arr,i,n-1);
  }

   for(int j=n-1;j>=1;--j)
  {
     std::swap(arr[0],arr[j]);
     MinHeap_Sift(arr,0,j-1);
  }
}

void test_minheapsort()
{
  int arr[10]={9,5,32,57,9,24,3,4,67,88};
  for(int i=0;i<10;++i)
	{
      cout<<arr[i]<<" ";
    }
  cout<<endl;
  MinHeap_Sort(arr,10);
    for(int i=0;i<10;++i)
	{
      cout<<arr[i]<<" ";
    }
  cout<<endl;

}

void MaxHeap_Sift(int arr[],int pos,int sz)
{
  if(arr == NULL || pos <0 || sz <0)
	{
      return ;
    }
	int i=pos;
	int j=2*i+1;
    int tmp = arr[i];
	while(j<=sz)
	{
	   if(j<sz && arr[j]<arr[j+1])
		{
	     ++j;
	    }
		if(tmp>=arr[j])
		{
		  break;
		}
		else
		{
		 arr[i]=arr[j];
		  i=j;
		  j=2*i+1;
		}
	}
	arr[i]=tmp;
}
void MaxHeap_Sort(int arr[],int n)
{
   for(int i=n/2-1;i>=0;--i)
    {
       MaxHeap_Sift(arr,i,n-1);  
    }
	for(int j=n-1;j>=1;--j)
	{
	   std::swap(arr[0],arr[j]);
       MaxHeap_Sift(arr,0,j-1);
	}
}
void test_maxheapsort()
{
    int arr[10]={9,5,32,57,9,24,3,4,67,88};
  for(int i=0;i<10;++i)
	{
      cout<<arr[i]<<" ";
    }
  cout<<endl;
  MaxHeap_Sort(arr,10);
    for(int i=0;i<10;++i)
	{
      cout<<arr[i]<<" ";
    }
  cout<<endl;
}
int main()
{
	test_minheapsort();
	test_maxheapsort();
    return 0;
}

