#include <iostream>
#include "magazine.h"
#include <string>

int main()
{
    Print* p = new Print;
    p->input();
    p->show();

    Magazine* m = new Magazine;
    m->input();
    m->show();

    return 0;
}