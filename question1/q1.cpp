#include <iostream>

//A
template <class T>

typedef array<double> T1;
typedef array<int> T2;
typedef array<double, 5> T3;
typedef array<double, 8> T4;

class BadIndex
{
private:
    int index; //stores the BadIndex
public:
    BadIndex(int i) : index(i){} //constructor that restores the index to the given BadIndex
    friend ostream& operator <<(ostream& co, BadIndex a) //operator << - prints the exeption
    {
        return co<<"Bad_Index value is "<<a.index<<endl;
    } 
};

class arrayBase
{
private:
    int size; //only size- other classes are inhertance anything that doesn't have T
protected:
    bool legal_index(int index) //checks if the index is OK between 0 - size-1 returns true/false
    {
        if (index>0 && index <size-1)
        {
            return true;
        }
        return false;
    }
    void size(int sz) //restore size as sz if legal
    {
        if (sz<0)
        {
            size=0;
        }
        size=sz;
    }
public:
    arrayBase(int sz) // creats and array with sz places
    {
        size(sz);
    }

    int size() const // get() func
    {
        return size;
    }
};

template <class T>
class array: public arrayBase
{
private:
    T* elements;

public:
    array(int sz):arrayBase(sz), elements(new T[sz]) {}
    ~array()
    {
        delete[] elements;
    }

    T& operator [](int index)
    {
        if (!legal_index(index))
        {
            throw BadIndex;
            return elements[index];
        }
        
    }

    const T& operator[](int index) const
    {
        if (!legal_index(index))
        {
            throw BadIndex;
            return elements[index];
        }
    }

    friend ostream& operator <<(ostream& co,const <array,T>& array) //operator << - prints the exeption
    {
        for(int i=0; i<array.size();i++)
        {
            return co<<array[i]<<" "<<endl;
        }
        
    } 
};
 



