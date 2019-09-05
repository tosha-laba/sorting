#pragma once
#include "../utils.hpp"
#include <fstream>
#include <iostream>

/*
    TODO:
        1. Рефакторинг обработки ошибок
        2. Метод merge
 */
namespace sorting
{
    namespace external_merge
    {
        namespace
        {
            template <typename Item>
            int partition(std::ifstream &input, const char *destination_path_1, char *destination_path_2, int length)
            {
                std::ofstream output_left(destination_path_1);
                if (!output_left.is_open()) {
                    std::cout << "Failed to open " << destination_path_1 << '\n';
                    return -1;
                }

                std::ofstream output_right(destination_path_2);
                if (!output_right.is_open()) {
                    std::cout << "Failed to open " << destination_path_2 << '\n';
                    return -1;
                }

                int divider = length / 2;

                for (int i = 0; i < divider; ++i) {
                    if (input.eof()) {
                        std::cout << "Unexpected EOF while reading from input file\n";
                        return -1;
                    }

                    Item item;
                    input >> item;
                    output_left << item;
                    output_left << ' ';
                }

                for (int i = divider; i < length; ++i) {
                    if (input.eof()) {
                        std::cout << "Unexpected EOF while reading from input file\n";
                        return -1;
                    }

                    Item item;
                    input >> item;
                    output_right << item;
                    output_right << ' ';
                }

                return 0;
            }

            template <typename Item>
            int merge_files(const char *in_left_name,
                            const char *in_right_name,
                            const char *out_left_name,
                            const char *out_right_name,
                            int p,
                            int length)
            {
                std::ifstream in_left(in_left_name), in_right(in_right_name);
                std::ofstream out_left(out_left_name), out_right(out_right_name);

                if (!in_left.is_open()) {
                    std::cout << "Failed to open " << in_left_name << '\n';
                    return -1;
                } else if (!in_right.is_open()) {
                    std::cout << "Failed to open " << in_right_name << '\n';
                    return -1;
                } else if (!out_left.is_open()) {
                    std::cout << "Failed to open " << out_left_name << '\n';
                    return -1;
                } else if (!out_right.is_open()) {
                    std::cout << "Failed to open " << out_right_name << '\n';
                    return -1;
                }

                // См. восходящую сортировку у Седжвика

                return 0;
            }

            template <typename Item>
            int consolidation(const char *destination_path, const char *left_path, const char *right_path, int length)
            {
                std::ifstream in_left(left_path), in_right(right_path);
                std::ofstream out(destination_path);

                if (!in_left.is_open()) {
                    std::cout << "Failed to open " << left_path << '\n';
                    return -1;
                } else if (!in_right.is_open()) {
                    std::cout << "Failed to open " << right_path << '\n';
                    return -1;
                } else if (!out.is_open()) {
                    std::cout << "Failed to open " << destination_path << '\n';
                    return -1;
                }

                int divider = length / 2;

                for (int i = 0; i < divider; ++i) {
                    if (in_left.eof()) {
                        std::cout << "Unexpected EOF while reading from input file\n";
                        return -1;
                    }

                    Item item;
                    in_left >> item;
                    out << item;
                    out << ' ';
                }

                for (int i = divider; i < length; ++i) {
                    if (in_right.eof()) {
                        std::cout << "Unexpected EOF while reading from input file\n";
                        return -1;
                    }

                    Item item;
                    in_right >> item;
                    out << item;
                    out << ' ';
                }

                return 0;
            }

        } // namespace

        template <typename Item>
        void straight_sort(const char *source_path, const char *destination_path, int length)
        {
            std::ifstream input(source_path);
            if (!input.is_open()) {
                std::cout << "Failed to open " << source_path << '\n';
                return;
            }

            int p = 1;
            char *in_left_name = "tmp_left_1.dat";
            char *in_right_name = "tmp_right_1.dat";
            char *out_left_name = "tmp_left_2.dat";
            char *out_right_name = "tmp_right_2.dat";

            if (partition<Item>(input, in_left_name, in_right_name, length) != 0) {
                return;
            }

            input.close();

            do {
            if (merge_files<Item>(in_left_name, in_right_name, out_left_name, out_right_name, p, length) != 0) {
                return;
            }

            swap(in_left_name, out_left_name);
            swap(in_right_name, out_right_name);

            p *= 2;
            } while (p < length);

            consolidation<Item>(destination_path, in_left_name, in_right_name, length);
        }
    } // namespace external_merge

} // namespace sorting
