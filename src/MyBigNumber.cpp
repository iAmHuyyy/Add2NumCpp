#include "MyBigNumber.h"

#include <algorithm>
#include <iostream>
#include <sstream>

MyBigNumber::MyBigNumber(bool enableLogging, std::ostream* logStream)
    : enableLogging_(enableLogging), logStream_(logStream == nullptr ? &std::cout : logStream) {}

void MyBigNumber::setEnableLogging(bool enableLogging) {
    enableLogging_ = enableLogging;
}

void MyBigNumber::setLogStream(std::ostream& logStream) {
    logStream_ = &logStream;
}

std::string MyBigNumber::sum(const std::string& stn1, const std::string& stn2) {
    int i = static_cast<int>(stn1.size()) - 1;
    int j = static_cast<int>(stn2.size()) - 1;
    int carry = 0;
    int step = 1;
    std::string resultReversed;

    while (i >= 0 || j >= 0 || carry > 0) {
        const char char1 = (i >= 0) ? stn1[static_cast<std::size_t>(i)] : '0';
        const char char2 = (j >= 0) ? stn2[static_cast<std::size_t>(j)] : '0';
        const int digit1 = char1 - '0';
        const int digit2 = char2 - '0';
        const int carryIn = carry;

        const int total = digit1 + digit2 + carryIn;
        const int resultDigit = total % 10;
        carry = total / 10;

        resultReversed.push_back(static_cast<char>('0' + resultDigit));

        std::string currentResult = resultReversed;
        std::reverse(currentResult.begin(), currentResult.end());

        logStep(step, char1, char2, digit1, digit2, carryIn, total, resultDigit, carry, currentResult);

        --i;
        --j;
        ++step;
    }

    std::reverse(resultReversed.begin(), resultReversed.end());

    // Remove leading zeroes while keeping exactly one zero for results such as "0" + "0".
    const std::size_t firstNonZero = resultReversed.find_first_not_of('0');
    if (firstNonZero == std::string::npos) {
        return "0";
    }
    return resultReversed.substr(firstNonZero);
}

void MyBigNumber::logStep(int step,
                          char char1,
                          char char2,
                          int digit1,
                          int digit2,
                          int carryIn,
                          int total,
                          int resultDigit,
                          int carryOut,
                          const std::string& currentResult) const {
    if (!enableLogging_ || logStream_ == nullptr) {
        return;
    }

    (*logStream_) << "Step " << step << ": "
                  << "take '" << char1 << "' and '" << char2 << "' -> "
                  << digit1 << " + " << digit2 << " + carry " << carryIn
                  << " = " << total << "; write " << resultDigit
                  << "; new carry " << carryOut
                  << "; current result = " << currentResult << '\n';
}
