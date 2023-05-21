#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
using namespace std;

int collisions = 0;

struct Human
{
	string Name;
	string date_of_birth;
	string adress;

	void init()
	{
		Name = "none";
		date_of_birth = "none";
		adress = "none";
	}
	void showData()
	{
		cout << "-------------------------------------" << endl;
		cout << this->Name << endl;
		cout << this->date_of_birth << endl;
		cout << this->adress << endl;
		cout << "-------------------------------------" << endl;
	}
};
string Names[]{ "Jeremy","John","James","Jonathan","Jeremaya","Johnny","Fedor","Johan" }; // 8
string Surnames[]{ "Smith","Adams","Bell","Brooks","Dollar","Evans","Ivanov","Foster","Griffin","Hill" }; // 10
string Street[]{ "Prigorodnaya","Wall","Stupid","Apple","Golden Trout Way","Loch Ness Road","Gentle Rain Drive" }; // 7 
string Cities[]{ "St.Petersburg","Moscow","London","Boston","BigMall" }; // 5
string getDateofbirth();
string getAdress();

Human createPerson()
{
	Human person;
	person.Name = Names[rand() % 8] + ' ' + Surnames[rand() % 10];
	person.date_of_birth = getDateofbirth();
	person.adress = getAdress();
	return person;
}

struct ListElem
{
	ListElem* next = nullptr;
	Human data;

	void push_back(ListElem* arr_i, Human data)
	{
		if (arr_i->next == nullptr)
		{
			arr_i->data = data;
			return;
		}
		ListElem* tmp = new ListElem;
		tmp->data = data;
		tmp->next = nullptr;
		ListElem* curr = this;

		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = tmp;
	}

	void remove(int pos)
	{
		ListElem* curr = new ListElem;
		curr = this;
		for (int i = 0; i < pos - 1; i++)
		{
			curr = curr->next;
		}
		curr->next = curr->next->next;
	}

};


struct Hashtable
{
	ListElem** arr;
	int size;
	void init(int size)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = new ListElem[size];
		}
		this->size = size;
	}
	void put(int index, Human value)
	{
		// method of separate chaining
		arr[index]->push_back(arr[index], value);
		if (arr[index]->next != nullptr) { collisions++; }
	}
	int hashfunc(string key)
	{
		int hashcode = 0;
		for (int i = 0; i < key.length(); i++)
		{
			hashcode += int((unsigned char)key[i]);
		}
		return hashcode % size;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
		//	if (arr[i]->next != nullptr)
		
				ListElem* tmp = arr[i];
				while (tmp->next != nullptr)
				{
					tmp->data.showData();
					cout << hashfunc(tmp->data.Name) << endl;
					tmp = tmp->next;
				}
			
		}
	}
	int find(string key)
	{
		int index = hashfunc(key);
		int pos = 0;
		ListElem* tmp = arr[index];

		while (tmp != nullptr)
		{
			if (tmp->data.Name == key)
				return pos;
			tmp = tmp->next;
			pos++;
		}
		return -1;
	}
	void remove(string key)
	{
		int pos = find(key);
		int index = hashfunc(key);
		if (pos != -1)
		{
			arr[index]->remove(pos);
		}
	}
};


string getDateofbirth()
{
	int day = rand() % 31 + 1;
	int month = rand() % 12 + 1;
	int year = 1970 + rand() % 53;
	if (month / 10 < 1)
	{
		return to_string(day) + '.' + '0' + to_string(month) + '.' + to_string(year);
	}
	if (day / 10 < 1)
	{
		return '0' + to_string(day) + '.' + to_string(month) + '.' + to_string(year);
	}
	if (day / 10 < 1 && month / 10 < 1)
	{
		return '0' + to_string(day) + '.' + '0' + to_string(month) + '.' + to_string(year);
	}
	return to_string(day) + '.' + to_string(month) + '.' + to_string(year);
}
string getAdress()
{
	return Cities[rand() % 5] + ',' + Street[rand() % 7] + " St." + ',' + to_string(rand() % 15);
}
void fillTable(Hashtable*& table, int size)
{
	Human man;

	for (int i = 1; i <= size; i++)
	{
		man = createPerson();
		table->put(table->hashfunc(man.Name), man);
	}
}
int main()
{
	srand(time(NULL));

	Hashtable* table = new Hashtable;
	table->init(40);

	fillTable(table, 40);

	table->print();

	string key;

	getline(cin, key);
	cout << key + " " << table->find(key) << endl;

	delete[] table->arr;
	delete table;

	cout << collisions << endl;



	cout << "next?" << endl;
	getline(cin, key);
	if (key != "1") { return 0; }
	system("cls");

	table = new Hashtable;
	table->init(75);

	collisions = 0;
	fillTable(table, 75);

	table->print();

	getline(cin, key);
	cout << key + " " << table->find(key) << endl;

	delete[] table->arr;
	delete table;

	cout << collisions << endl;



	cout << "next?" << endl;
	getline(cin, key);
	if (key != "1") { return 0; }
	system("cls");

	table = new Hashtable;
	table->init(90);

	collisions = 0;
	fillTable(table, 90);

	table->print();

	getline(cin, key);
	cout << key + " " << table->find(key) << endl;

	cout << collisions << endl;

	cout << "delete key?" << endl;
	getline(cin, key);
	table->remove(key);

	table->print();

	delete[] table->arr;
	delete table;

	return 0;
}