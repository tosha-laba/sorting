#pragma once

namespace sorting
{
    namespace
    {
        template <typename T>
        void merge(T &a, int l, int r, int m)
        {
            auto left_part = T(m - l + 1);
            auto right_part = T(r - m);

            merge_impl(a, left_part, right_part, l, r, m);
        }

        template <typename Item>
        void merge(Item a[], int l, int r, int m)
        {
            Item *left_part = new Item[m - l + 1];
            Item *right_part = new Item[r - m];

            merge_impl(a, left_part, right_part, l, r, m);

            delete[] left_part;
            delete[] right_part;
        }

        template <typename T>
        void merge_impl(T &a, T &left_part, T &right_part, int l, int r, int m)
        {
            for (int i = 0; i <= m - l; ++i) {
                left_part[i] = a[i + l];
            }
            for (int i = 0; i < r - m; ++i) {
                right_part[i] = a[i + m + 1];
            }

            for (int i = 0, j = 0, k = l; k <= r; k++) {
                if (i == m - l + 1) {
                    a[k] = right_part[j++];
                    continue;
                }

                if (j == r - m) {
                    a[k] = left_part[i++];
                    continue;
                }

                a[k] = (left_part[i] <= right_part[j]) ? left_part[i++] : right_part[j++];
            }
        }

        template <typename T>
        void merge_sort_impl(T &a, int l, int r)
        {
            if (l < r) {
                int m = (l + r) / 2;

                merge_sort_impl(a, l, m);
                merge_sort_impl(a, m + 1, r);
                merge(a, l, r, m);
            }
        }
    } // namespace

    template <typename T>
    void merge_sort(T &a, int length)
    {
        merge_sort_impl(a, 0, length - 1);
    }
} // namespace sorting
