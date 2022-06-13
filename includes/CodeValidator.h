#pragma once

#include "Code.h"
#include "GuessResult.h"

class CodeValidator
{
public:
    CodeValidator(const Code& encoded_code);

    GuessResult::Places validate(const Code& code);

private:
    bool isGuessedFoundInOtherPlace(char sign, size_t place) const;

private:
    Code m_encoded_code;
};