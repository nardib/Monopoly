cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 11)
project (Monopoly)

include_directories (include)

add_library (${PROJECT_NAME} SHARED
	src/Board.cpp
	src/Player.cpp
	src/HumanPlayer.cpp
	src/ComputerPlayer.cpp
	src/Cell.cpp)

add_executable (main src/main.cpp)

target_link_libraries (main ${PROJECT_NAME})