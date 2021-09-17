#include "myvector.h"

void Vector::push_back(const Payload & x)
{
    if ( sz < cap )
    {
        data[sz++] = x;
        return;
    }
    
    int newcap = cap * 2;
    Payload * newdata = new Payload[newcap];
    
    for ( int i = 0; i < cap; i++ ) newdata[i] = data[i];
    
    delete [] data;
    data = newdata;
    
    cap = newcap;
    
    push_back(x);
}

Vector::Vector(): sz(0), cap(INI_SZ), data(new Payload[INI_SZ]) {}

Vector::~Vector() { delete [] data; }

void Vector::print() const
{
    for ( int i = 0; i < sz; i++ ) data[i].print();
}

void Vector::push_front(const Payload & x)
{
    push_back(x);
    for ( int i = sz - 1; i > 0; i-- ) data[i] = data[i - 1];
    data[0] = x;
}

void Vector::pop_front()
{
    for ( int i = 1; i < sz; i++ ) data[i - 1] = data[i];
    --sz;
}

bool Vector:: empty() const {
    if(sz==0)
        return true;
    else
        return false;
}

Payload Vector::front() const
{
    if(!empty())
        return data[0];
    else
        exit(0);
}
Payload Vector::back() const
{
    if(!empty())
        return data[sz-1];
    else
        exit(0);
}

