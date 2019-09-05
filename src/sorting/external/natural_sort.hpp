#pragma once

namespace sorting
{
    namespace external_merge
    {
        template <typename Item>
        void natural_sort(const char *source_path, const char *destination_path, int length)
        {
            std::ifstream input(source_path);
            if (!input.is_open()) {
                std::cout << "Failed to open " << source_path << '\n';
                return;
            }
        }
    } // namespace external_merge
    
} // namespace sorting
