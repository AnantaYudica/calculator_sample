#include "Calculator.h"

#include <iostream>

Calculator::Calculator() :
    m_update(false),
    m_comma(false),
    m_op('\0'),
    m_ndigit(0), 
    m_ans_ndigit(0),
    m_int_ndigit(0),
    m_ans_int_ndigit(0),
    m_fraction_ndigit(0), 
    m_ans_fraction_ndigit(0),
    m_int(0), 
    m_ans_int(0),
    m_fraction(0), 
    m_ans_fraction(0)
{}

Calculator::~Calculator()
{}

void Calculator::UpdateValue(const int& num)
{
    m_ndigit++;
    if (!m_comma)
    {
        m_int = (num + (m_int * 10));
        m_int_ndigit++;
    }
    else
    {
        m_fraction = (num+ (m_fraction * 10));
        m_fraction_ndigit++;
    }
    m_update = true;
}

void Calculator::SetValue()
{
    m_comma = false;
    m_ans_ndigit = m_ndigit;
    m_ndigit = 0;
    m_ans_int_ndigit = m_int_ndigit;
    m_int_ndigit = 0;
    m_ans_fraction_ndigit = m_fraction_ndigit; 
    m_fraction_ndigit = 0;
    m_ans_int = m_int;
    m_int = 0;
    m_ans_fraction = m_fraction; 
    m_fraction = 0;
    m_update = true;
}

void Calculator::Key(char ch)
{
    std::cout << "ch : " << ch << std::endl;
}

std::string Calculator::Print()
{
    return "0";
}
