// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

struct Node {
    char data;
    std::vector<Node*> descendants;

    explicit Node(char d);
    ~Node();
};

class PermutationTree {
 private:
    Node* head;

    void construct(Node*, std::vector<char>);
    void gather(Node*, std::vector<char>&, std::vector<std::vector<char>>&);
    std::vector<char> extract_by_idx(Node*, int&, int);

 public:
    explicit PermutationTree(const std::vector<char>& input);
    ~PermutationTree();

    friend std::vector<std::vector<char>> all_permutations(PermutationTree&);
    friend std::vector<char> permutation_at(PermutationTree&, int);
    friend std::vector<char> direct_perm_access(PermutationTree&, int);
};

#endif  // INCLUDE_TREE_H_
