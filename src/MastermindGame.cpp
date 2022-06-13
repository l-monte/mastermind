#include "MastermindGame.h"
#include "Code.h"
#include <iostream>
#include <random>

Code generate()
{
    auto toStr = [](int n){ return std::to_string(n)[0]; };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(0, 9);

    const auto code = Code(Code::CodeType{toStr(distr(gen)),
                                          toStr(distr(gen)),
                                          toStr(distr(gen)),
                                          toStr(distr(gen))});
    return Code(code);
}

MastermindGame::MastermindGame()
    : m_player(std::make_unique<Player>())
    , m_validator(std::make_unique<CodeValidator>(generate()))
    , m_board(std::make_unique<Board>())
{
    m_board->init();
}

void MastermindGame::run()
{
    std::cout << "\t----==== MASTERMIND ====----\n"
                 "Available chars: digits 0 - 9.\n"
                 "Good luck!" << std::endl << std::endl;
    while(m_current_round < MAX_ROUNDS)
    {
        if (playTheRound())
        {
            std::cout << "You win! Congratulations!" << std::endl;
            return;
        }
        ++m_current_round;
    }

    std::cout << "Unfortunately, you loose.\nTry it again!" << std::endl;
}

bool MastermindGame::playTheRound() const
{
    auto code = m_player->guessCode();
    auto places = m_validator->validate(code);
    m_board->set(m_current_round, code.getCode(), places);
    m_board->show(m_current_round);

    return isGuessed(places);
}

bool MastermindGame::isGuessed(const GuessResult::Places& result) const
{
    for (const auto r : result)
    {
        if (r != GuessResult::MATCHED)
            return false;
    }

    return true;
}
