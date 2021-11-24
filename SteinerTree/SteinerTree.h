#pragma once

#include "BFSBuildTree.h"
#include "BuildTree.h"
#include "FluteAdapter.h"
#include "Tree.h"
#include "UnionFindSetBuildTree.h"

class SteinerTree {
public:
  SteinerTree();
  ~SteinerTree();

  Tree build_steiner_tree(const vector<Coordinate<int>> &coords,
                          const Coordinate<int> &root_coord);

private:
  FluteAdapter *_flute;
  BuildTree *_builder;
};