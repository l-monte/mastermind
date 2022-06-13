#include "Code.h"

std::ostream& operator<<(std::ostream& o, const Code& code)
{
    o << "[" << code.m_code[0] << " " << code.m_code[1] << " " << code.m_code[2] << " " << code.m_code[3] << "]";
    return o;
}

Code::Code(const CodeType& code) : m_code(code)
{}

Code::CodeType Code::getCode() const
{
    return m_code;
}