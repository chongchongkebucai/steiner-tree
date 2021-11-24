#pragma once

#include "Coordinate.h"
#include <vector>

using std::vector;

struct TreeNode {
  Coordinate<int> _data;
  TreeNode *_father;
  vector<TreeNode *> _childs;
};

typedef TreeNode *Tree;