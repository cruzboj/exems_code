#include <iostream>
using namespace std;

class Fraction
{
    int num;
    unsigned denom;

public:
    explicit Fraction(int n = 0, unsigned d = 1)
    {
        num = n;
        denom = d;
    }
    friend ostream &operator<<(ostream &s, const Fraction &temp)
    {
        s << temp.num << " / " << temp.denom;
        return s;
    }
};

int main ( )
{
    try
    {
        Array<int, 6> Arr_int;
        for (int i = 1; i < 4; i++)
        {
            Arr_int += i;
            Arr_int += i;
        }
        cout << Arr_int; // 1 1 2 2 3 3
        Array<Fraction, 8> Arr_Fraction;
        for (i = 1; i < 3; i++)
        {
            Arr_Fraction += Fraction(i, 1);
            Arr_Fraction += Fraction(i, 1);
        }
        cout << Arr_Fraction; // 1 /1 1 /1 2 /1 2 /1
        Set<int, 6> Set_int;
        for (i = 1; i < 3; i++)
        {
            Set_int += i;
            Set_int += i;
        }
        cout << Set_int; // 1 2
        Set<Fraction, 8> Set_Fraction;
        for (i = 0; i < 3; i++)
        {
            Set_Fraction += Fraction(i * 10000 + 9999, 10000);
            Set_Fraction += Fraction(i * 10000 + 9999, 10000);
        }
        cout << Set_Fraction; // 9999 /10000 19999 /10000 29999 /10000
        // cout << Set_int [ 5 ] ; // Out of range
        // Arr_Fraction [ 5 ] = Fraction ( 5, 6 ) ; // Out of range
        if (Arr_Fraction > Arr_int)
            cout << "Yes\n";
        else
            cout << "No\n"; // No
        if (Set_int > Arr_int)
            cout << "Yes\n";
        else
            cout << "No\n"; // Yes
        if (Set_Fraction > Arr_ Fraction)
            cout << "Yes\n";
        else
            cout << "No\n"; // Yes
        Set_int += Arr_int;
        cout << Set_int; // 1 2 3
        // Arr_int חלק מודגש מ-
        Arr_Fraction += Set_Fraction;
        cout << Arr_Fraction;
        // 1 /1 1 /1 2 /1 2 /1 9999 /10000 19999 /10000 29999 /10000
        // Set _Fraction חלק מודגשמ-
        // Arr_int += Set_int ; // Array Full
        // Arr_Fraction += Set_Fraction ; // Array Full
        // Set_int += 4;
        // Set_int += 5;
        // Set_int += 6;
        // Set_int += 7; // Set Full
    }
    catch (char *msg)
    {
        cout << msg;
    }

    return 0;
}