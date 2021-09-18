# Payload-vector-list-full-implementation
## Summary
This is a C++ based project that has an implementation of vector and list data structures with data type Payload. A list of functions for vector and list: 
* push_back, push_front:  pushes elements to the back/front of the vector/linked list
* pop_back, pop_front: pops element from the back/front of the vector/linked list
* back, front: returns back/front element of the vector/linked list
* size, capacity:  returns size/capacity of the vector/linked list
* empty:  returns true or false if vector/linked list is empty or not empty respectively
* print: prints the content of the vector/linked list
* fill_front, fill_back:  fills the vector/linked list at the front/back with a predetermined amount of elemets (z0, z1, z2, z3, ...)
* modify: modifies every element in the vector/list by deleting the first character (z0 would become z)
* modify_it:  modifies every element in the vector/list by appending '!' to the element

### Installation
IDE : Xcode Version 10.2.1 (10E1001) \
Complier: Clang C++ frontend with LLVM as backend \
OS: macOS Catalina version 10.15.7 (19H2) 
### Directory structure
prelab-3.zip --> DSA-lab-2 --> DSA-prelab2 --> user.cpp
### Usage 
Automated run in Xcode
### Description of modules
There are three main structs: \
* Payload 
* Vector -> additionally has VectorIterator struct
* List -> additionally has ListIterator struct and Node struct
