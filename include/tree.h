// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class TreeNode {
 public:
    char label;
    std::vector<TreeNode*> subnodes;

    explicit TreeNode(char l);
    ~TreeNode();
};

class PMTree {
 private:
    TreeNode* base;

    void expand(TreeNode* parent, std::vector<char> rest);
    void traverse(TreeNode* curr,
                  std::vector<char>& route,
                  std::vector<std::vector<char>>& results);
    std::vector<char> fetch_by_order(TreeNode* curr, int& idx, int goal);

 public:
    explicit PMTree(const std::vector<char>& chars);
    ~PMTree();

    friend std::vector<std::vector<char>> getAllPerms(PMTree& tree);
    friend std::vector<char> getPerm1(PMTree& tree, int num);
    friend std::vector<char> getPerm2(PMTree& tree, int num);
};


#endif  // INCLUDE_TREE_H_
