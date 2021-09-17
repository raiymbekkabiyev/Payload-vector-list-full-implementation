#include "payload.h"


struct Vector
{
    int sz, cap;
    Payload * data;
    
    static const int INI_SZ = 1;
    
    void push_back(const Payload & x);
    void pop_back() { --sz; }
    
    void push_front(const Payload & x);
    void pop_front();
    
    int size() const { return sz; }
    int capacity() const { return cap; }
    
    Vector();
    ~Vector();
    
    void print() const;
    
    //In-lab-2
    bool empty() const;
    Payload front() const;
    Payload back() const;
    
    Payload & operator[](int i) const{
        if(i>=0 && i<sz)
            return data[i];
        else
            exit(0);
        
    }
};


