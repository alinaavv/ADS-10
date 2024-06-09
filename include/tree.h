// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
public:
    char value;
    std::vector<Tree*> children;

    Tree(std::vector<char> elements) {
        if (!elements.empty()) {
            value = elements[0];
            for (size_t i = 1; i < elements.size(); ++i) {
                std::vector<char> next_elements = elements;
                next_elements.erase(next_elements.begin() + i - 1);
                children.push_back(new Tree(next_elements));
            }
        }
    }

    ~Tree() {
        for (auto child : children) {
            delete child;
        }
    }

    std::vector<char> getPermutation(int n, std::vector<char>& perm, int& count) {
        perm.push_back(value);
        if (children.empty()) {
            count++;
            if (count == n) {
                return perm;
            }
        } else {
            for (auto child : children) {
                std::vector<char> result = child->getPermutation(n, perm, count);
                if (!result.empty()) {
                    return result;
                }
            }
        }
        perm.pop_back();
        return {};
    }
};

#endif  // INCLUDE_TREE_H_
