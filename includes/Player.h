#pragma once

#include "Code.h"

class Player
{
public:
    Player() = default;
    ~Player() = default;

    Code guessCode() const;
};