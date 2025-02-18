// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

template <typename T, int arr_size = 0> // Default size is 10
class Array
{
    T *array;
    int size;

public:
    Array() : size(arr_size) { array = new T[size]; } // Default constructor
    Array(int value) : size(value) { array = new T[size]; }

    void fill(T value)
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = value;
        }
    }

    T &at(int index)
    {
        return array[index];
    }

    int getSize() const { return size; }
};

typedef Array<double> T1;
typedef Array<int> T2;
typedef Array<double, 5> T3;
typedef Array<double, 8> T4;

int main()
{
    T2 a2(10);
    T3 a3;
    a2.fill(10);
    cout << a2.getSize() << endl;
    cout << a3.getSize() << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "a2[" << i << "]: " << a2.at(i) << endl;
    }
    return 0;
}