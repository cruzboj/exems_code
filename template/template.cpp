#include <iostream>
#include <string>
// https://www.youtube.com/watch?v=mQqzP9EWu58

using namespace std; //template use

/* //we dont need them anymore its just an example for why we need to use this template 
class IntArray{
    public:
        string array[10];

        void fill(int value){
            for(int i = 0; i < 10; i++){
                array[i] = value;
            }
        }

        string & at(int index){
            return array[index];
        }
};

class StringArray{
    public:
        string array[10];

        void fill(string value)
        {
            for (int i = 0; i < 10; i++)
            {
                array[i] = value;
            }
        }

        string &at(int index)
        {
            return array[index];
        }
};
*/

template <typename T,int length> 
class Array{
public:
    T array[length];

    void fill(T value)
    {
        for (int i = 0; i < length; i++)
        {
            array[i] = value;
        }
    }

    T &at(int index)
    {
        return array[index];
    }
};


int main(){

    Array<int,5> intArray;
    intArray.fill(2);
    cout << "intArray[4]: " << intArray.at(4) << endl;

    Array<string,8> strArray;
    strArray.fill("abc");
    strArray.at(6) = "123";

    for(int i = 0; i < 8; i++){
        cout << "strArray[" << i << "]: " << strArray.at(i) << endl;
    }
    
    //problem - cant use template as run time *only compile time!
    // int x;
    // cin >> x;
    // Array<double,x> xArray;

    return 0;
}