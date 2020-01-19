cmake_minimum_required(VERSION 3.15)
project(limsave)

set(CMAKE_CXX_STANDARD 17)
add_executable(limsave driver.cpp CustomException.cpp SaveBuilder.cpp SaveInterface.cpp UtilityFunctions.cpp Saver.cpp)

