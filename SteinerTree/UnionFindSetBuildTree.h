#pragma once

#include "BuildTree.h"
#include <iostream>

class UnionFindSetBuildTree : public BuildTree {
public:
  UnionFindSetBuildTree() = default;

  Tree build_tree(const Flute::Tree &flute_tree, int root_index);
};