#include "CodeValidator.h"
#include <algorithm>
#include <set>
#include <iostream>

CodeValidator::CodeValidator(const Code& encoded_code)
    : m_encoded_code(encoded_code)
{}

GuessResult::Places CodeValidator::validate(const Code& code)
{
    GuessResult::Places places;
    const auto guessed_code = code.getCode();
    const auto encoded_code = m_encoded_code.getCode();
    for (auto i = 0u; i < guessed_code.size(); ++i)
    {
        if (guessed_code[i] == encoded_code[i])
        {
            places[i] = GuessResult::MATCHED;
        }
        else if (isGuessedFoundInOtherPlace(guessed_code[i], i))
        {
            places[i] = GuessResult::OTHER_PLACE;
        }
        else
        {
            places[i] = GuessResult::MISSING;
        }
    }

    return places;
}

bool CodeValidator::isGuessedFoundInOtherPlace(char sign, size_t place) const
{
    std::set<size_t> indexes = {0, 1, 2, 3};
    indexes.erase(place);

    const auto code = m_encoded_code.getCode();
    const auto found = std::find_if(begin(indexes), end(indexes), [&](size_t p)
    {
        return code[p] == sign;
    });

    return found != end(indexes);
}