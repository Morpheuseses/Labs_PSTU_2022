#include "print.h"
#include <iostream>
#include <string>

Print::Print()
{
    name = "";
    author = "";
}
Print::~Print()
{
}
Print::Print(std::string n, std::string a)
{
    name = n;
    author = a;
}
Print::Print(const Print& p)
{
    name = p.name;
    author = p.author;
}
std::string Print::getName()
{
    return name;
}
std::string Print::getAuthor()
{
    return author;
}
void Print::setName(std::string n)
{
    name = n;
}
void Print::setAuthor(std::string a)
{
    author = a;
}
Print& Print::operator= (const Print& p)
{
    name = p.name;
    author = p.author;
    return *this;
}
void Print::show()
{
    std::cout << "\nName " << name << std::endl;
    std::cout << "Author " << author << std::endl;
}
void Print::input()
{
    std::cout << "Name? "; std::cin >> name;
    std::cout << "Author? "; std::cin >> author;
}