// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class TreeNode {
 public:
    char value;
    std::vector<TreeNode*> children;

    explicit TreeNode(char val);
    ~TreeNode();
};

class PMTree {
 private:
    TreeNode* root;

    void build(TreeNode* node, std::vector<char> remaining);
    void collect(TreeNode* node,
std::vector<char>& path, std::vector<std::vector<char>>& result);
    std::vector<char> getPermByIndex(TreeNode* node, int& index, int target);

 public:
    explicit PMTree(const std::vector<char>& in);
    ~PMTree();

    friend std::vector<std::vector<char>> getAllPerms(PMTree& tree);
    friend std::vector<char> getPerm1(PMTree& tree, int num);
    friend std::vector<char> getPerm2(PMTree& tree, int num);
};


#endif  // INCLUDE_TREE_H_
