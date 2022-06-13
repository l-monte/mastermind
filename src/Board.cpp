#include "Board.h"

#include <iostream>

void Board::show(size_t round_number) const
{
    showHeader(round_number);
    showHorizontalBar();
    for (auto i = 0u; i < NUM_OF_ROWS; i++)
    {
        showRow(i);
        showHorizontalBar();
    }
}

void Board::init()
{
    for (auto i = 0u; i < NUM_OF_ROWS; ++i)
    {
        board_data[i].first = {' ', ' ', ' ', ' '};
        board_data[i].second = {' ', ' ', ' ', ' '};
    }
}

void Board::set(size_t currentRound,
                const Code::CodeType& player_guess,
                const GuessResult::Places& places)
{
    board_data[currentRound].first = player_guess;
    board_data[currentRound].second = places;
}

void Board::showHorizontalBar() const
{
    for(auto i = 0u; i < BOARD_WIDTH; ++i)
    {
        std::cout << "-";
    }

    std::cout << "\n";
}

void Board::showRow(unsigned row_number) const
{
    std::cout << row_number + 1 << " ||";

    for (auto i = 0; i < Code::CODE_SIZE; i++)
    {
        std::cout << " " << board_data[row_number].first[i] << " |";
    }

    std::cout << "|";

    for (auto i = 0; i < Code::CODE_SIZE; i++)
    {
        std::cout << " " << board_data[row_number].second[i] << " |";
    }

    std::cout << "|\n";
}

void Board::showHeader(unsigned row_number) const
{
    std::cout << "\nMASTERMIND! \nNumber of tries: " << row_number + 1 << "\n";
}