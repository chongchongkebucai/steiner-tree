#pragma once

#include "Coordinate.h"
#include "flute.h"
#include <vector>

using std::pair;
using std::vector;

class FluteAdapter {
public:
  FluteAdapter() = default;
  ~FluteAdapter() = default;

  Flute::Tree build_flute_tree(const std::vector<Coordinate<int>> &coord_list);

  int get_index(const Flute::Tree &tree, Coordinate<int> coord) const;
  int get_root_index(const Flute::Tree &tree) const;
};