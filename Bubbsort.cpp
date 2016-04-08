//√∞≈›≈≈–Ú
void Bubbsort_Arr(int *arr, int n)
{
	if (arr == NULL)
	{
		return;
	}
	bool flag = true;
	for (int i = 0; i < n - 1 && flag; ++i)
	{
		flag = false;
		for (int j = 0; j < n - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
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

//µ•¡¥±Ì√∞≈›≈≈–Ú
void  Bubbsort(Lnode head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	Lnode pcur = head;
	Lnode tail = NULL;

	for (; pcur->next != NULL; pcur = pcur->next)
	{
		Lnode plow = head;
		Lnode pfast = head->next;
		bool flag = true;
		for (; pfast != tail; pfast = pfast->next,plow = plow->next)
		{
			if (plow->data > pfast->data)
			{
				std::swap(pfast->data, plow->data);
				flag = false;
			}
			if (flag)
			{
				return;
			}
			
		}
		tail = plow;
	}
}


