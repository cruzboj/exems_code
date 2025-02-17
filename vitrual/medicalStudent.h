#pragma once
#include "virtual.h"

class medicalstudent : public student{
    public:
        char * speciality;
        
        medicalstudent(const char * name ,const char * speciality);
        ~medicalstudent();
        void print(){std::cout << name << " :" << speciality << std::endl;}
        
};

medicalstudent::medicalstudent(const char* name, const char* speciality)
    : student(name) {
    this->speciality = new char[strlen(speciality) + 1];
    strcpy(this->speciality, speciality);
}

medicalstudent::~medicalstudent(){
    delete[] speciality;
}