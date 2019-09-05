#pragma once
#include <math.h>

namespace sorting
{
    // TODO: убрать log2 (?)
    template <typename T>
    void shell_sort(T &a, int length)
    {
        int step = (2 << (int)log2(length)) - 1;

        while (step > 0) {
            for (int i = step; i < length; ++i) {
                auto value = a[i];

                int j = i;
                while (j >= step && a[j - step] > value) {
                    a[j] = a[j - step];
                    j -= step;
                }
                a[j] = value;
            }

            step = (step - 1) / 2;
        }
    }
} // namespace sorting
