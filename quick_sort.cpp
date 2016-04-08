
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

//单链表快速排序


void QuickSort_List(Lnode head,Lnode tail)
{
	if (head == tail || head->next == NULL)
	{
		return;
	}
	Lnode cur = head->next;
	Lnode pre = head;

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
	QuickSort_List(head, pre);
	QuickSort_List(pre->next, tail);
}
