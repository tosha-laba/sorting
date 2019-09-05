#pragma once

namespace sorting
{
    template <typename Item>
    void swap(Item &a, Item &b)
    {
        Item temp = a;
        a = b;
        b = temp;
    }

    template <typename T>
    auto find_min(T &a, int length)
    {
        auto min_value = a[0];

        for (int i = 0; i < length; i++) {
            if (a[i] < min_value) {
                min_value = a[i];
            }
        }

        return min_value;
    }

    template <typename T>
    auto find_max(T &a, int length)
    {
        auto max_value = a[0];

        for (int i = 0; i < length; i++) {
            if (a[i] > max_value) {
                max_value = a[i];
            }
        }

        return max_value;
    }

} // namespace sorting
