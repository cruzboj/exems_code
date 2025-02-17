#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
using namespace std;
#include <string.h>

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

        // String *operator+(String &other)
        // {
        //     // Point_Null temp = dynamic_cast<Point_Null &>(other);
        //     // char *new_p = new char[strlen(pstart) + strlen(temp.pstart) + 1];
        //     // strcpy(new_p, pstart);
        //     // strcat(new_p, temp.pstart);

        //     // return new Point_Null(new_p); // Return a new object instead of modifying this
        // }
        virtual String* operator+(String& str)override{
            Point_Size* Temp = dynamic_cast<Point_Size*>(&str); 
            if(temp != nullptr){
                Point_Null * new_pstart = new Point_Null[this->strlen(pstart)+1 + str.size];
                strcpy(new_pstart, this->pstart);
                int j =0;
                for (int i = strlen(this->pstart); i < strlen(this->pstart) + str.size ; i++){
                    new_pstart[i] = str.pstart[j++];
                }
                new_pstart[strlen(this->pstart) + str.size] = '\0';
                return new_pstart;
            }
            else{
                new_pstart = new Point_Null[this->strlen(pstart) + strlen(str) + 1];
                strcpy(new_pstart,this->pstart);
                strcat(new_pstart,str);
                return new_pstart;
            }
        }
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
        return Point_Null(pstart);
    }

    operator Point_Size()
    {
        return *this;
    }

    
    // String *operator+(String &other)
    // {
    //     Point_Size& temp = dynamic_cast<Point_Size&>(other);
    //     size = strlen(pstart) + strlen(temp.pstart);
    //     char *new_p = new char[strlen(pstart) + strlen(temp.pstart)];
    //     strcpy(new_p, pstart);
    //     strcat(new_p, temp.pstart);
    //     pstart = new_p;
    //     size = strlen(pstart);

    //     return this;
    // }
    virtual String* operator+(String& str)override{
            Point_Null* Temp = dynamic_cast<Point_Null*>(&str);
            if (Temp != nullptr) {
                // str הוא מסוג Point_Null
                Point_Size *new_pstart = new Point_Size[size + strlen(str)];
                for (int i = 0; i < size; i++)
                {
                    new_pstart[i] = pstart[i];
                }
                j = 0;
                for (int i = size; i < size + strlen(str); i++)
                {
                    new_pstart[i] = str.pstart[j++];
                }
                new_pstart->size = size + strlen(str);
                return new_pstart;
            }
            else{
                Point_Size *new_pstart new Point_Size[size + str.size];
                for (int i = size; i < size+str.size; i++)
                {
                    new_pstart[i] = str.pstart[i];
                }
                new_pstart->size = size + str.size;
                return new_pstart;
            }
        }

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

#endif