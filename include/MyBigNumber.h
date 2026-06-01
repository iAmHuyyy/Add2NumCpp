#ifndef MY_BIG_NUMBER_H
#define MY_BIG_NUMBER_H

#include <iosfwd>
#include <string>

class MyBigNumber {
public:
    explicit MyBigNumber(bool enableLogging = true, std::ostream* logStream = nullptr);

    // Sum two non-negative integer numbers represented as strings.
    // Assumption from the requirement: input strings contain only valid digits.
    std::string sum(const std::string& stn1, const std::string& stn2);

    void setEnableLogging(bool enableLogging);
    void setLogStream(std::ostream& logStream);

private:
    bool enableLogging_;
    std::ostream* logStream_;

    void logStep(int step,
                 char char1,
                 char char2,
                 int digit1,
                 int digit2,
                 int carryIn,
                 int total,
                 int resultDigit,
                 int carryOut,
                 const std::string& currentResult) const;
};

#endif // MY_BIG_NUMBER_H
