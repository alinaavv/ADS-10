// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n, int* count, std::vector<char>* permutation) {
    if (tree.children.empty()) {
        (*count)++;
        if (*count == n) {
            return permutation;
        }
    } else {
        for (Tree* child : tree.children) {
            permutation.push_back(child->value);
            auto result = getPerm(*child, n, count, permutation);
            if (!result.empty()) {
                return result;
            }
            permutation.pop_back();
        }
    }
    return {};
}

std::vector<char> getPerm(const Tree& tree, int n) {
    int count = 0;
    std::vector<char> permutation;
    return getPerm(tree, n, &count, permutation);
}
