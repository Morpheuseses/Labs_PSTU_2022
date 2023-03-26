#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node* next;
};
struct Stack
{
	Node* top;
	int size;
	void init()
	{
		top = nullptr;
		size = 0;
	}
};
void Push(Stack*& stack, int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = stack->top;
	stack->top = tmp;
	stack->size++;
}
void Pop(Stack*& stack)
{
	if (stack->top == nullptr)
		return;
	stack->top = stack->top->next;
	stack->size--;
}
void showStack(Stack*& stack)
{
	if (stack->top == nullptr)
	{
		cout << "It's empty stack :)" << endl;
		return;
	}
	Node* curr = stack->top;
	cout << "Top -> ";
	for (int i = 1; i <= stack->size; i++)
	{
		cout << curr->data << " -> ";
		curr = curr->next;
	}
	cout << "Bottom " << endl;
}
void insertElem(Stack*& stack, int pos, int data)
{
	Stack* tmp = new Stack;
	tmp->init();
	int init_size = stack->size; // size of element after it was initialized 
	for (int i = 1; i <= init_size - pos + 1; i++)
	{
		Push(tmp, stack->top->data);
		Pop(stack);
	}
	Push(stack, data);
	init_size = tmp->size; // size of tmp stack after it was initialized 
	for (int i = 1; i <= init_size; i++)
	{
		Push(stack, tmp->top->data);
		Pop(tmp);
	}
	delete tmp;
}
void insertElems(Stack*& stack, int pos, int cnt)
{
	Stack* elems = new Stack;
	elems->init();
	int init_size = elems->size;
	int data;
	for (int i = 1; i <= cnt; i++)
	{
		cout << "Enter data of an element: ";
		cin >> data;
		Push(elems, data);
	}
	Stack* tmp = new Stack;
	tmp->init();
	init_size = stack->size;
	for (int i = 1; i <= init_size - pos + 1; i++)
	{
		Push(tmp, stack->top->data);
		Pop(stack);
	}
	init_size = elems->size;
	for (int i = 1; i <= init_size; i++)
	{
		Push(stack, elems->top->data);
		Pop(elems);
	}
	init_size = tmp->size; // size of tmp stack after it was initialized 
	for (int i = 1; i <= init_size; i++)
	{
		Push(stack, tmp->top->data);
		Pop(tmp);
	}
	delete tmp;
	delete elems;
}
void removElem(Stack*& stack, int pos)
{
	Stack* tmp = new Stack;
	tmp->init();
	int init_size = stack->size;
	for (int i = 1; i <= init_size - pos + 1; i++)
	{
		Push(tmp, stack->top->data);
		Pop(stack);
	}
	Pop(tmp);
	init_size = tmp->size;
	for (int i = 1; i <= init_size; i++)
	{
		Push(stack, tmp->top->data);
		Pop(tmp);
	}
	delete tmp;
}
void searchElem(Stack*& stack, int value)
{
	int pos = stack->size;
	Stack* curr = new Stack;
	curr->init();
	elfind = false;
	while (stack->top != nullptr)
	{
		if (stack->top->data == value)
		{
			cout << "Position of element with same value: " << pos << endl;
			elfind = true;
		}
		else
		{
			Push(curr, stack->top->data);
			Pop(stack);
		}
		pos--;
	}
	while (curr->top != nullptr)
	{
		Push(stack, curr->top->data);
		Pop(curr);
	}
	cout << "There no element with the same value " << endl;
}
void removElems(Stack*& stack, int pos, int cnt)
{
	Stack* tmp = new Stack;
	tmp->init();
	int init_size = stack->size;
	for (int i = 1; i < init_size - pos; i++)
	{
		Push(tmp, stack->top->data);
		Pop(stack);
	}
	for (int i = 1; i <= cnt; i++)
	{
		Pop(stack);
	}
	init_size = tmp->size;
	for (int i = 1; i <= init_size; i++)
	{
		Push(stack, tmp->top->data);
		Pop(tmp);
	}
	delete tmp;
}
int main()
{
	Stack* stack = new Stack;
	stack->init();
	int size = 5, data, pos;
	for (int i = 1; i < size; i++)
	{
		cout << "Enter a data of a new element: ";
		cin >> data;
		Push(stack, data);
	}
	showStack(stack);
	int choice;
	cout << "Choose the option:" << endl;
	cout << "1 - push, 2 - pop, 3 - top, 4 - insertElem, 5 - insertElems, 6 - removElem, 7 - removElems, 8 - find element " << endl;
	cin >> choice;
	//system("cls");
	switch (choice)
	{
	case 1:
	{
		cout << "Enter data of the element:";
		cin >> data;
		Push(stack, data);
		showStack(stack);
		break;
	}
	case 2:
	{
		Pop(stack);
		showStack(stack);
		break;
	}
	case 3:
	{
		cout << "Top data = " << stack->top->data << endl;
		showStack(stack);
		break;
	}
	case 4:
	{
		cout << "Enter position and data of the element, you want to add: ";
		cin >> pos >> data;
		insertElem(stack, pos, data);
		showStack(stack);
		break;
	}
	case 5:
	{
		int cnt;
		cout << "Enter position from which element will be inserted and quantity of them: ";
		cin >> pos >> cnt;
		insertElems(stack, pos, cnt);
		showStack(stack);
		break;
	}
	case 6:
	{
		cout << "Enter the position of element you want to remove: ";
		cin >> pos;
		removElem(stack, pos);
		showStack(stack);
		break;
	}
	case 7:
	{
		int cnt;
		cout << "Enter position from which element will be removed and quantity of them: ";
		cin >> pos >> cnt;
		removElems(stack, pos, cnt);
		showStack(stack);
		break;
	}
	case 8:
	{
		int value;
		cout << "Enter value, which you want to find: ";
		cin >> value;
		searchElem(stack, value);
		break;
	}
	default:
		cout << "Oops, something has gone wrong!" << endl;
		break;
	}

	return 0;
}