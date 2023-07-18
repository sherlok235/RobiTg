cmake_minimum_required(VERSION 3.5)

project(RobiTGBot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(boost_system REQUIRED)

link_directories(../tgbot-cpp/UILD_SHARED_LIBS)
include_directories(../tgbot-cpp/include)
add_executable(RobiTGBot main.cpp TokenReader.cpp TokenReader.hpp Bot.cpp Bot.hpp)
target_link_libraries(RobiTGBot TgBot boost_system ssl crypto pthread)
