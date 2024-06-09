// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>
#include  "tree.h"

std::vector<char> getPerm(Tree* tree, int n, int& count,
                          std::vector<char>& perm) {
    if (!tree) {
        return {};
    }
    perm.push_back(tree->value);
    if (tree->children.empty()) {
        count++;
        if (count == n) {
            return perm;
        }
    } else {
        for (Tree* child : tree->children) {
            auto result = getPerm(child, n, count, perm);
            if (!result.empty()) {
                return result;
            }
        }
    }
    perm.pop_back();
    return {};
}

std::vector<char> getPermWrapper(Tree* tree, int n) {
    int count = 0;
    std::vector<char> perm;
    return getPerm(tree, n, count, perm);
}
