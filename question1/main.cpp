#include <iostream>
#include <stdexcept>

using namespace std;

// Exception class for index errors
//----------------------------------------------------------------------------------------question1 part2 (just need to wote the class)
class Bad_Index : public exception
{
private:
    int index;

public:
    Bad_Index(int idx) : index(idx) {}

    const char *what() const noexcept override
    {
        return "Bad-Index value is out of bounds.";
    }

    int getIndex() const { return index; }

    // Add operator<< for exception output
    friend ostream &operator<<(ostream &os, const Bad_Index &ex)
    {
        return os << ex.what() << " (Index: " << ex.index << ")";
    }
};

// Template class for dynamic array
//----------------------------------------------------------------------------------------question2 (wrote the constnstuctor || the destructor || operator<< || operator[])
template <typename T>
class Array
{
private:
    T *data;
    size_t size;

public:
    // Default constructor (important for T3 and T4)
    Array() : data(nullptr), size(0) {} // ---------------------------------------------------default constnstuctor

    // Constructor with size
    Array(size_t n) : size(n)
    {
        data = new T[size]();
    }

    // Copy Constructor
    Array(const Array &other) : size(other.size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    // Constructor to initialize from C-style array
    Array(const T arr[], size_t n) : size(n) 
    {
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = arr[i];
        }
    }

    // Destructor
    ~Array() // ----------------------------------------------------------------------------------------destructor

    {
        delete[] data;
    }

    // Assignment operator
    Array &operator=(const Array &other)
    {
        if (this == &other)
            return *this;
        delete[] data;
        size = other.size;
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Indexing operator
    T &operator[](size_t index) // --------------------------------------------------------------------operator[]
    {
        if (index >= size)
            throw Bad_Index(index);
        return data[index];
    }

    // Const Indexing Operator
    const T &operator[](size_t index) const
    {
        if (index >= size)
            throw Bad_Index(index);
        return data[index];
    }

    // Friend function to output the array
    friend ostream &operator<<(ostream &os, const Array &arr) // -------------------------------------operator<<
    {
        os << "[ ";
        for (size_t i = 0; i < arr.size; ++i)
        {
            os << arr.data[i] << " ";
        }
        os << "]";
        return os;
    }

    // // Conversion Constructor: Convert Array<int> -> Array<double>
    // template <typename U>
    // Array(const Array<U> &other)
    // {
    //     size = other.getSize();
    //     data = new T[size];
    //     for (size_t i = 0; i < size; ++i)
    //     {
    //         data[i] = static_cast<T>(other[i]); // Convert each element
    //     }
    // }

    // // Conversion Operator: Convert Array<int> to Array<double>
    // template <typename U>
    // operator Array<U>() const
    // {
    //     return Array<U>(*this);
    // }

    // // Get size (needed for the conversion constructor)
    // size_t getSize() const { return size; }
};

//----------------------------------------------------------------------------------------question1 part1 (just need to wote typedef's parameters)
// Type definitions
typedef Array<double> T1;
typedef Array<int> T2;
typedef Array<T1> T3;
typedef Array<T2> T4;

int main()
{
    try
    {
        T1 a1(12), a11(10);         // בגודל12ו10- double הגדרת2מערכים של
        T2 a2(10);                  // 10 בגודל int הגדרת מערך של
        //a2 = a11;                 // Syntax error
        a1 = a11;                   // O.K.
        a1[5] = a2[4];              // O.K.
        cout << a1 << endl;         // הדפסת מערך שלם

        const T1 ca1(a11);          // הגדרת מערך קבוע עם אתחול
        // ca1 = a11;               // Syntax error
        // ca1[2] = a11[3];         // Syntax error
        a11[3] = ca1[2];            // O.K.

        double c_array[] = {0.5, -7, 3.14, 0., 3};      // "C הגדרת "מערך
        T1 a12(c_array, 4);                             // "C הגדרת מערך ואתחולו ע"י "מערך
        T3 a3;                                          // בגודל5 double הגדרת מערך של
        T4 a4;                                          // בגודל8 double הגדרת מערך של
        // a3[1] = a4[2];                                  // O.K.     || but not will produce the result cuz we cant Convert Array<double> to Array<int>
        //  // a3 = a4;                                   // Syntax error
        //  // a4 = a3;                                   // Syntax error
        // a1 = a4;                                        // O.K.     || but not will produce the result cuz we cant Convert Array<int> to Array<double>

        return 0;
    }
    catch (Bad_Index exc)
    {
        cerr << exc; // Bad-Index value is ... : פלט
    }
}
