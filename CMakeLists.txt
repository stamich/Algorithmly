cmake_minimum_required(VERSION 3.14)
project(algorithmly)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithmly
        01-iteration/BinaryGap.cpp
        02-array/OddOccurrencesInArray.cpp 02-array/CyclicRotation.cpp
        03-time_complexity/FrogJump.cpp 03-time_complexity/PermMissingElem.cpp 03-time_complexity/TapeEquilibrium.cpp
        04-counting_elements/PermCheck.cpp 04-counting_elements/FrogRiverOne.cpp 04-counting_elements/MaxCounters.cpp 04-counting_elements/MissingInteger.cpp
        05-prefix_sums/CountDiv.cpp 05-prefix_sums/PassingCars.cpp 05-prefix_sums/GenomicRangeQuery.cpp 05-prefix_sums/MinAvgTwoSlice.cpp
        06-sorting/Distinct.cpp 06-sorting/MaxProductOfThree.cpp 06-sorting/Triangle.cpp 06-sorting/NumberOfDiscIntersections.cpp
        07-stacks_and_queues/Brackets.cpp 07-stacks_and_queues/Fish.cpp 07-stacks_and_queues/Nesting.cpp 07-stacks_and_queues/StoneWall.cpp
        08-leader/Dominator.cpp 08-leader/EquiLeader.cpp
        09-maximum_slice_problem/MaxProfit.cpp 09-maximum_slice_problem/MaxSliceSum.cpp 09-maximum_slice_problem/MaxDoubleSliceSum.cpp
        10-prime_and_composite/CountFactors.cpp 10-prime_and_composite/MinPerimeterRectangle.cpp 10-prime_and_composite/Peaks.cpp 10-prime_and_composite/Flags.cpp
        11-sieve_of_erathostenes/CountSemiprimes.cpp 11-sieve_of_erathostenes/CountNonDivisible.cpp
        12-euclidean_algorithm/ChocolatesByNumbers.cpp 12-euclidean_algorithm/CommonPrimeDivisors.cpp
        13-fibonacci_numbers/Ladder.cpp 13-fibonacci_numbers/FibFrog.cpp
        14-binary_search/MinMaxDivision.cpp 14-binary_search/NailingPlanks.cpp
        15-caterpillar_method/CountDistinctSlices.cpp 15-caterpillar_method/CountTriangles.cpp 15-caterpillar_method/AbsDistinct.cpp 15-caterpillar_method/MinAbsSumOfTwo.cpp
        16-greedy_algorithms/TieRopes.cpp 16-greedy_algorithms/MaxNonOverlappingSegments.cpp
        17-dynamic_programming/NumberSolitaire.cpp 17-dynamic_programming/MinAbsSum.cpp)