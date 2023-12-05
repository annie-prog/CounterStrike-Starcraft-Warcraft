cmake_minimum_required(VERSION 3.5.0)
project(star-craft VERSION 0.1.0 LANGUAGES C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake_helpers/helpers.cmake)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}
        ${SRC_DIR}/battle_cruiser.cpp
        ${SRC_DIR}/carrier.cpp
        ${SRC_DIR}/game.cpp
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/phoenix.cpp
        ${SRC_DIR}/protoss.cpp
        ${SRC_DIR}/protoss_ship.cpp
        ${SRC_DIR}/race.cpp
        ${SRC_DIR}/ship.cpp
        ${SRC_DIR}/terran.cpp
        ${SRC_DIR}/viking.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 11)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(star-craft PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
)