#include "virtual.h"
#include "medicalStudent.h"
// https://www.youtube.com/watch?v=-FUhG98hdLI
#include "base.h"

int main() {
    
    //new polymorphism
    student * students[] = {
        new student("kevin"),
        new student("yosi"),
        new student("yakov"),
        new medicalstudent("jane","dentis"),
        new medicalstudent("lisa","doctor"),
        new medicalstudent("harry","wizzard")
    };

    for(int i = 0 ; i < 6; i++)
    {
        students[i]->print();
    }

    //pure virtual function
    base * array[] = {
        new derived1(),
        new derived2()
    };

    for(int i = 0 ;i< 2; i++)
    {
        array[i]->func();
    }

    for (int i = 0; i < 2; i++)
    {
        delete array[i];
    }
    
    return 0;
}