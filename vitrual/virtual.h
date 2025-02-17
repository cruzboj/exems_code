#pragma once

#include <iostream>
#include <cstring>

class student {
    public:
        char * name;
        
        student(const char* name);
        virtual ~student();
        virtual void print() {std::cout << name << std::endl;}
        
};

student::student(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
}
student::~student(){
    delete[] name;
}