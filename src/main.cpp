// Copyright 2022 NNTU-CS
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "tree.h"

int main() {
    std::vector<char> symbols = {'A', 'B', 'C', 'D'};
    PermutationTree tree(symbols);

    auto begin_time = std::chrono::high_resolution_clock::now();
    auto full_perms = all_permutations(tree);
    auto finish_time = std::chrono::high_resolution_clock::now();
    double elapsed_ms = std::chrono::duration<double, std::milli>(finish_time - begin_time).count();
    std::cout << "Время вычисления всех перестановок: " << elapsed_ms << " мс.\n";

    std::random_device rand_dev;
    std::mt19937 random_gen(rand_dev());
    std::uniform_int_distribution<int> distribution(1, static_cast<int>(full_perms.size()));
    int position = distribution(random_gen);

    begin_time = std::chrono::high_resolution_clock::now();
    auto perm1 = permutation_at(tree, position);
    finish_time = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration<double, std::milli>(finish_time - begin_time).count();
    std::cout << "Получение одной перестановки (метод 1): " << elapsed_ms << " мс.\n";

    begin_time = std::chrono::high_resolution_clock::now();
    auto perm2 = direct_perm_access(tree, position);
    finish_time = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration<double, std::milli>(finish_time - begin_time).count();
    std::cout << "Получение одной перестановки (метод 2): " << elapsed_ms << " мс.\n";

    return 0;
}
