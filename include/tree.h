// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 public:
    char value;
    std::vector<Tree*> children;

    explicit Tree(std::vector<char> elements) {
        if (!elements.empty()) {
            value = elements[0];
            elements.erase(elements.begin());
            for (char elem : elements) {
                std::vector<char> next_elements = elements;
                next_elements.erase(std::remove(next_elements.begin(), next_elements.end(), elem), next_elements.end());
                children.push_back(new Tree(next_elements));
            }
        }
    }

    ~Tree() {
        for (Tree* child : children) {
            delete child;
        }
    }
};

#endif  // INCLUDE_TREE_H_
