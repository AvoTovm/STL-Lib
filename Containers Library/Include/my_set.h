#pragma once

#include "../trees/AVLtree.h"

template <typename T>
class Set {
public:
    Set() = default;
    Set(std::initializer_list<T> list) {
        for (const auto& item : list) {
            insert(item);
        }
    }

    void insert(T value) {
        tree.insert(value);
    }

    void erase(T value) {
        tree.deleteKey(value);
    }

    bool contains(T value) {
        return tree.search(value);
    }

    void print() {
        tree.inOrder();
    }

private:
    AVLTree<T> tree;
};