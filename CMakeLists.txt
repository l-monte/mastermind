cmake_minimum_required(VERSION 3.12)

project(mastermind CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(includes)

add_executable(${PROJECT_NAME}
        src/Board.cpp
        src/CodeValidator.cpp
		src/MastermindGame.cpp
		src/Player.cpp
        src/Code.cpp
        src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR/includes/}
)

