#include <iostream>

// constractors & deconstractors
class example{
    private:
        int x;
        static int count;       //it means that this variable is shared between all objects of this class || 1:32:00 lecture 2
    public:
        example();              // defult constractor
        example(example &ex);   // copy constractor
        ~example();             // deconstractor

        void metoda();          //metoda x.methoda(b) || x.operator+(b)
        void func();            //func func(x,b);  || operator+(x,b)
};

class example_child : public example{
    private:
        int y;
    public:
        example_child();        // defult constractor
        ~example_child();       // deconstractor
};

int main()
{

    //<&>refrence - better then <*>pointers take less memory 
    int i = 8;
    int &j = i;
    int x = i;
    i = 5; // j =5 , x = 8
    j++; // i = j = 6

    // 31:46 lecture 1
    const int max1 = 100;
    //int * max2 = &max; // error
    int const * max2 = &max1; // ok
    int k;
    max2 = &k; // ok

    //if max3 is not const it will be ok
    int max3 = 100;
    // int * max4 = &max3; // ok
    int const *max4 = &max3; // ok
    int k;
    max4 = &k; // ok

    //---------------------------------------------------
    //class example
    example ex;
    static_cast<example>(example());      // static cast is used to convert one data type to another in compile time

    example_child ex_child;
    example* ex_ptr = dynamic_cast<example*>(&ex_child); // dynamic cast is used to convert from child to father on runtime
    if (ex_ptr) {
        ex = *ex_ptr;
    }

    return 0;
}