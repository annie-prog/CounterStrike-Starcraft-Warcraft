cmake_minimum_required(VERSION 3.5.1)

project(multi-projects)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/starcraft)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/warcraft)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/counter-strike)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lcs)

