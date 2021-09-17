#pragma once

#include <string>

using std::string;


struct Payload
{
    static int counter, dead;
    int id;
    string name;
    
    Payload(string n = "") : id(++counter), name(n) { say_born(); }
    ~Payload() { say_die(); ++dead; }
    void print() const;
    
    Payload(const char * n) : Payload(string(n)) {}
    Payload(const Payload & x) : id(++counter), name(x.name) { say_born(); }
    Payload(Payload && x) : id(++counter), name(x.name) { say_born(); }
    void operator=(const Payload & x) { name = x.name; }
    
    void say_born() const;
    void say_die() const;
};


struct Leaks
{
    ~Leaks();
};

