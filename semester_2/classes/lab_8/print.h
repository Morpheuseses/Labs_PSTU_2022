#pragma once 
#include "object.h"
#include <string>

class Print : public Object
{
protected:
    std::string name;
    std::string author;
public:
    Print();
    virtual ~Print();
    void show();
    void input();
    void HandleEvent(const TEvent& e);
    Print(std::string, std::string);
    Print(const Print&);
    std::string getName();
    std::string getAuthor();
    void setName(std::string n);
    void setAuthor(std::string a);
    Print& operator= (const Print&);

};
