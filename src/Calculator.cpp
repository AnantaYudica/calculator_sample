#include "Calculator.h"

#include <iostream>
#include <algorithm>

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

bool Calculator::IsUpdate() const
{
    return m_update.load();
}

void Calculator::Key(char ch)
{
    std::cout << "ch : " << ch << std::endl;switch (ch)
    {
    case '0':
        UpdateValue(0);
        break;
    case '1':
        UpdateValue(1);
        break;
    case '2':
        UpdateValue(2);
        break;
    case '3':
        UpdateValue(3);
        break;
    case '4':
        UpdateValue(4);
        break;
    case '5':
        UpdateValue(5);
        break;
    case '6':
        UpdateValue(6);
        break;
    case '7':
        UpdateValue(7);
        break;
    case '8':
        UpdateValue(8);
        break;
    case '9':
        UpdateValue(9);
        break;
    case '.':
        m_comma = true;
        m_update = true;
        break;
    case '+':
        break;
    case '-':
        break;
    case '*':
        break;
    case '/':
        break;
    case '=':
        break;
    default:
        break;
    }
}

std::string Calculator::Print()
{
    m_update = false;
    if (!m_comma)
    {
        auto res = std::to_string(m_int);
        std::reverse(res.begin(), res.end());
        return res;
    }
    std::string res = std::to_string(m_int);
    std::string fraction_str = std::to_string(m_fraction);
    res += ",";
    std::cout << "res " << res << std::endl;
    if (m_fraction_ndigit != 0)
    {
        const auto size = m_fraction_ndigit - fraction_str.size();
        for (std::size_t i = 0; i < size; ++i)
        {
            res += "0";
        }
        res += fraction_str;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
