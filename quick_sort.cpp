#include<iostream>
using namespace std;
#include<stdlib.h>

//数组快速排序
void QuickSort_Arr(int *arr, int lhs, int rhs)
{
	if (arr == NULL || lhs >= rhs)
	{
		return;
	}
	int left = lhs;
	int right = rhs;
	int tmp = arr[left];

	while (left != right)
	{
		while (tmp <= arr[right] && right > left)
		{
			--right;
		}
		if (right > left)
		{
			arr[left++] = arr[right];
		}
		while (tmp >= arr[left] && right > left)
		{
			++left;
		}
		if (right > left)
		{
			arr[right--] = arr[left];
		}
	}
	arr[left] = tmp;
	QuickSort_Arr(arr, lhs, left - 1);
	QuickSort_Arr(arr, left + 1, rhs);
}
//尾递归优化快速排序
int Partition(int *arr,int lhs,int rhs) {

    if (arr == NULL || lhs >= rhs) {
        return 0; 
    }
    int key = arr[lhs];
    int l = lhs;
    int r = rhs;
    
    while (l < r) {
          while (r>l && key <= arr[r]) {
               --r;
          }
          if (r>l) {
              arr[l++] = arr[r];
          }
          while(l<r && key >= arr[l]) {
              ++l; 
          }
          if(l<r) {
             arr[r--] = arr[l];
          } 
    }
    arr[l] = key;
    return  l;
}
void QuickSort_Arr_2(int *arr,int lhs,int rhs) {

    if (arr == NULL || lhs >= rhs) {
        return ; 
    }
    int index = 0;
    while (lhs < rhs) {
        index = Partition(arr,lhs,rhs);
        QuickSort_Arr_2(arr,lhs,index-1);
        lhs = index+1;
    }
}


typedef struct node
{
	int data;
	struct node *next;
}*Lnode,node;

void push_back(Lnode &head,int val)
{
	if (head == NULL)
	{
		head = new node;
		head->data = val;
		head->next = NULL;
	}
	else
	{
		Lnode pcur = head;
		while (pcur->next != NULL)
		{
			pcur = pcur->next;
		}
		Lnode tmp = new node;
		tmp->data = val;
		tmp->next = NULL;
		tmp->next=pcur->next;
		pcur->next = tmp;
	}
}
void show(Lnode head)
{
	if (head == NULL)
	{
		return;
	}
	Lnode pcur = head;
	while (pcur != NULL)
	{
		cout << pcur->data << " ";
		pcur = pcur->next;
	}
	cout << endl;
}
void destory(Lnode head)
{
	if (head == NULL)
	{
		return;
	}
	Lnode pcur = head;

	while (pcur != NULL)
	{
		Lnode tmp = pcur->next;
		delete pcur;
		pcur = tmp;
	}
}

void QuickSort_List(Lnode head, Lnode tail)
{
	if (head == tail || head->next == NULL)
	{
		return;
	}
	Lnode pre = head;
	Lnode cur = head->next;
	 //选择头节点的数据作为key数据
    while (cur != tail)
    {
        if (cur->data < head->data)
        {
            pre = pre->next;
            std::swap(pre->data, cur->data);
        }
        cur = cur->next;
    }
	std::swap(pre->data, head->data); 
	QuickSort_List(head, pre); //前闭后开
	QuickSort_List(pre->next, tail);
}


void test_node()
{
	Lnode head = NULL;
	push_back(head, 14);
	push_back(head, 44);
	push_back(head, 554);
	push_back(head, 344);
	push_back(head, 77578);
	push_back(head, 4);
	push_back(head, 8);
	push_back(head, 0);
	push_back(head, 25);
	show(head);
	QuickSort_List(head, NULL);
	show(head);
	destory(head);
}
void test_arr()
{
	int arr[10] = { 1, 6, 0, 99, 77, 23, 56, 22, 12, 8 };
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	//Quick(arr, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
}


bool func(int N)
{
    int *arr = new int[N];
    srand((unsigned int)time(NULL));
    for(int i=0;i<N;++i)
    {
        arr[i]=rand()%100;
    }
    //QuickSort_Arr(arr,0,N-1);
    QuickSort_Arr_2(arr,0,N-1);
    for(int j=0;j<N;++j)
    {
        cout<<arr[j]<<endl;
    }
    delete []arr;
}


int main()
{
	//test_arr();
	//test_node();
	func(10);
	//cout << endl;
    return 0;
}
