cmake_minimum_required(VERSION 3.14)
project(algorithmly)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithmly
        01-iteration/BinaryGap.cpp
        02-array/OddOccurrencesInArray.cpp 02-array/CyclicRotation.cpp
        03-time_complexity/FrogJump.cpp 03-time_complexity/PermMissingElem.cpp 03-time_complexity/TapeEquilibrium.cpp 04-counting_elements/PermCheck.cpp 04-counting_elements/FrogRiverOne.cpp 04-counting_elements/MaxCounters.cpp 04-counting_elements/MissingInteger.cpp)