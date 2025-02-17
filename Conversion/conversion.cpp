#include <iostream>
#include <string>

using namespace std;

//lecture 5 1:09:00
class employee{
    protected: //we can access them from the child classes
        string name;
        short year_born;
        short department;
        int salary;
        //employee * next; //pointer to the next employee if you wnat to use linked list
    
    public:
        employee(string n, short y, short d, int s) : name(n), year_born(y), department(d), salary(s) {};
        virtual void give_raise(int amount){
            // doint nothing to keep use of the employee object in the main
            // if you dont want to make a object of the base class then make the function pure virtual
            // virtual void give_raise(int amount) = 0;
        }

        virtual void display() {};

        virtual ~employee() {} // Virtual destructor for proper cleanup
};

class Manager : public employee{
    private:
        string degrees;

    public:
        Manager(string n, short y, short d, int s, string deg) : employee(n, y, d, s), degrees(deg) {};
        void display()
        {
            cout << "Manager Information:\n"
                 << "---------------------\n"
                 << "Name: " << name << "\n"
                 << "Year Born: " << year_born << "\n"
                 << "Department: " << department << "\n"
                 << "Salary: $" << salary << "\n"
                 << "Degrees: " << degrees << "\n"
                 << "---------------------\n\n";
        }

        void give_raise(int amount) override
        {
            salary += amount;
            salary += 0.1 * salary;
        }
};

class salesman : public employee{
    private:
        double commission_rate;    
    public:
        salesman(string n, short y, short d, int s, double c) : employee(n, y, d, s), commission_rate(c) {};
        void display()
        {
            cout << "Employee Information:\n"
                 << "---------------------\n"
                 << "Name: " << name << "\n"
                 << "Year Born: " << year_born << "\n"
                 << "Department: " << department << "\n"
                 << "Salary: $" << salary << "\n"
                 << "Commission Rate: " << commission_rate * 100 << "%\n"
                 << "---------------------\n\n";
        }

        void give_raise(int amount) override
        {
            salary += amount;
            salary += commission_rate * salary;
        }
};

int main()
{
    employee p1("John", 1970, 3, 50000) , *pE;
    Manager p2("Jane", 1975, 3, 60000, "MSc"), *pM;
    salesman p3("Jim", 1980, 3, 70000, 0.1) , *pS;

    //father can be assigned to child but not the other way around
    p1 = p2;
    p1 = p3;

    p1.display();
    p2.display();
    p3.display();

    // p2 = p1; //error
    // p3 = p1; //error
    // p3 = p2; //error
    // p2 = p3; //error
    
    //[pointers *pE, *pEn, *pS]
    // pM = &p1;                           //error
    pE = &p2;                           //ok
    // pE = *pE;                           //error

    p2 = *(Manager*)pE;                 //ok
    p2 = *static_cast<Manager*>(pE);    //safer then normal cast


    //arrays of calsses
    employee *Dept[100];
    Dept[0] = new Manager("yosi", 1975, 3, 60000, "MSc");
    Dept[1] = new salesman("jeff", 1980, 3, 70000, 0.1);
    
    Dept[0]->give_raise(1000);
    Dept[1]->give_raise(1000);
    
    for(int i = 0; i < 2; i++)
    {
        Dept[i]->display();
    }

    for (int i = 0; i < 2; i++)
    {
        delete Dept[i];
    }
    
    return 0;
}