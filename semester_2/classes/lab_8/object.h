#pragma once
#include "event.h"

class Object
{
public:
    Object();
    virtual void show() = 0;
    virtual void input() = 0;
    virtual void HandleEvent(const TEvent &e) = 0;
    virtual ~Object();
};
