// Copyright 2022 NNTU-CS
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "tree.h"

int main() {
  std::vector<char> input = { '1', '2', '3', '4', '5', '6' };
  PMTree tree(input);
  auto start = std::chrono::high_resolution_clock::now();
  auto perms = getAllPerms(tree);
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "getAllPerms time: "
    << std::chrono::duration<double, std::milli>(end - start).count() << "ms\n";
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, perms.size());
  int n = dist(gen);
  start = std::chrono::high_resolution_clock::now();
  auto perm1 = getPerm1(tree, 5000);
  end = std::chrono::high_resolution_clock::now();
  std::cout << "getPerm1 time: "
    << std::chrono::duration<double, std::milli>(end - start).count() << "ms\n";
  start = std::chrono::high_resolution_clock::now();
  auto perm2 = getPerm2(tree, 5000);
  end = std::chrono::high_resolution_clock::now();
  std::cout << "getPerm2 time: "
    << std::chrono::duration<double, std::milli>(end - start).count() << "ms\n";
  return 0;
}
