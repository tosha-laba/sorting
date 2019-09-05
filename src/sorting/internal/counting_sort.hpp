#pragma once
#include "../utils.hpp"
#include <map>
#include <type_traits>

namespace sorting
{
    namespace
    {
        template <typename T>
        void counting_sort_integral(T &a, int length)
        {
            auto min = find_min(a, length);
            auto max = find_max(a, length);

            int *element_counters = new int[max - min + 1]();

            for (int i = 0; i < length; i++) {
                element_counters[a[i] - min]++;
            }

            int element_index = 0;
            for (int i = 0; i < max - min + 1; i++) {
                for (int j = 0; j < element_counters[i]; j++) {
                    a[element_index++] = i + min;
                }
            }

            delete[] element_counters;
        }

        template <typename Item, typename T>
        void counting_sort_map(T &a, int length)
        {
            std::map<Item, int> element_counters;

            for (int i = 0; i < length; i++) {
                element_counters[a[i]]++;
            }

            int element_index = 0;
            for (const auto &counter : element_counters) {
                for (int j = 0; j < counter.second; j++) {
                    a[element_index++] = counter.first;
                }
            }
        }

        template <typename Item, typename T>
        void counting_sort_dispatcher(T &a, int length, std::true_type)
        {
            counting_sort_integral(a, length);
        }

        template <typename Item, typename T>
        void counting_sort_dispatcher(T &a, int length, std::false_type)
        {
            counting_sort_map<Item>(a, length);
        }

    } // namespace

    template <typename T>
    void counting_sort(T &a, int length)
    {
        using Item = T::value_type;
        counting_sort_dispatcher<Item>(a, length, std::is_integral<Item>{});
    }

    template <typename Item>
    void counting_sort(Item a[], int length)
    {
        counting_sort_dispatcher<Item>(a, length, std::is_integral<Item>{});
    }

} // namespace sorting
