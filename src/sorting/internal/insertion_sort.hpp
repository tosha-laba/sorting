#pragma once

namespace sorting
{
    template <typename T>
    void insertion_sort(T &a, int length)
    {
        for (int i = 0; i < length; ++i) {
            auto value = a[i];

            int j = i;
            while (j >= 1 && a[j - 1] > value) {
                a[j] = a[j - 1];
                --j;
            }
            a[j] = value;
        }
    }

} // namespace sorting
