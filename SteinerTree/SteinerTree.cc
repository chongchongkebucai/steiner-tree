#include "SteinerTree.h"

SteinerTree::SteinerTree() { _flute = new FluteAdapter(); }

SteinerTree::~SteinerTree() { delete _flute; }

Tree SteinerTree::build_steiner_tree(const vector<Coordinate<int>> &coords,
                                     const Coordinate<int> &root_coord) {
  // build steiner tree respresented by pairs of coordination.
  Flute::Tree flute_tree = _flute->build_flute_tree(coords);
  // get the index of root node in the flute tree.
  auto root_index = _flute->get_index(flute_tree, root_coord);
  auto tree_root_index = _flute->get_root_index(flute_tree);
  // choose appropriate algorithm
  if (root_index == tree_root_index) {
    _builder = new UnionFindSetBuildTree();
  } else {
    _builder = new BFSBuildTree();
  }
  return _builder->build_tree(flute_tree, root_index);
}
