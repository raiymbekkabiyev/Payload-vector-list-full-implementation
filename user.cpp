#include <iostream>
#include <chrono>
#include "payload.h"
#include "myvector.h"
#include "mylist.h"
#include "string"
using std::cout;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

template <class C> void show(const C & v)
{
    cout << "size/cap: " << v.size() << '/' << v.capacity() << ": ";
    v.print(); cout << '\n';
}
template <class C> void fill_back(C & v, int n)
{
    for(int i=0; i<n; i++)
    {
        v.push_back(("z"+std::to_string(i)));
    }
}
template <class C> void fill_front(C & v, int n)
{
    for(int i=0; i<n; i++)
    {
        v.push_front(("z"+std::to_string(i)));
    }
}
template <class C> void remove_back(C & v)
{
    int size = v.size();
    for (int i=0; i<size; i++)
    {
        v.pop_back();
    }
}
template <class C> void remove_front(C & v)
{
    int size = v.size();
    for (int i=0; i<size; i++)
    {
        v.pop_front();
    }
}
template <class C> void modify(C & v)
{
    for (int i=0; i<v.size(); i++)
    {
        v[i].name.erase(0,1);
    }
}
template <class C> void print(C & v)
{
    //    for(int i=0; i<size; i++){
    //        v[i].print();
    //    }
    int size = v.size();
    cout<<"print: "<<size<<" items ";
    int cnt=0;
    while(cnt!=size){
        cout<<v[cnt].name<<" ";
        cnt++;
    }
    cout<<std::endl;
}

//Task 2: Implement: void reverse<Src,Dest>(const Src & src, Dest & dest);
template <class Src, class Dest> void reverse(const Src & src, Dest & dest)
{
    for (int i=0; i<src.size(); i++) {
        if(src.empty())
            exit(0);
        else
            dest.push_front(src[i]);
    }
}

//TASK 3 implement: const Payload * find_in<Container>(const Container & c, std::string name);
template <class Container> const Payload* find_in(const Container & c, std::string name){
    int size =c.size();
    for(int i=0; i<size; i++)
    {
        if(c[i].name==name)
            return &c[i];
    }
        cout<<name<<" was not found\n";
        exit(0);
}

template <class Container> void run(string message, int n)
{
    cout << message << '\n';
    Container c;
    fill_back(c, n); show(c);
    modify(c); show(c);
    modify(c); show(c);
    modify(c); show(c);
    remove_back(c); show(c);
    fill_front(c, n); show(c);
    print(c);
    remove_front(c); show(c);
    cout << '\n';
}

int main()
{
    //Pre-lab2
//    run<Vector>("Vector", 10);
//    run<List>("List", 10);
    
    //IN-LAB-2
    //TASK 1 test
    Vector v;
    List l;
    if(!v.empty())
        cout<<"the container is not empty\n";
    else
        cout<<"the container is empty\n";
    
    if(!l.empty())
        cout<<"the container is not empty\n";
    else
        cout<<"the container is empty\n";
    //Expected output: both containers are empty
    //now I want to test if it can detect that the container is not empty
    v.push_back("e1");
    if(!v.empty())
        cout<<"the container is not empty\n";
    else
        cout<<"the container is empty\n";
    l.push_front("e1");
    if(!l.empty())
        cout<<"the container is not empty\n";
    else
        cout<<"the container is empty\n";
    
    
    //testing front and back functions
    v.push_front("e2"); v.push_front("e3");
    l.push_front("e2"); l.push_front("e3");
    cout<<"vector items: "; v.print(); cout<<std::endl;
    cout<<"front:";v.front().print(); cout<<std::endl;//expected output is e3
    cout<<"back:"; v.back().print(); cout<<std::endl;//expected output is e1
    cout<<"list items: "; l.print(); cout<<std::endl;
    cout<<"front:"; l.front().print();  cout<<std::endl; //expected output is e3
    cout<<"back:"; l.back().print(); cout<<std::endl;  //expected output is e1
    
    //TASK 2 test
    Vector reversed_v1; //var for destination container
    List reversed_l1;   //var for destination container
    reverse(l, reversed_v1); reversed_v1.print(); cout<<std::endl;//expected output e1, e2, e3
    reverse(v, reversed_l1); reversed_l1.print();cout<<std::endl; //expected output e1, e2, e3
    
    //TASK 3 test
    find_in(v, "e3")->print();cout<<std::endl;
    
    //TASK 4 test
//  CHRONO TEST
    Vector v_chrono;
    List l_chrono;
    fill_front(v_chrono, 10000);
    fill_front(l_chrono, 10);

    auto t1 = high_resolution_clock::now();
    find_in(l_chrono, "z9");
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> result_t = t2 - t1;
    cout << result_t.count() << "ms\n";
    return 0;
    
}
