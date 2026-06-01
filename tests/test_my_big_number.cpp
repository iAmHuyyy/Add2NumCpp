#include "MyBigNumber.h"

#include <cassert>
#include <iostream>
#include <string>

static void assertSum(const std::string& a, const std::string& b, const std::string& expected) {
    MyBigNumber calculator(false);
    const std::string actual = calculator.sum(a, b);
    assert(actual == expected);
}

int main() {
    assertSum("1234", "897", "2131");
    assertSum("0", "0", "0");
    assertSum("1", "999", "1000");
    assertSum("999999999999999999", "1", "1000000000000000000");
    assertSum("12345678901234567890", "98765432109876543210", "111111111011111111100");
    assertSum("00012", "0008", "20");
    assertSum("500", "500", "1000");

    std::cout << "All tests passed.\n";
    return 0;
}
