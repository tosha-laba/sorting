#pragma once
#include "../utils.hpp"

namespace sorting
{
    namespace
    {
        template <typename T>
        void sift_down(T &a, int index, int length)
        {
            for (;;) {
                int left = index * 2 + 1;
                int right = index * 2 + 2;

                if (left >= length) {
                    break;
                }

                if (right >= length) {
                    right = left;
                }

                int next_index = index;

                if (a[left] > a[index]) {
                    next_index = left;
                }

                if (a[right] > a[next_index]) {
                    next_index = right;
                }

                if (next_index == index) {
                    break;
                }

                swap(a[index], a[next_index]);

                index = next_index;
            }
        }

        template <typename T>
        void heapify(T &a, int length)
        {
            for (int i = length / 2; i >= 0; --i) {
                sift_down(a, i, length);
            }
        }
    } // namespace

    template <typename T>
    void heap_sort(T &a, int length)
    {
        heapify(a, length);

        for (int i = length - 1; i >= 0; --i) {
            swap(a[0], a[i]);
            sift_down(a, 0, i);
        }
    }

} // namespace sorting
