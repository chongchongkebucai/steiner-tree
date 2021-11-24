#pragma once

template <typename T> class Coordinate {
public:
  Coordinate() = default;
  Coordinate(int x, int y) : _x(x), _y(y) {}
  ~Coordinate() = default;

  // getter
  T get_x() const { return _x; }
  T get_y() const { return _y; }

  // setter
  void set_x(T x) { _x = x; }
  void set_y(T y) { _y = y; }

  // operator
  bool operator==(const Coordinate &coord) const;
  bool operator!=(const Coordinate<T> &coord) const;

private:
  T _x;
  T _y;
};

template <typename T>
bool Coordinate<T>::operator==(const Coordinate<T> &coord) const {
  return _x == coord.get_x() && _y == coord.get_y();
}

template <typename T>
bool Coordinate<T>::operator!=(const Coordinate<T> &coord) const {
  return _x != coord.get_x() || _y != coord.get_y();
}