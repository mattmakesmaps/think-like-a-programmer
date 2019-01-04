/** A function that has a pointer in it's calling signature.
 * Let's call it with combinations of references */

#include <iostream>

void timesTwo(int * num1)
{
    *num1 = *num1 * 2;
}

int timesTwoConstInput(const int * num1)
{
    return *num1 * 2;
}

void timesTwoRef(int& num1)
{
    num1 = num1 * 2;
}

int timesTwoConstRefInput(const int& num1)
{
    return num1 * 2;
}

int main(void)
{
    std::cout << "Testing: void timesTwo(int * num1)\n";
    std::cout << "can not accept const parameters\n";
    int num = 10;
    std::cout << num << "\n";
    timesTwo(&num); // pass in address of staticly defined num
    std::cout << num << "\n";

    //Compilation Error:
    //  candidate function not viable: 1st argument ('const int *') 
    //  would lose const qualifier
    //
    // const int num2 = 40;
    // std::cout << num << "\n";
    // timesTwo(&num2); // pass in address of staticly defined num
    // std::cout << num << "\n";

    std::cout << "Testing: int timesTwoConstInput(const int * num1)\n";
    std::cout << "Legal to pass in both const int and int addresses\n";
    const int const_num2 = 40;
    std::cout << timesTwoConstInput(&const_num2) << "\n"; // Passing in address;
    int num2 = 40;
    std::cout << timesTwoConstInput(&num2) << "\n"; // Passing in address;

    std::cout << "Testing: void timesTwoRef(int & num1)\n";
    std::cout << "can not accept const parameters\n";
    int num3 = 10;
    const int const_num3 = 10;
    std::cout << num << "\n";
    timesTwoRef(num3); 
    //timesTwoRef(const_num3); // illegal
    std::cout << num << "\n";
    std::cout << "Testing: int timesTwoConstRefInput(const int& num1)\n";
    std::cout << "to pass const and non-const parameters\n";
    std::cout << num << "\n";
    timesTwoConstRefInput(num3); 
    timesTwoConstRefInput(const_num3);
    std::cout << num << "\n";
}