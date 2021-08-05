cmake_minimum_required(VERSION 3.16.3)

project(SFMLgame)

include_directories(include)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

