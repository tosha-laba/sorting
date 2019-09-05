#pragma once

namespace sorting
{
    namespace
    {
        template <typename Item>
        struct node {
            node *left_children = nullptr;
            node *right_children = nullptr;
            Item value;

            void add(Item &item)
            {
                if (item > value) {
                    if (right_children == nullptr) {
                        right_children = make_node(item);
                    } else {
                        right_children->add(item);
                    }
                } else {
                    if (left_children == nullptr) {
                        left_children = make_node(item);
                    } else {
                        left_children->add(item);
                    }
                }
            }

            template <typename T>
            int traverse(T &a, int index = 0)
            {
                if (left_children != nullptr) {
                    index = left_children->traverse(a, index);
                }

                a[index++] = value;

                if (right_children != nullptr) {
                    index = right_children->traverse(a, index);
                }

                return index;
            }

            ~node()
            {
                if (left_children != nullptr)
                    delete left_children;

                if (right_children != nullptr)
                    delete right_children;
            }
        };

        template <typename Item>
        node<Item> *make_node(Item item,
                              node<Item> *left_children = nullptr,
                              node<Item> *right_children = nullptr)
        {
            node<Item> *root = new node<Item>;

            root->value = item;
            root->left_children = left_children;
            root->right_children = right_children;

            return root;
        }

    } // namespace

    template <typename T>
    void tree_sort(T &a, int length)
    {
        if (length == 0)
            return;

        auto *root = make_node(a[0]);

        for (int i = 1; i < length; ++i) {
            root->add(a[i]);
        }
        root->traverse(a);

        delete root;
    }
} // namespace sorting
