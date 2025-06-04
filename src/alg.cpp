// Copyright 2022 NNTU-CS
#include <iostream>
#include <algorithm>
#include <vector>
#include "tree.h"

TreeNode::TreeNode(char l) : label(l) {}

TreeNode::~TreeNode() {
    for (auto s : subnodes)
        delete s;
}

PMTree::PMTree(const std::vector<char>& chars) {
    base = new TreeNode(' ');
    expand(base, chars);
}

PMTree::~PMTree() {
    delete base;
}

void PMTree::expand(TreeNode* p, std::vector<char> rem) {
    std::sort(rem.begin(), rem.end());
    for (char c : rem) {
        TreeNode* sn = new TreeNode(c);
        p->subnodes.push_back(sn);
        std::vector<char> next = rem;
        next.erase(std::find(next.begin(), next.end(), c));
        expand(sn, next);
    }
}

void PMTree::traverse(TreeNode* curr,
                      std::vector<char>& path,
                      std::vector<std::vector<char>>& out) {
    if (curr->label != ' ')
        path.push_back(curr->label);
    if (curr->subnodes.empty()) {
        out.push_back(path);
    } else {
        for (auto sn : curr->subnodes)
            traverse(sn, path, out);
    }
    if (!path.empty() && curr->label != ' ')
        path.pop_back();
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
    std::vector<std::vector<char>> output;
    std::vector<char> temp;
    tree.traverse(tree.base, temp, output);
    return output;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
    auto perms = getAllPerms(tree);
    return(num>0 && num <= perms.size()) ? 
        perms[num-1] : std::vector<char>{};
}

std::vector<char> PMTree::fetch_by_order(TreeNode* node, int& cnt, int target) {
    if (node->subnodes.empty()) {
        ++cnt;
        return(cnt == target) ? std::vector<char>{node->label} 
            : std::vector<char>{};
    }
    for (auto sn : node->subnodes) {
        auto res = fetch_by_order(sn, cnt, target);
        if (!res.empty()) {
            if (node->label != ' ') {
                res.insert(res.begin(), node->label);
            }
            return res;
        }
    }
    return {};
}

std::vector<char> getPerm2(PMTree& tree, int num) {
    int counter = 0;
    return tree.fetch_by_order(tree.base, counter, num);
}
