cmake_minimum_required(VERSION 3.15)
project(limsave)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(limsave
        Commons.h
        CustomException.cpp
        CustomExceptions.h
        driver.cpp
        SaveBuilder.cpp
        SaveBuilder.h
        SaveInterface.cpp
        SaveInterface.h
        Saver.cpp
        Saver.h
        UtilityFunctions.cpp
        UtilityFunctions.h)
