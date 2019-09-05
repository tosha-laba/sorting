#pragma once

namespace sorting
{
    template <typename T>
    void shaker_sort(T &a, int length)
    {
        int l = 0;
        int r = length - 1;
        bool has_permutation = false;

        while (l < r) {
            has_permutation = false;

            for (int i = l; i < r; ++i) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                    has_permutation = true;
                }
            }

            if (!has_permutation)
                break;

            --r;

            has_permutation = false;

            for (int i = r; i > l; --i) {
                if (a[i - 1] > a[i]) {
                    swap(a[i - 1], a[i]);
                    has_permutation = true;
                }
            }

            if (!has_permutation)
                break;

            ++l;
        }
    }
} // namespace sorting
