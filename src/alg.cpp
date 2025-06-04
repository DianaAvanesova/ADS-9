// Copyright 2022 NNTU-CS
#include <iostream>
#include <algorithm>
#include <vector>
#include "tree.h"

Node::Node(char d) : data(d) {}

Node::~Node() {
    for (auto descendant : descendants)
        delete descendant;
}

PermutationTree::PermutationTree(const std::vector<char>& in) {
    head = new Node('\0');
    construct(head, in);
}

PermutationTree::~PermutationTree() {
    delete head;
}

void PermutationTree::construct(Node* parent, std::vector<char> rem) {
    std::sort(rem.begin(), rem.end());
    for (char ch : rem) {
        Node* kid = new Node(ch);
        parent->descendants.push_back(kid);
        std::vector<char> temp = rem;
        temp.erase(std::remove(temp.begin(), temp.end(), ch), temp.end());
        construct(kid, temp);
    }
}

void PermutationTree::gather(Node* current_node, std::vector<char>& acc_path, std::vector<std::vector<char>>& collected) {
    if (current_node->data != '\0')
        acc_path.push_back(current_node->data);
    if (current_node->descendants.empty())
        collected.push_back(acc_path);
    else
        for (auto descendant : current_node->descendants)
            gather(descendant, acc_path, collected);
    if (!acc_path.empty() && current_node->data != '\0')
        acc_path.pop_back();
}

std::vector<std::vector<char>> all_permutations(PermutationTree& tree) {
    std::vector<std::vector<char>> permutations;
    std::vector<char> intermediate;
    tree.gather(tree.head, intermediate, permutations);
    return permutations;
}

std::vector<char> permutation_at(PermutationTree& tree, int idx) {
    auto perms = all_permutations(tree);
    return ((idx > 0 && static_cast<size_t>(idx) <= perms.size())) ? perms[idx - 1] : std::vector<char>();
}

std::vector<char> PermutationTree::extract_by_idx(Node* cur_node, int& counter, int target) {
    if (cur_node->descendants.empty()) {
        ++counter;
        return (counter == target) ? std::vector<char>{cur_node->data} : std::vector<char>{};
    }
    for (auto descendant : cur_node->descendants) {
        auto res = extract_by_idx(descendant, counter, target);
        if (!res.empty()) {
            if (cur_node->data != '\0') {
                res.insert(res.begin(), cur_node->data);
            }
            return res;
        }
    }
    return {};
}

std::vector<char> direct_perm_access(PermutationTree& tree, int pos) {
    int count = 0;
    return tree.extract_by_idx(tree.head, count, pos);
}
