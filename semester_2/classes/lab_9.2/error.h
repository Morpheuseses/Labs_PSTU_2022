#pragma once
#include <string>
#include <iostream>
using namespace std;

class error
{
public:
	virtual void what() { };
};
class IndexError : public error
{
protected:
	string msg;
public:
	IndexError() { msg = "Index Error\n"; }
	virtual void what() { cout << msg; }
};
class SizeError : public error
{
protected:
	string msg;
public:
	SizeError() { msg = "size error\n"; }
	virtual void what() { cout << msg; }
};
class MaxSizeError : public SizeError
{
protected:
	string msg_;
public:
	MaxSizeError() { SizeError(); msg = "size>MAXSIZE\n"; }
	virtual void what() { cout << msg << msg_; }
};
class EmptySizeError : public SizeError
{
protected:
	string msg_;
public: 
	EmptySizeError() { SizeError(); msg_ = "List is empty"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError1 : public IndexError
{
protected:
	string msg_;
public:
	IndexError1() { IndexError(); msg_ = "index < 0\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError2 : public IndexError
{
protected:
	string msg_;
public:
	IndexError2() { IndexError();  msg_ = "index > 0\n"; }
	virtual void what() { cout << msg << msg_; }
};