#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
#include <cstdint>
#include <atomic>

class Calculator
{
private:
    std::atomic_bool m_update;
    bool m_comma;
    char m_op;
    std::size_t m_ndigit, m_ans_ndigit;
    std::size_t m_int_ndigit, m_ans_int_ndigit;
    std::size_t m_fraction_ndigit, m_ans_fraction_ndigit;
    std::int64_t m_int, m_ans_int;
    std::uint64_t m_fraction, m_ans_fraction;
public:
    Calculator();
public:
    ~Calculator();
private:
    void UpdateValue(const int& num);
    void SetValue();
public:
    bool IsUpdate() const;
public:
    void Key(char ch);
    std::string Print();
};

#endif //!CALCULATOR_H_
