

#include "payload.h"

struct Node
{
    Node * next;
    Payload a;
};

struct List
{
    Node * head;
    void push_front(const Payload &);
    void pop_front();
    
    void push_back(const Payload & x);
    void pop_back();
    
    List(): head(nullptr) {}
    ~List() { while (head) pop_front(); }
    
    int size() const;
    void print() const;
    int capacity() const { return size(); }
    
    Payload & operator[](int i)const;
    
    bool empty() const;
    Payload front() const;
    Payload back() const;
};

