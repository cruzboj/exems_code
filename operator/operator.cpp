#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class op{
    char * name;
public:
    // Constructor
    op(const char *str)
    {
        name = new char[strlen(str) + 1];
        strcpy(name, str);
    }

    // Copy Constructor
    op(const op &other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    // Destructor
    ~op(){
        delete[] name;
    }

    op operator+(const op &other)
    {
        char *temp = new char[strlen(this->name) + strlen(other.name) + 1];
        strcpy(temp, this->name);
        strcat(temp, other.name);

        op result(temp);
        delete[] temp; // Now safe because we copied temp into result
        return result;
    }

    op &operator=(const op &other)
    {
        if (this != &other)
        {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }

    // Display Function
    void display()
    {
        cout << name << endl;
    }
};

int main(){

    op str1("hello");
    op str2("world");
    str1 = str1 + str2;
    str1.display(); // Output: helloworld
    
    return 0;
}