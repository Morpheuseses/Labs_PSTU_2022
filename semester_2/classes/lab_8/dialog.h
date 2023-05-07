#ifndef DIALOG_H
#define DIALOG_H

#include "event.h"

#include "list.h"
#include "event.h"

class Dialog : public List
{
protected:
	int EndState;
public:
	Dialog();
	~Dialog(){};
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent (TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();

};

#endif // DIALOG_H