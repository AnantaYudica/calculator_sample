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

void Calculator::Key(char ch)
{
    std::cout << "ch : " << ch << std::endl;
}

std::string Calculator::Print()
{
    return "0";
}
