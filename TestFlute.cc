#include "Coordinate.h"
#include "FluteAdapter.h"
#include "SteinerTree.h"
#include <iostream>
#include <vector>

using namespace std;

void print_tree(Tree tree);
Coordinate<int> compute_center_of_mass(const vector<Coordinate<int>> &coords);

int main() {
  vector<Coordinate<int>> coords{Coordinate<int>(0, 0), Coordinate<int>(2, 0),
                                 Coordinate<int>(2, 1), Coordinate<int>(0, 2),
                                 Coordinate<int>(3, 0)};

  // FluteAdapter flute;
  // Flute::Tree flute_tree = flute.build_flute_tree(coords);
  // Flute::printtree(flute_tree);
  // Flute::plottree(flute_tree);

  SteinerTree builder;
  auto root_coord = compute_center_of_mass(coords);
  coords.push_back(root_coord);
  cout << "(" << root_coord.get_x() << ", " << root_coord.get_y() << ")"
       << endl;
  Tree tree = builder.build_steiner_tree(coords, root_coord);
  print_tree(tree);

  return 0;
}

Coordinate<int> compute_center_of_mass(const vector<Coordinate<int>> &coords) {
  double sum_coord_x = 0.0;
  double sum_coord_y = 0.0;

  for (auto &coord : coords) {
    sum_coord_x += coord.get_x();
    sum_coord_y += coord.get_y();
  }

  auto size = coords.size();
  int coord_x = static_cast<int>(sum_coord_x / size);
  int coord_y = static_cast<int>(sum_coord_y / size);

  return Coordinate<int>(coord_x, coord_y);
}

void print_tree(Tree tree) {
  if (!tree)
    return;
  auto root_coord = tree->_data;
  auto &childs = tree->_childs;
  for (auto child : childs) {
    auto child_coord = child->_data;
    cout << "(" << root_coord.get_x() << "," << root_coord.get_y() << ") --> "
         << "(" << child_coord.get_x() << "," << child_coord.get_y() << ")  ";
  }
  cout << endl;

  for (auto child : childs) {
    print_tree(child);
  }
}