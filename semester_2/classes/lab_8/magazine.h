#pragma once 
#include "print.h"

class Magazine : public Print 
{
protected:
    int pages;
public:
    Magazine();
    ~Magazine();
    Magazine(std::string, std::string, int);
    Magazine(const Magazine&);
    void show();
    void input();
    int getPages();
    void setPages(int);
    Magazine& operator = (const Magazine& );
};