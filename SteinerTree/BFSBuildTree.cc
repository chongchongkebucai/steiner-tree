#include "BFSBuildTree.h"

Tree BFSBuildTree::build_tree(const Flute::Tree &flute_tree, int root_index) {
  auto flute_node_number = flute_tree.deg * 2 - 2;

  // build an graph represented by adjacency list according to flute tree
  vector<vector<int>> graph(flute_node_number);
  for (int cur = 0; cur < flute_node_number; ++cur) {
    auto flute_node = flute_tree.branch[cur];
    auto next = flute_node.n;

    graph[cur].push_back(next);
    graph[next].push_back(cur);
  }

  // recursive build tree
  Tree tree = nullptr;
  if (flute_node_number > 0) {
    vector<bool> visited(flute_node_number, false);
    tree = depth_first_build_tree(flute_tree, graph, visited, root_index);
    tree->_father = tree;
  }

  // remove steiner node that duplicate the coordinate with original nodes
  remove_redundant_steiner_node(tree);
  return tree;
}

Tree BFSBuildTree::depth_first_build_tree(const Flute::Tree &flute_tree,
                                          const vector<vector<int>> &graph,
                                          vector<bool> &visited, int index) {
  Tree root = new TreeNode();
  // add coordinate information
  auto flute_node = flute_tree.branch[index];
  auto coord_x = flute_node.x;
  auto coord_y = flute_node.y;
  Coordinate<int> coord(coord_x, coord_y);

  root->_data = coord;
  visited[index] = true;

  // add child and father information
  auto &adjacents_index = graph[index];
  for (auto next_index : adjacents_index) {
    if (visited[next_index] == false) {
      auto child =
          depth_first_build_tree(flute_tree, graph, visited, next_index);
      root->_childs.push_back(child);
      child->_father = root;
    }
  }
  return root;
}

// void BFSBuildTree::remove_redundant_steiner_node(Tree tree) {
//   auto root_coord = tree->_data;
//   auto &childs = tree->_childs;

//   auto iter = childs.begin();
//   while (iter != childs.end()) {
//     auto child_coord = (*iter)->_data;
//     if (root_coord == child_coord) {
//       auto next_iter = iter + 1;
//       auto grandsons = (*iter)->_childs;
//       for (auto grandson : grandsons) {
//         childs.insert(next_iter, grandson);
//         grandson->_father = tree;
//       }
//       next_iter = iter + 1;
//       // free child node and delete child pointer
//       delete (*iter);
//       childs.erase(iter);
//       // change the iterator
//       iter = next_iter;
//     } else {
//       ++iter;
//     }
//   }

//   childs = tree->_childs;
//   for (auto child : childs) {
//     remove_redundant_steiner_node(child);
//   }
// }




void BFSBuildTree::remove_redundant_steiner_node(Tree tree) {
  auto root_coord = tree->_data;
  auto &childs = tree->_childs;

  for(auto child:childs){
    auto child_coord = child->_data;
    if(root_coord == child_coord){
      
    }    
  }

  auto iter = childs.begin();
  while (iter != childs.end()) {
    auto child_coord = (*iter)->_data;
    
    if (root_coord == child_coord) {
      auto next_iter = iter + 1;
      auto grandsons = (*iter)->_childs;
      for (auto grandson : grandsons) {
        childs.insert(next_iter, grandson);
        grandson->_father = tree;
      }
      next_iter = iter + 1;
      // free child node and delete child pointer
      delete (*iter);
      childs.erase(iter);
      // change the iterator
      iter = next_iter;
    } else {
      ++iter;
    }
  }

  childs = tree->_childs;
  for (auto child : childs) {
    remove_redundant_steiner_node(child);
  }
}