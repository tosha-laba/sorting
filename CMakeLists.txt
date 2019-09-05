cmake_minimum_required(VERSION 3.0.0)
project(sorting VERSION 0.1.0)

include(CTest)
enable_testing()

set(MAIN_PATH src/main.cpp)
set(SORTING_ENTRY_PATH src/sorting/sorting.hpp)
set(
    SORTING_PATH 
    
    src/sorting/internal/bubble_sort.hpp 
    src/sorting/internal/insertion_sort.hpp 
    src/sorting/internal/selection_sort.hpp
    src/sorting/internal/counting_sort.hpp
    src/sorting/internal/heap_sort.hpp
    src/sorting/internal/quick_sort.hpp
    src/sorting/internal/shaker_sort.hpp
    src/sorting/internal/shell_sort.hpp
    src/sorting/internal/tree_sort.hpp
    src/sorting/internal/merge_sort.hpp
    src/sorting/external/straight_sort.hpp
    src/sorting/external/natural_sort.hpp
    src/sorting/utils.hpp
)

add_executable(sorting ${MAIN_PATH} ${SORTING_ENTRY_PATH} ${SORTING_PATH})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
