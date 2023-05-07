#include <iostream>
#include ".\stack.h"

int main()
{
    Stack s;
    s.push(3);
    s.push(9);
    s.push(6);
    std::cout << "Stack Init: ";
    std::cout << s << std::endl;
    s.push(4);
    std::cout << "Stack push data: ";
    std::cout << s << std::endl;
    s.add(5, 3);
    std::cout << "Stack add element on n pos: ";
    std::cout << s << std::endl;
    s.del(2);
    std::cout << "Stack delete element in n pos: ";
    std::cout << s << std::endl;
    return 0;
}