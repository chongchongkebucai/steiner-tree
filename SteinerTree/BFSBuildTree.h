#pragma once

#include "BuildTree.h"
#include "Coordinate.h"
#include "Tree.h"
#include <queue>
#include <vector>

using std::queue;
using std::vector;

class BFSBuildTree : public BuildTree {
public:
  BFSBuildTree() = default;

  Tree build_tree(const Flute::Tree &flute_tree, int root_index);

private:
  Tree depth_first_build_tree(const Flute::Tree &flute_tree,
                              const vector<vector<int>> &graph,
                              vector<bool> &visited, int index);
  void remove_redundant_steiner_node(Tree tree);
};