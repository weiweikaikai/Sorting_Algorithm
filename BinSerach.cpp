/*************************************************************************
	> File Name: BinSerach.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sat 13 Aug 2016 07:05:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int  Binserch(int arr[],int left,int right,int key)
{
	if(arr == NULL || right <left)
	{
	  return -1;
	}
	int l= left;
	int r=right;
	
	while(l <= r)
	{
	    int mid = l+((r-l)>>1);
		if(arr[mid] > key)
		{
		  r = mid-1;
		}
		if(arr[mid] > key)
		{
		  l = mid+1;
		}
		else 
			return mid;
	}
    return -1;
}

int   Recusion_Binsearch(int arr[],int left,int right,int key)
{
   if(arr !=NULL && left <=right)
    {
	 int l = left;
	 int r = right;
	 int mid= l+((r-l)>>1);
	 if(arr[mid] > key)
	 {
	    return Recusion_Binsearch(arr,l,mid-1,key);
	 }
	 else if(arr[mid] <key)
	 {
	  return Recusion_Binsearch(arr,mid+1,r,key);
	 }
	 else
	{
	  return mid;
	}
	}
	return -1;
}
void test()
{
  int  arr[10]={0,1,2,3,4,5,6,7,8,9};
  for(int i=0;i<10;++i)
	{
      cout<<arr[i]<<" ";     
    }
    cout<<endl;
      cout<<Recusion_Binsearch(arr,0,9,9);
	     cout<<endl;
	  cout<<Recusion_Binsearch(arr,0,9,0);
	     cout<<endl;
	  cout<<Recusion_Binsearch(arr,0,9,5);
	    cout<<endl;

}

int main()
{
	
    test();
    return 0;
}

