cmake_minimum_required(VERSION 3.14)
project(algorithmly)

set(CMAKE_CXX_STANDARD 17)
set(ALGORITHMLY
        01-iteration
        02-array
        03-time_complexity
        04-counting_elements
        05-prefix_sums
        06-sorting
        07-stacks_and_queues
        08-leader
        09-maximum_slice_problem
        10-prime_and_composite
        11-sieve_of_erathostenes
        12-euclidean_algorithm
        13-fibonacci_numbers
        14-binary_search
        15-caterpillar_method
        16-greedy_algorithms
        17-dynamic_programming
        90-2015_challenge
        )

foreach(_dir IN ITEMS ${ALGORITHMLY})
    file(GLOB _files "${_dir}/*.cpp")
    message(STATUS "Algorithm `${_dir}':")

    foreach(_file IN ITEMS ${_files})

        get_filename_component(_file_name ${_file} NAME)

        set(_project_name "${_file_name}")
        message(STATUS "  ${_dir}/${_file_name} is going to be built")

        add_executable(${_project_name} "${_dir}/${_file_name}")
    endforeach()

endforeach()