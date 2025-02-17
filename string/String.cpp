#include <iostream>
#include <string>

// https://www.youtube.com/watch?v=-5xVrsBguHg

//  using namespace std; //template use

int main()
{
    std::string test1 = "abcdefghi";

    std::cout << test1 << std::endl;

    std::cout << "size :" << test1.size() << std::endl;

    std::cout << "test[1] = " << test1[1] << std::endl;

    std::cout << "test1.at(3) " << test1.at(3) << std::endl;

    test1[2] = 'C';
    std::cout << test1 << std::endl;

    test1 = test1 + "jklmnop";
    test1 += "qrstu";
    test1.append("vwxyz");
    std::cout << test1 << std::endl;

    std::cout << "length: " << test1.length() << std::endl;

    return 0;
}