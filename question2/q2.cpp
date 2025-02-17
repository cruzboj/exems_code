#include <iostream>
using namespace std;
#include <cstring>
#include <string.h>

class Point_Null;
class Point_Size;
class String
{
protected:
    char *pstart;

public:
    String(const char *p = nullptr)
    {
        if (p)
        {
            pstart = new char[strlen(p) + 1];
            strcpy(pstart, p);
        }
        else
            pstart = nullptr;
    }
    virtual ~String()
    {
        if (pstart)
            delete[] pstart;
    }
    virtual void print() = 0;

    virtual String *operator+(String &) = 0; //////////////////
    virtual String *operator=(String *) = 0; //////////////////
    virtual operator Point_Null() = 0;       //////////////////
    virtual operator Point_Size() = 0;       //////////////////
};


class Point_Null : public String
{
public:
    operator Point_Size();
    operator Point_Null();

    Point_Null(const char *p = nullptr) : String(p) {}
    void print() { cout << "point null " << pstart << endl; }

    String *operator+(String &str);
    String *operator=(String *str);
};

class Point_Size : public String
{
    int size;

public:
    operator Point_Null();
    operator Point_Size();

    Point_Size(const char *p = nullptr) : String(p)
    {
        if (p)
            size = strlen(pstart);
        else
            size = 0;
    }
    void print()
    {
        cout << "Point Size " << endl;
        for (int i = 0; i < size; i++)
            cout << pstart[i];
        cout << endl;
    }

    String *operator+(String &str);
    String *operator=(String *str);
};

Point_Null::operator Point_Size()
{
    cout << "Point_NULL::operetor Point_Size\n";
    return Point_Size(pstart);
}

Point_Null::operator Point_Null()
{
    cout << "Point_size::operetor Point_Null\n";
    return Point_Null(pstart);
}

Point_Size::operator Point_Size()
{
    cout << "Point_size::operetor Point_Size\n";
    return *this;
}

Point_Size::operator Point_Null()
{
    cout << "Point_size::operetor Point_Null\n";
    char *str = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        str[i] = pstart[i];
    }
    str[size] = '\0';
    //Point_Null result = str;
    //return Point_Null(result);
    return Point_Null(str);
}

String * Point_Null::operator+(String &str)
{
    Point_Null *Temp = dynamic_cast<Point_Null *>(&str); // check if the string is Point_Null if yes its will be true else false
    if (Temp != nullptr)
    {
        char *new_pstart = new char[strlen(pstart) + 1 + strlen(Temp->pstart)];
        strcpy(new_pstart, pstart);
        strcat(new_pstart, Temp->pstart);

        return new Point_Null(new_pstart); // creative new Point_Null and in his constractor he make new string objet that why we do this 
    }
    else
    {
        //how do i get acces to the size of the string
        //cant change main 
        //cant change the string class 
        //cant change the size from private to protected

        Point_Null converted = str.operator Point_Null();
        char *new_pstart = new char[strlen(pstart) + strlen(converted.pstart) + 1];
        strcpy(new_pstart, pstart);
        strcat(new_pstart, converted.pstart);
        return new Point_Null(new_pstart);
    }
}

String *Point_Size::operator+(String &str)
{
    Point_Null *Temp = dynamic_cast<Point_Null *>(&str);  //check if the string is Point_Null if yes its will be true else false
    if(Temp != nullptr){
        Point_Size converted = str.operator Point_Size();
        char *new_pstart = new char[size + converted.size - 1];
        for (int i = 0; i < size; i++)
        {
            new_pstart[i] = pstart[i];
        }
        int j = 0;
        for (int i = size; i < size + converted.size; i++)
        {
            new_pstart[i] = converted.pstart[j++];
        }
        return new Point_Size(new_pstart);
    }
    else{
        Point_Size converted = str.operator Point_Size();
        char *new_pstart = new char[size + converted.size];
        for (int i = 0; i < size; i++)
        {
            new_pstart[i] = pstart[i];
        }
        int j = 0;
        for (int i = size; i < size + converted.size; i++)
        {
            new_pstart[i] = converted.pstart[j++];
        }
        return new Point_Size(new_pstart);
    }
}

String *Point_Null::operator=(String *str){
    Point_Null *temp = dynamic_cast<Point_Null *>(str);
    if (temp != nullptr)
    {
        cout<< "if Point_Null::operator=(String *str)\n";
        delete[] pstart; // Free previous memory
        pstart = new char[strlen(temp->pstart) + strlen(temp->pstart) + 1];
        strcpy(pstart, temp->pstart);

        return this;
    }
    else
    {
        cout << "else Point_Null::operator=(String *str)\n";
        Point_Null converted = str->operator Point_Null();
        if (temp != nullptr)
        {
            delete[] pstart; // Free previous memory
            pstart = new char[strlen(temp->pstart) + strlen(converted.pstart) + 1];
            strcpy(pstart, temp->pstart);

            return this;
        }
    }

}

String *Point_Size::operator=(String *str)
{
    Point_Null *Temp = dynamic_cast<Point_Null *>(str);
    if (Temp != nullptr){
        Point_Size converted = str->operator Point_Size();
        delete[] pstart;
        this->size = converted.size;
        pstart = new char[converted.size];
        for(int i = 0; i < converted.size; i++){
            pstart[i] = converted.pstart[i];
        }
        return this;
    }
    else{
        Point_Size converted = str->operator Point_Size();
        delete[] pstart;
        this->size = converted.size;
        pstart = new char[converted.size];
        for (int i = 0; i < converted.size; i++)
        {
            pstart[i] = converted.pstart[i];
        }
        return this;
    }
}

int main()
{
    Point_Size p_size1("abc"), p_size2("ij"), p_size3;
    Point_Null p_null1("defgh"), p_null2("klmnop"), p_null3;
    cout << endl;

    p_size1 = p_size1 + p_null1; // abc + defgh
    p_size1.print(); // Point Size abcdefgh
    cout << endl;

    p_null3 = p_null1 + p_size1; // defgh + abcdefgh
    p_null3.print(); // Point null defghabcdefgh
    cout << endl;

    p_null3 = p_size2 + p_null2; // ij + klmnop
    p_null3.print(); // Point null ijklmnop
    cout << endl;

    p_size1 = p_size1 + p_null3; // abcdefgh + ijklmnop
    p_size1.print(); // Point Size abcdefghijklmnop

    return 0;
}