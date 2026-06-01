#include "MyBigNumber.h"

#include <iostream>
#include <string>

int main() {
    MyBigNumber calculator;

    const std::string stn1 = "1234";
    const std::string stn2 = "897";

    std::cout << "stn1 = " << stn1 << '\n';
    std::cout << "stn2 = " << stn2 << '\n';
    std::cout << "-----------------------------\n";

    const std::string result = calculator.sum(stn1, stn2);

    std::cout << "-----------------------------\n";
    std::cout << "Result: " << stn1 << " + " << stn2 << " = " << result << '\n';

    return 0;
}
