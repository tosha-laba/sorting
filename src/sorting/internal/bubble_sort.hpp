#pragma once
#include "../utils.hpp"

namespace sorting
{
    template <typename T>
    void bubble_sort(T &a, int length)
    {
        for (int i = 0; i < length - 1; ++i) {
            for (int j = 0; j < length - i - 1; ++j) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }

} // namespace sorting
