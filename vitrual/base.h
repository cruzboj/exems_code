#pragma once

#include <iostream>
#include <cstring>

//abstract class
class base{
    public:
        virtual void func() = 0; //pure virtual function
        // {
        //     std::cout << "base func()" << std::endl;
        // }
        virtual ~base() = 0;
};

base::~base(){std::cout << "base destructor" << std::endl;}

class derived1 : public base{
    public:
        void func()
        {
            std::cout << "derived1 overriding func()" << std::endl;
        }
        ~derived1(){std::cout << "derived1 destructor" << std::endl;}
};

class derived2 : public base{
    public:
        void func()
        {
            std::cout << "derived2 overriding func()" << std::endl;
        }
        ~derived2(){std::cout << "derived2 destructor" << std::endl;}
};