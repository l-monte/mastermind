#pragma once

#include <array>
#include <utility>
#include "Code.h"
#include "GuessResult.h"

class Board
{
public:
    constexpr static unsigned BOARD_WIDTH = 38;
    constexpr static unsigned NUM_OF_ROWS = 8;

    using BoardType = std::array<std::pair<Code::CodeType , GuessResult::Places>, NUM_OF_ROWS>;

    Board() = default;
    ~Board() = default;

    // noncopyable
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;

    void init();
    void show(size_t round_number) const;
    void set(size_t currentRound, const Code::CodeType& player_guess, const GuessResult::Places& places);

private:
    void showHeader(unsigned round_number) const;
    void showRow(unsigned round_number) const;
    void showHorizontalBar() const;
    BoardType board_data;
};