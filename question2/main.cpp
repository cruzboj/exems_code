#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>

class Point_Null;
class Point_Size;

class String
{
protected:
    char *pstart;

public:
    String(char *p = NULL)
    {
        if (p)
        {
            pstart = new char[strlen(p) + 1];
            strcpy(pstart, p);
        }
        else
            pstart = NULL;
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
    Point_Null(char *p = NULL) : String(p) {}
    void print() { cout << "point null " << pstart << endl; }

    operator Point_Null() override
    {
        return *this;
    }

    operator Point_Size()
    {
        return Point_Size(pstart);
    }

    // dynamic_cast is used to convert from father to child and vice versa
    String *operator=(String *other)
    {
        Point_Null *temp = dynamic_cast<Point_Null *>(other);
        if (!temp)
            return this; // Check if cast was successful

        delete[] pstart; // Free old memory before assigning new one
        pstart = new char[strlen(temp->pstart) + 1];
        strcpy(pstart, temp->pstart);

        return this;
    }

    virtual String *operator+(String &str) override
    {
        // שימוש אוטומטי ב-operator Point_Null()
        Point_Null tempNull = str;                // ממיר כל String ל-Point_Null
        int str_length = strlen(tempNull.pstart); // מחלץ את אורך המחרוזת

        // הקצאת זיכרון למחרוזת החדשה
        char *new_pstart = new char[strlen(pstart) + 1 + str_length];
        strcpy(new_pstart, pstart);
        strcat(new_pstart, tempNull.pstart);

        // קביעה אם להחזיר Point_Size או Point_Null
        if (dynamic_cast<Point_Size *>(&str))
            return new Point_Size(new_pstart);
        else
            return new Point_Null(new_pstart);
    }
    // String *operator+(String &other)
    // {
    //     // Point_Null temp = dynamic_cast<Point_Null &>(other);
    //     // char *new_p = new char[strlen(pstart) + strlen(temp.pstart) + 1];
    //     // strcpy(new_p, pstart);
    //     // strcat(new_p, temp.pstart);

    //     // return new Point_Null(new_p); // Return a new object instead of modifying this
    // }
    // virtual String *operator+(String &str) override
    // {
    //     Point_Size *Temp = dynamic_cast<Point_Size *>(&str);
    //     if (Temp != nullptr)
    //     {
    //         char *new_pstart = new Point_Null[strlen(pstart) + 1 + Temp->Point_Size()];
    //         strcpy(new_pstart, pstart);
    //         int j = 0;
    //         for (int i = strlen(this->pstart); i < strlen(this->pstart) + str.size; i++)
    //         {
    //             new_pstart[i] = str.pstart[j++];
    //         }
    //         new_pstart[strlen(this->pstart) + str.size] = '\0';
    //         return new_pstart;
    //     }
    //     else
    //     {
    //         char *new_pstart = new Point_Null[this->strlen(pstart) + strlen(str) + 1];
    //         strcpy(new_pstart, pstart);
    //         strcat(new_pstart, str);
    //         return new_pstart;
    //     }
    //}
};

class Point_Size : public String
{
    int size;

public:
    Point_Size(char *p = NULL) : String(p)
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

    operator Point_Null() override
    {
        char * new_str = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            new_str[i] = pstart[i];
        }
        new_str[size] = '\0';

        return Point_Null(new_str);
    }

    operator Point_Size()
    {
        return *this;
    }

    virtual String *operator+(String &str) override{

    }
        // virtual String *operator+(String &str) override
        // {
        //     Point_Null *Temp = dynamic_cast<Point_Null *>(&str);
        //     if (Temp != nullptr)
        //     {
        //         // str הוא מסוג Point_Null
        //         Point_Size *new_pstart = new Point_Size[size + strlen(str)];
        //         for (int i = 0; i < size; i++)
        //         {
        //             new_pstart[i] = pstart[i];
        //         }
        //         j = 0;
        //         for (int i = size; i < size + strlen(str); i++)
        //         {
        //             new_pstart[i] = str.pstart[j++];
        //         }
        //         new_pstart->size = size + strlen(str);
        //         return new_pstart;
        //     }
        //     else
        //     {
        //         Point_Size *new_pstart new Point_Size[size + str.size];
        //         for (int i = size; i < size + str.size; i++)
        //         {
        //             new_pstart[i] = str.pstart[i];
        //         }
        //         new_pstart->size = size + str.size;
        //         return new_pstart;
        //     }
        // }

        // dynamic_cast is used to convert from father to child and vice versa
        String *operator=(String *other)
    {
        Point_Size *temp = dynamic_cast<Point_Size *>(other);
        if (!temp)
            return this; // Ensure successful cast

        delete[] pstart; // Free previous memory
        size = strlen(temp->pstart);
        pstart = new char[size + 1];
        strcpy(pstart, temp->pstart);

        return this;
    }
};

int main(){
        Point_Size p_size1("abc"),/*p_size1("ij"),*/p_size3;
        Point_Null p_null1("defgh"),p_null2("klmnop"),p_null3;
        cout << endl;
        
        // p_size1 = p_size1 + p_null1; // abc + defgh
        // p_size1.print(); // Point Size abcdefgh
        // cout << endl;

        // p_null3 = p_null1 + p_size1; // defgh + abcdefgh
        // p_null3.print(); // Point null defghabcdefgh
        // cout << endl;

        // p_null3 = p_size2 + p_null2; // ij + klmnop
        // p_null3.print(); // Point null ijklmnop
        // cout << endl;

        // p_size1 = p_size1 + p_null3; // abcdefgh + ijklmnop
        // p_size1.print(); // Point Size abcdefghijklmnop

    return 0;
}