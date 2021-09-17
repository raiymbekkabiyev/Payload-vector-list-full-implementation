#include "mylist.h"

void List::push_front(const Payload & x)
{
    head = new Node {head, x};
}

void List::pop_front()
{
    if ( !head ) return;
    auto old = head;
    head = head->next;
    delete old;
}

int List::size() const
{
    int c = 0;
    for ( Node * p = head; p != nullptr; p = p->next ) ++c;
    return c;
}

void List::print() const
{
    for ( Node * p = head; p != nullptr; p = p->next ) p->a.print();
}

void List::push_back(const Payload & x)
{
    Node ** q = &head;
    for ( Node * p = head; p != nullptr; p = p->next ) q = &p->next;
    *q = new Node {nullptr, x};
}

void List::pop_back()
{
    if ( !head ) return;
    
    Node ** q = &head;
    for ( Node * p = head; p->next != nullptr; p = p->next ) q = &p->next;
    
    delete *q;
    *q = nullptr;
}

Payload & List::operator[](int i)const
{

        int c = 0;
        for ( Node * p = head; p != nullptr; p = p->next )
            if ( c++ == i ) return p->a;
        
        static Payload bad_access("range_error");
        return bad_access;

  
}


bool List:: empty() const {
    if(size()==0)
        return true;
    else
        return false;
}

Payload List:: front() const{
    if(!empty())
        return head->a;
    else
        exit(0);
}
Payload List:: back() const{
    if(!empty())
    {
        Node * p = head;
        while(p->next != nullptr){
            p = p->next;
        }
        return p->a;
    
    }
    else
        exit(0);
}
