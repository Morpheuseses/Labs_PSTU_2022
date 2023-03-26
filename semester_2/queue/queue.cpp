#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
struct Queue
{
	Node* front;
	Node* back;
	int size;
	void init()
	{
		size = 0;
		front = nullptr;
		back = nullptr;
	}
};
void Push(Queue*& queue, int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = nullptr;
	if (queue->size == 0)
	{
		queue->front = tmp;
		queue->back = tmp;
	}
	else
	{
		queue->back->next = tmp;
		queue->back = tmp;
	}
	queue->size++;
}
void Pop(Queue*& queue)
{
	if (queue->size == 0)
	{
		return;
	}
	queue->front = queue->front->next;
	queue->size--;
}

void insertElem(Queue*& queue, int pos, int data)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		Push(tmp, queue->front->data);
		Pop(queue);
	}
	Push(tmp, data);
	int init_size = queue->size;
	for (int i = 1; i <= init_size; i++)
	{
		Push(tmp, queue->front->data);
		Pop(queue);
	}
	queue = tmp;
}
void searchElem(Queue*& queue, int element)
{
	Queue* curr = new Queue;
	curr->init();
	bool elfind = false;
	while (queue->front != nullptr && queue->back != nullptr && !elfind)
	{
		if (queue->front->data == element)
		{
			cout << "Element is here" << endl;
			elfind = true;
		}
		else
		{
			Push(curr, queue->front->data);
			Pop(queue);
		}
		
	}
	while (queue->size != 0)
	{
		Push(curr, queue->front->data);
		Pop(queue);
	}
	queue = curr;
	cout << "There is no element, with such value" << endl;
}
void insertElems(Queue*& queue, int pos, int cnt)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		Push(tmp, queue->front->data);
		Pop(queue);
	}
	int data;
	for (int i = 1; i <= cnt; i++)
	{
		cout << "Enter data of next element: ";
		cin >> data;
		Push(tmp, data);
	}
	int init_size = queue->size;
	for (int i = 1; i <= init_size; i++)
	{
		Push(tmp, queue->front->data);
		Pop(queue);
	}
	queue = tmp;
}
void removElem(Queue*& queue, int pos)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		Push(tmp, queue->front->data);
		Pop(queue);
	}
	Pop(queue);
	int init_size = queue->size;
	for (int i = 1; i <= init_size; i++)
	{
		Push(tmp, queue->front->data);
		Pop(queue);
	}
	queue = tmp;
}
void removElems(Queue*& queue, int pos, int cnt)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		Push(tmp, queue->front->data);
		Pop(queue);
	}
	for (int i = 1; i <= cnt; i++)
	{
		Pop(queue);
	}
	int init_size = queue->size;
	for (int i = 1; i <= init_size; i++)
	{
		Push(tmp, queue->front->data);
		Pop(queue);
	}
	queue = tmp;
}
void showQueue(Queue*& queue)
{
	Node* curr = new Node;
	curr = queue->front;
	cout << "Begin -> ";
	for (int i = 1; i <= queue->size; i++)
	{
		cout << curr->data << " -> ";
		curr = curr->next;
	}
	cout << "End" << endl;
}
int main()
{
	Queue* queue = new Queue;
	queue->init();
	int data, pos, cnt, choice;
	for (int i = 1; i < 5; i++)
	{
		cout << "Enter data of an element: ";
		cin >> data;
		Push(queue, data);
	}
	showQueue(queue);
	cout << "Choose the optiion: " << endl;
	cout << "1 - Push, 2 - Pop, 3 - insertElem, 4 - InsertElems, 5 - remove Elem, 6 - remove Elems, 7 - find element " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "Enter data of element, you want to add: ";
		cin >> data;
		Push(queue, data);
		showQueue(queue);
		break;
	}
	case 2:
	{
		Pop(queue);
		showQueue(queue);
		break;
	}
	case 3:
	{
		cout << "Enter position and data of an element, you want to insert: ";
		cin >> pos >> data;
		insertElem(queue, pos, data);
		showQueue(queue);
		break;
	}
	case 4:
	{
		cout << "Enter position and quantity, you want to insert: ";
		cin >> pos >> cnt;
		insertElems(queue, pos, cnt);
		break;
	}
	case 5:
	{
		cout << "Enter position of element, which will be removed";
		cin >> pos;
		removElem(queue, pos);
		showQueue(queue);
		break;
	}
	case 6:
	{
		cout << "Enter position and quantity of element, which will be removed: ";
		cin >> pos >> cnt;
		removElems(queue, pos, cnt);
		showQueue(queue);
		break;
	}
	case 7:
	{
		int value;
		cin >> value;
		searchElem(queue, value);
		showQueue(queue);
		break;
	}
	}
	return 0;
}