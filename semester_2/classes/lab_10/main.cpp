#include "pair.h"
#include "file_work.h"
#include <iostream>
using namespace std;

int main()
{
	Pair p, p1, p2, p3;
	int k, c;
	char file_name[30];
	do
	{
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete record from file";
		cout << "\n4. Add record to file";
		cout << "\n5. Change record in file";
		cout << "\n6. Delete records less than given ";
		cout << "\n7. Add const to records ";
		cout << "\n8. Add K elements from element pos";
		cout << "\n0. Exit" << endl;
		cin >> c;
		switch (c)
		{
		case 1: 
			cout << "file name?"; 
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "Can't make file";
			break;
		case 2: 
			cout << "file name?"; 
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "Empty file\n";
			if (k < 0) cout << "Can't read file\n";
			break;
		case 3: 
			cout << "file name?"; 
			cin >> file_name;
			int nom; cout << "nom?"; cin >> nom;
			k = del_file(file_name, nom);
			if (k < 0) cout << "Can't read file";
			break;
		case 4: 
			cout << "file name?";
			cin >> file_name;
			cout << "nom?"; 
			cin >> nom;
			cout << "New pair:";
			cin >> p1;
			k = add_file(file_name, nom, p1);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = add_end(file_name, p1);
			break;
		case 5: 
			cout << "file name?";
			cin >> file_name;
			cout << "nom?"; cin >> nom;
			cout << "New pair:";
			cin >> p2;
			k = change_file(file_name, nom, p2);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		case 6:
			cout << "Compare Pair?";
			cin >> p3;
			k = delete_lessThan(file_name, p3);
			if (k == 0) cout << "No records changed" << endl;
			if (k > 0) cout << k << " records changed" << endl;
			break;
		case 7:
			cout << "const?"; 
			int con;
			cin >> con;
			k = addConst(file_name, con);
			if (k == 0) { cout << "No records changed"; }
			break;
		case 8:
			int pos, count;
			cout << "K?";
			cin >> count;
			cout << "Pos?";
			cin >> pos;
			addRecords(file_name, count, pos);
			break;
		}
		

	} while (c != 0);

	return 0;
}