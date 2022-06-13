#pragma once

#include "Code.h"
#include <array>

class GuessResult
{
public:
    constexpr static char MISSING     = ' ';
    constexpr static char MATCHED     = 'o';
    constexpr static char OTHER_PLACE = 'x';

    using Places = Code::CodeType;
};