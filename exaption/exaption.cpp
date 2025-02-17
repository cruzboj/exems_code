#include <iostream>
#include <exception>
#include <string>
// https://www.youtube.com/watch?v=5nCXSDv6e4I
using namespace std;

int main() {

    string word = "four";
    try {
        // cout << word.at(4) << endl;
        // int *array  = new int[1000000000000000000];
    } catch (out_of_range &error) {
        cout << "1th catch: " << error.what() << endl;
    }
    catch (bad_alloc &error)
    {
        cout << "2th catch: " << error.what() << endl;
    }
    catch (exception &error)
    {
        cout << "3th catch: " << error.what() << endl;
    }
    catch (...)
    {
        cout << "default catch case" << endl;
    }

    return 0;
}