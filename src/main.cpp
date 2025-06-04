// Copyright 2022 NNTU-CS
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "tree.h"

int main() {
    std::vector<char> letters = {'a', 'b', 'c', 'd'};
    PMTree tree(letters);

    auto timer_start = std::chrono::high_resolution_clock::now();
    auto all_permutations = getAllPerms(tree);
    auto timer_end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double,
    std::milli>(timer_end - timer_start).count();
    std::cout << "Вычисление всех перестановок заняло: "
        << duration << "мс." << std::endl;

    std::random_device rnd_device;
    std::mt19937 rng_engine(rnd_device());
    std::uniform_int_distribution<> distr
    (1, static_cast<int>(all_permutations.size()));
    int chosen_number = distr(rng_engine);

    timer_start = std::chrono::high_resolution_clock::now();
    auto perm_from_list = getPerm1(tree, chosen_number);
    timer_end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration<double, std::milli>
        (timer_end - timer_start).count();
    std::cout << "Выбор конкретной перестановки занял: "
        << duration << "мс." << std::endl;

    timer_start = std::chrono::high_resolution_clock::now();
    auto perm_directly = getPerm2(tree, chosen_number);
    timer_end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration<double, std::milli>
        (timer_end - timer_start).count();
    std::cout << "Прямой доступ к перестановке занял: "
        << duration << "мс." << std::endl;

    return 0;
}
