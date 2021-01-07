#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>

class Calculator
{
private:
    double m_curr, m_tmp;
    char m_op;
public:
    Calculator();
public:
    ~Calculator();
public:
    void Key(char ch);
    std::string Print();
};

#endif //!CALCULATOR_H_
