#pragma once

#include "CodeValidator.h"
#include "Player.h"
#include "Board.h"
#include <cstdint>
#include <memory_resource>

class MastermindGame
{
    constexpr static uint32_t MAX_ROUNDS = 8;
public:
	MastermindGame();
	~MastermindGame() = default;

    // noncopyable
    MastermindGame(const MastermindGame&) = delete;
    MastermindGame& operator=(const MastermindGame&) = delete;

	void run();

private:
    bool playTheRound() const;
    bool isGuessed(const GuessResult::Places& result) const;

private:
    std::unique_ptr<Player> m_player = nullptr;
    std::unique_ptr<CodeValidator> m_validator = nullptr;
    std::unique_ptr<Board> m_board = nullptr;
    uint32_t m_current_round = 0;
};
