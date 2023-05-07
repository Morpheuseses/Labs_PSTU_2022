#include <iostream>
#include "magazine.h"

Magazine::Magazine() :Print()
{
    pages = 0;
}
Magazine::Magazine(std::string n, std::string a, int p) :Print(n, a)
{
    pages = p;
}
Magazine::~Magazine()
{
}
Magazine::Magazine(const Magazine& m)
{
    name = m.name;
    author = m.author;
    pages = m.pages;
}
Magazine& Magazine::operator= (const Magazine& m)
{
    if (&m == this) return *this;
    name = m.name;
    author = m.author;
    pages = m.pages;
    return *this;
}
void Magazine::show()
{
    std::cout << "\nName " << name << std::endl;
    std::cout << "Author " << author << std::endl;
    std::cout << "Pages " << pages << std::endl;
}
void Magazine::input()
{
    std::cout << "Name? "; std::cin >> name;
    std::cout << "Author? "; std::cin >> author;
    std::cout << "Pages? "; std::cin >> pages;
}
int Magazine::getPages()
{
    return pages;
}
void Magazine::setPages(int p)
{
    pages = p;
}