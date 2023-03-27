#include<iostream>

struct ListElem
{
	int data;
	ListElem* next;
	ListElem* prev;
};

ListElem* createList(int n)
{
	ListElem* start = new ListElem;
	ListElem* curr, * prev;
	start->prev = nullptr;
	std::cout << "Enter a data of an element: ";
	std::cin >> start->data;
	prev = start;
	for (int i = 0; i < n - 1; i++)
	{
		ListElem* curr = new ListElem;
		std::cout << "Enter a data of an element: ";
		std::cin >> curr->data;
		curr->next = nullptr;
		curr->prev = prev;
		prev->next = curr;
		prev = curr;
	}
	return start;
}

void addElem(ListElem*& list, int pos, int data, int& size)
{
	if (pos == 1)
	{
		ListElem* start = new ListElem;
		start->data = data;
		start->prev = nullptr;
		start->next = list;
		list->prev = start;
		list = start; // if it will work, it will be cool
	}
	/*if (pos == size)
	{
		ListElem* curr = list;
		for (int i = 1; i < size; i++)
		{
			curr = curr->next;
		}
		ListElem* end = new ListElem;
		end->data = data;
		end->next = nullptr;
		end->prev = curr;
		curr->next = end;
	}*/
	if (pos != 1)
	{
		ListElem* elem = new ListElem;
		elem->data = data;
		ListElem* curr = list;
		for (int i = 1; i < pos - 1; i++)
			curr = curr->next;

		elem->prev = curr;
		elem->next = curr->next;
		curr->next = elem;

	}
	size++;
}
void addElems(ListElem*& list, int pos, int& size, int cnt)
{

	ListElem* curr, * prev, * start = new ListElem;
	std::cout << "Enter data of the next element: ";
	std::cin >> start->data;
	start->prev = nullptr;
	prev = start;
	for (int i = 1; i < cnt; i++)
	{
		curr = new ListElem;
		std::cout << "Enter a data of the next element: ";
		std::cin >> curr->data;
		curr->next = nullptr;
		curr->prev = prev;
		prev->next = curr;
		prev = curr;
	}
	if (pos == 1)
	{
		list->prev = prev;
		list = start;
	}
	/*if (pos == size)
	{
		ListElem* curr = list;
		for (int i = 1; i <= size; i++)
		{
			curr = curr->next;
		}
		curr->next = start;
		start->prev = curr;
		prev->next = nullptr;
	}*/
	if (pos != 1 && pos != size)
	{
		ListElem* curr = list;
		for (int i = 1; i < pos - 1; i++)
		{
			curr = curr->next;
		}
		prev->next = curr->next;
		curr->next->prev = prev;
		curr->next = start;
	}
	size += cnt;
}
void searchElem(ListElem* list, int value)
{
	int pos = 1;
	ListElem* curr = list;
	while (curr->next != nullptr)
	{
		if (curr->data == value)
		{
			std::cout << "Position of the element, you look for: " << pos << std::endl;
			return;
		}
		curr = curr->next;
		pos++;
	}
	std::cout << "There is no element with such value" << std::endl;
}
void removElem(ListElem*& list, int pos, int& size)
{
	if (pos == 1)
	{
		list = list->next;
	}
	if (pos == size)
	{
		ListElem* curr = list;
		for (int i = 1; i < size; i++)
		{
			curr = curr->next;
		}
		curr->next = nullptr;
	}
	if (pos != size && pos != 1)
	{
		ListElem* curr = list;
		for (int i = 1; i < pos - 1; i++)
		{
			curr = curr->next;
		}
		curr->next = curr->next->next;
		curr->next->prev = curr;
	}
	size--;
}
void removElems(ListElem*& list, int pos, int& size, int cnt)
{
	if (cnt > size)
	{
		list->next = nullptr;
	}
	if (pos == 1)
	{
		ListElem* curr = list;
		for (int i = 1; i <= cnt; i++)
		{
			curr = curr->next;
		}
		curr->prev = nullptr;
		list = curr;
	}
	if (pos != 1)
	{
		ListElem* curr = list, * pend; // pend - pointer to "tail" of list
		for (int i = 1; i < pos - 1; i++)
		{
			curr = curr->next;
		}
		pend = curr;
		for (int i = 1; i <= cnt; i++)
		{
			pend = pend->next;
		}
		curr->next = pend->next;
		pend->prev = curr;
	}
	size -= cnt;
}
void showList(ListElem* list, int size)
{
	std::cout << "Here your list" << std::endl;
	std::cout << "Begin <-> ";
	ListElem* curr = list;
	std::cout << curr->data << " <-> ";
	for (int i = 1; i < size; i++)
	{
		curr = curr->next;
		std::cout << curr->data << " <-> ";
	}
	std::cout << "End" << std::endl;

}
int main()
{
	int size = 5; // quantity of elements in the list, we will create
	ListElem* list = new ListElem;
	list = createList(size);
	showList(list, size);
	int pos;
	std::cout << "Enter a position of an element you want to add: ";
	std::cin >> pos;
	int data;
	std::cout << "Enter data of the element, you add: ";
	std::cin >> data;
	addElem(list, pos, data, size);
	showList(list, size);
	int cnt;
	std::cout << "Enter pos of the element from which you want to add, and count of this elements: ";
	std::cin >> pos >> cnt;
	addElems(list, pos, size, cnt);
	showList(list, size);
	std::cout << "Enter position of the element, which will bw deleted: ";
	std::cin >> pos;
	removElem(list, pos, size);
	showList(list, size);
	std::cout << "Enter position of an element from which element will be deleted and count of them: ";
	std::cin >> pos >> cnt;
	removElems(list, pos, size, cnt);
	showList(list, size);
	std::cout << "Enter the value of the element you want know position of: ";
	std::cin >> data;
	searchElem(list, data);
	showList(list, size);
	return 0;
}