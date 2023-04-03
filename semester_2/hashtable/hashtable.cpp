#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
using namespace std;


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
string Names[]{"Jeremy","John","James","Jonathan","Jeremaya","Johnny","Fedor","Johan"}; // 8
string Surnames[]{"Smith","Adams","Bell","Brooks","Dollar","Evans","Ivanov","Foster","Griffin","Hill"}; // 10
string Street[]{"Prigorodnaya","Wall","Stupid","Apple","Golden Trout Way","Loch Ness Road","Gentle Rain Drive"}; // 7 
string Cities[]{"St.Petersburg","Moscow","London","Boston","BigMall"}; // 5
string getDateofbirth();
string getAdress();

Human createPerson()
{
	Human person;
	person.Name = Names[rand() % 8]+' '+Surnames[rand()%10];
	person.date_of_birth = getDateofbirth();
	person.adress = getAdress();
	return person;
}

struct Hashtable
{
	Human* arr;
	int size;
	void init(int size)
	{
		arr = new Human[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].init();
		}
		this->size = size;
	}
	void put(int index, Human value) 
	{
		int i = index;
		if (arr[i].Name == "none")
		{
			arr[i] = value;
			return;
		}
		i++;
		while (i != size)
		{
			if (arr[i].Name == "none")
			{
				arr[i] = value;
				return;
			}
			i++;
		}
		i = 0;
		while (i != index)
		{
			if (arr[i].Name == "none")
			{
				arr[i] = value;
				return;
			}
			i++;
		}
		cout << "Element did not fit in the table" << endl; 
		// Метод открытой адресации
		

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
				arr[i].showData();
				cout << hashfunc(arr[i].Name)<< endl;
		}
	}
	int find(string key)
	{
		int index = hashfunc(key) % size;
		if (arr[index].Name == key)
		{
			return index;
		}
		int i = index;
		while (i != size - 1) // Hashtable size = 100 
		{
			if (arr[i].Name == key)
				return i;
			i++;
		}
		i = 0;
		while (i != index)
		{
			if (arr[i].Name == key)
				return i;
			i++;
		}
		return 0;
	}
};
string getDateofbirth()
{
	int day = rand() % 31 + 1;
	int month = rand() % 12 + 1;
	int year = 1970 + rand() % 53;
	return to_string(day) + '.' + to_string(month) + '.' + to_string(year);
}
string getAdress()
{
	return Cities[rand() % 5] + ',' + Street[rand() % 7] + " St." + ',' + to_string(rand() % 15);
}
int main()
{
	int size_array = 10;
	srand(time(NULL));

	Hashtable* table = new Hashtable;
	table->init(size_array);

	Human man;

	for (int i = 1; i <= size_array; i++)
	{
		man = createPerson();
		table->put(table->hashfunc(man.Name), man);
	}
	
	table->print();

	/*string key;
	getline(cin,key);
	cout << key+" " << table->find(key) << endl;*/
	delete[] table->arr;
	return 0;
}