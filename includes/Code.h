#pragma once

#include <array>
#include <ostream>

class Code
{
public:
    constexpr static uint8_t CODE_SIZE = 4;

    using CodeType = std::array<char, CODE_SIZE>;

    Code() = default;
    ~Code() = default;
    Code(const CodeType& code);

    Code(const Code& o) = default;
    Code(Code&& o) = default;

    friend std::ostream& operator<<(std::ostream&, const Code&);

    CodeType getCode() const;

private:
    CodeType m_code;
};