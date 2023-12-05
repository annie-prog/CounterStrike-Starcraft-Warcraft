cmake_minimum_required(VERSION 3.5.0)
project(lcs VERSION 0.1.0 LANGUAGES C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake_helpers/helpers.cmake)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


add_executable(${PROJECT_NAME}
        ${SRC_DIR}/ColorMatrix.cpp
        ${SRC_DIR}/ColorSequenceFinder.cpp
        ${SRC_DIR}/main.cpp
)
set_target_cpp_standard(${PROJECT_NAME} 11)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(lcs PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
)