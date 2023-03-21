#include<iostream>
using namespace std; 


struct ListElem
{
	ListElem* next;
	ListElem* prev;
	int value;
};

ListElem* createList(int n)
{
	ListElem* start;
	ListElem* p, *r;
	start = new ListElem;
	cin >> start->value;
	start->next = nullptr;
	start->prev = nullptr;
	p = start;
	for (int i = 0; i < n - 1; i++)
	{
		r = new ListElem;
		cin >> r->value;
		r->next = nullptr;
		r->prev = p;
		p->next = r;
		p = r;
	}
	return start;
}
void addElem(ListElem* list, int elem, int pos, int& size)
{
	size++;
	ListElem* px = list, *pend;
	for (int i = 1; i < pos - 1; i++)
	{
		px = px->next;
	}
	pend = px->next;
	ListElem* tmp = new ListElem;
	if (pos == 1)
	{
		tmp->prev = nullptr;
		tmp->value = elem;
	}
	else
	{
		tmp->prev = px;
		px->next = tmp;
	}
	tmp->next = pend;
	
}
void deleteElem(ListElem* list, int pos, int& size)
{
	size--;
	ListElem* px = list, *pend;
	for (int i = 1; i < pos - 1; i++)
	{
		px = px->next;
	}
	pend = px->next->next;
	px->next = pend;
}
void addElems(ListElem* list, int pos, int& size)
{
	cout << "Enter count of elements you want to add:";
	int cnt;
	cin >> cnt;
	size += cnt;
	ListElem* px = list;
	for (int i = 1; i < pos - 1; i++)
	{
		px = px->next;
	}
	ListElem* next = px->next;
	ListElem* prev = px;
	ListElem* tmp = new ListElem;
	for (int i = 0; i < cnt; i++)
	{
		cout << "Enter next element: ";
		int value;
		tmp = new ListElem;
		cin >> value;
		tmp->value = value;
		tmp->prev = prev;
		prev->next = tmp;
		prev = tmp;
	}
	tmp->next = next;
}
void deleteElems(ListElem* list, int pos, int& size)
{
	cout << "Enter count of elements you want to delete:";
	int cnt;
	cin >> cnt;
	size -= cnt;
	ListElem* px = list;
	for (int i = 1; i < pos - 1; i++)
	{
		px = px->next;
	}
	ListElem* pend = px;
	for (int i = 1; i <= cnt; i++)
	{
		pend =pend->next;
	}
	px->next = pend->next;
	pend->prev = px;
}
int main()
{
	int size = 5;
	cout << "Enter list elements values: " << endl;
	ListElem* list = createList(size);
	addElem(list, 1, 3, size);
	deleteElem(list, 4, size);
	addElems(list, 2, size);
	ListElem* tmp = list;
	for (int i = 1; i <= size; i++)
	{
		cout << tmp->value << " ";
		if (tmp->next!=nullptr)
			tmp = tmp->next;
	}
	cout << endl;
	deleteElems(list, 2, size);
	tmp = list;
	for (int i = 1; i <= size; i++)
	{
		cout << tmp->value << " ";
		if (tmp->next != nullptr)
			tmp = tmp->next;
	}
	cout << endl;
	delete[] list;
	return 0;
}