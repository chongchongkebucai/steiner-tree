#include "FluteAdapter.h"
#include <stdlib.h>

Flute::Tree
FluteAdapter::build_flute_tree(const std::vector<Coordinate<int>> &coord_list) {
  int coord_num = coord_list.size();

  // 将保持在vector中的数据拷贝到使用C语言分配的动态内存中
  Flute::DTYPE *x = (Flute::DTYPE *)malloc(sizeof(Flute::DTYPE) * coord_num);
  Flute::DTYPE *y = (Flute::DTYPE *)malloc(sizeof(Flute::DTYPE) * coord_num);
  for (int i = 0; i < coord_num; i++) {
    auto &coord = coord_list[i];
    x[i] = coord.get_x();
    y[i] = coord.get_y();
  }

  // 构建查找表， 后续可以定义一个bool变量判断是否已经创建过查找表了
  Flute::readLUT();

  // 利用flute库构建steiner树
  Flute::Tree tree = Flute::flute(coord_num, x, y, FLUTE_ACCURACY);

  // 释放内存
  free(x);
  free(y);

  return tree;
}

int FluteAdapter::get_index(const Flute::Tree &tree,
                            Coordinate<int> coord) const {
  for (int idx = 0; idx < tree.deg; ++idx) {
    auto &node = tree.branch[idx];
    if (coord.get_x() == node.x && coord.get_y() == node.y) {
      return idx;
    }
  }
  return -1;
}

int FluteAdapter::get_root_index(const Flute::Tree &tree) const {
  int node_number = tree.deg * 2 - 2;
  for (int cur = 0; cur < node_number; ++cur) {
    auto node = tree.branch[cur];
    auto next = node.n;
    if (cur == next) {
      return cur;
    }
  }
  return -1;
}