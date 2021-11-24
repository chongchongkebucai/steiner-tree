#pragma once

#include "Tree.h"
#include "flute.h"

class BuildTree {
public:
  virtual Tree build_tree(const Flute::Tree &flute_tree, int root_index) = 0;
};