#pragma once
#include "../utils.hpp"
#include <random>

namespace sorting
{
    namespace
    {
        /*
            Заметка: 
                Стандартное разделение Ломуто из книги Кормена плохо тем,
                что разделяет массив на части с a[i] <= x и a[i] > x,
                тем самым оставляя возможность свести алгоритм к O(N^2) при
                сортировке массива из одинаковых элементов.

                Решить проблему можно разделяя массив на a[i] <= x и a[i] >= x.

                Просто сменив строгость/направление упорядочивания этого не добиться,
                но можно добавлять элементы в одну из частей на основе, допустим,
                четности/нечетности обозреваемого элемента, если он, при этом, равен x:
                
                (a[i] == x && i % 2 == 0) || a[i] < x

                Минус такого подхода в том, что сортировка получается неустойчивой,
                т.к. элементы со вторичными ключами добавляются в группы не в исходном порядке.
         */
        template <typename T>
        int partition(T &a, int l, int r)
        {
            static std::random_device rd;
            static std::default_random_engine el(rd());
            std::uniform_int_distribution<int> dist(l, r);

            std::swap(a[dist(el)], a[r]);

            auto x = a[r];
            int i = l - 1;

            for (int j = l; j <= r - 1; ++j) {
                if (a[j] <= x) {
                    ++i;
                    swap(a[j], a[i]);
                }
            }
            swap(a[r], a[i + 1]);

            return i + 1;
        }

        template <typename T>
        void quick_sort_impl(T &a, int l, int r)
        {
            if (l < r) {
                int pivot_index = partition(a, l, r);
                quick_sort_impl(a, l, pivot_index - 1);
                quick_sort_impl(a, pivot_index + 1, r);
            }
        }
    } // namespace

    template <typename T>
    void quick_sort(T &a, int length)
    {
        quick_sort_impl(a, 0, length - 1);
    }
} // namespace sorting
