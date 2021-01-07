#include "Calculator.h"

#include <iostream>

Calculator::Calculator() :
    m_curr(0),
    m_tmp(0),
    m_op('\0')
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
