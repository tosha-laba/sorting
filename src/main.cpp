#include "sorting/sorting.hpp"
#include <ctime>
#include <iostream>
#include <random>

#define INIT_PERF clock_t c_start, c_end;

#define PERF(statement, message)    \
    c_start = std::clock();         \
    statement;                      \
    c_end = std::clock() - c_start; \
    std::cout << message << " running time:\t\t\t\t" << 1000.0 * c_end / CLOCKS_PER_SEC << " ms\n";

template <typename T>
void print_array(T &a, int length)
{
    for (int i = 0; i < length; i++) {
        std::cout << a[i];
        std::cout << ' ';
    }

    std::cout << std::endl;
}

template <typename T>
void check_arrangency(T &a, int length, char *testName)
{
    for (int i = 0; i < length - 1; i++) {
        if (a[i] > a[i + 1]) {
            std::cout << testName << " failed \n";
            return;
        }
    }

    std::cout << testName << " correct \n";
}

template <typename T>
bool compare_arrays(T &a, T &b, int length)
{
    for (int i = 0; i < length; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

int main(int, char **)
{
    // std::cout << "Internal sorts\n\n";

    // int *test_1 = new int[100000],
    //     *test_2 = new int[100000],
    //     *test_3 = new int[100000],
    //     *test_4 = new int[100000],
    //     *test_5 = new int[100000],
    //     *test_6 = new int[100000],
    //     *test_7 = new int[100000],
    //     *test_8 = new int[100000],
    //     *test_9 = new int[100000],
    //     *test_10 = new int[100000];

    // float *test_4_map = new float[100000];

    // std::random_device r;
    // std::default_random_engine el(r());
    // std::uniform_int_distribution<int> dist(0, 1999999);

    // for (int i = 0; i < 100000; i++) {
    //     auto value = dist(el);
    //     test_1[i] = value;
    //     test_2[i] = value;
    //     test_3[i] = value;
    //     test_4[i] = value;
    //     test_4_map[i] = (float)value;
    //     test_5[i] = value;
    //     test_5[i] = value;
    //     test_6[i] = value;
    //     test_7[i] = value;
    //     test_8[i] = value;
    //     test_9[i] = value;
    //     test_10[i] = value;
    // }

    // std::cout << std::fixed;

    // INIT_PERF

    // PERF(sorting::bubble_sort(test_1, 10000), "BubbleSort")
    // PERF(sorting::insertion_sort(test_2, 10000), "InsertionSort")
    // PERF(sorting::selection_sort(test_3, 10000), "SelectionSort")
    // PERF(sorting::counting_sort(test_4, 10000), "CountingSort")
    // PERF(sorting::counting_sort(test_4_map, 10000), "CountingSort (std::map)")
    // PERF(sorting::heap_sort(test_5, 10000), "HeapSort")
    // PERF(sorting::shaker_sort(test_6, 10000), "ShakerSort")
    // PERF(sorting::shell_sort(test_7, 10000), "ShellSort")
    // PERF(sorting::tree_sort(test_8, 10000), "TreeSort")
    // PERF(sorting::quick_sort(test_9, 10000), "QuickSort")
    // PERF(sorting::merge_sort(test_10, 10000), "MergeSort")

    // std::cout << std::endl;

    // check_arrangency(test_1, 10000, "BubbleSort");
    // check_arrangency(test_2, 10000, "InsertionSort");
    // check_arrangency(test_3, 10000, "SelectionSort");
    // check_arrangency(test_4, 10000, "CountingSort");
    // check_arrangency(test_4_map, 10000, "CountingSort (std::map)");
    // check_arrangency(test_5, 10000, "HeapSort");
    // check_arrangency(test_6, 10000, "ShakerSort");
    // check_arrangency(test_7, 10000, "ShellSort");
    // check_arrangency(test_8, 10000, "TreeSort");
    // check_arrangency(test_9, 10000, "QuickSort");
    // check_arrangency(test_10, 10000, "MergeSort");

    // std::cout << std::endl;

    // std::cout << "BubbleSort: " << compare_arrays(test_1, test_1, 10000) << '\n';
    // std::cout << "InsertionSort: " << compare_arrays(test_1, test_2, 10000) << '\n';
    // std::cout << "SelectionSort: " << compare_arrays(test_1, test_3, 10000) << '\n';
    // std::cout << "CountingSort: " << compare_arrays(test_1, test_4, 10000) << '\n';
    // std::cout << "HeapSort: " << compare_arrays(test_1, test_5, 10000) << '\n';
    // std::cout << "ShakerSort: " << compare_arrays(test_1, test_6, 10000) << '\n';
    // std::cout << "ShellSort: " << compare_arrays(test_1, test_7, 10000) << '\n';
    // std::cout << "TreeSort: " << compare_arrays(test_1, test_8, 10000) << '\n';
    // std::cout << "QuickSort: " << compare_arrays(test_1, test_9, 10000) << '\n';
    // std::cout << "MergeSort: " << compare_arrays(test_1, test_10, 10000) << '\n';

    // delete[] test_1;
    // delete[] test_2;
    // delete[] test_3;
    // delete[] test_4;
    // delete[] test_4_map;
    // delete[] test_5;
    // delete[] test_6;
    // delete[] test_7;
    // delete[] test_8;
    // delete[] test_9;
    // delete[] test_10;

    std::cout << "\nExternal sorts" << std::endl;

    sorting::external_merge::straight_sort<int>("input.dat", "output.dat", 10);
    sorting::external_merge::natural_sort<int>("input.dat", "output.dat", 10);
}
