#pragma once
#include "../utils.hpp"

namespace sorting
{
    template <typename T>
    void selection_sort(T &a, int length)
    {
        for (int i = 0; i < length; ++i) {
            int min_index = i;
            auto min_value = a[i];

            for (int j = i + 1; j < length; ++j) {
                if (a[j] < min_value) {
                    min_index = j;
                    min_value = a[j];
                }
            }

            swap(a[i], a[min_index]);
        }
    }

} // namespace sorting
