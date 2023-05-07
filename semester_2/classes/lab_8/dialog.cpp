#include <iostream>
#include "dialog.h"
#include "event.h"
using namespace std;

Dialog::Dialog() : List()
{
	EndState = 0;
}
void Dialog::GetEvent(TEvent& event)
{
	std::string OpInt = "m+-szq";
	std::string s;
	std::string param;

	char code;
	cout << '>';
	cin >> s; code = s[0];
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break; // make
		case '+': event.command = cmAdd; break; // add
		case '-': event.command = cmDel; break; // delete
		case 'q': event.command = cmQuit; break; // quit 
		case 's': event.command = cmShow; break; // elements
		case 'z': event.command = cmGet; break; // names 
		}
		if (s.length() >= 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.param = A;
		}
		else event.what = evNothing;
	}
}
int Dialog::Execute() 
{
	TEvent event;
	do
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} 
	while (!Valid());
	return EndState;
}

int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}
void Dialog::EndExec()
{
	EndState = 1;
}
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake: // переделать 

			ClearEvent(event);
			break;
		case cmAdd: // переделать
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del();
			ClearEvent(event);
			break;
		
		case cmShow:
			show();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		default: List::HandleEvent(event);
		};
	}
	
}
