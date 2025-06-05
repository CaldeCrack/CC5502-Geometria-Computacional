#include <cmath>
#include <iostream>

template <typename T> class Point {
private:
  T x = 0, y = 0, z = 0;

public:
  // Constructors
  Point() : x(0), y(0), z(0) {}
  Point(T x, T y) : x(x), y(y) {}
  Point(T x, T y, T z) : x(x), y(y), z(z) {}
  Point(const Point<T> &p) : x(p.x), y(p.y), z(p.z) {}

  // Getter
  const T &operator[](int i) const {
    if (i == 0)
      return x;
    else if (i == 1)
      return y;
    else
      return z;
  }

  // Distance operations
  double dist(const Point<T> &p) {
    double dx = static_cast<double>(x - p.x);
    double dy = static_cast<double>(y - p.y);
    double dz = static_cast<double>(z - p.z);
    return std::sqrt(dx * dx + dy * dy + dz * dz);
  }

  // Overload operators
  Point<T> operator+(const Point<T> &p) {
    return Point(x + p.x, y + p.y, z + p.z);
  }
  Point<T> operator*(T scalar) const {
    return Point(scalar * x, scalar * y, scalar * z);
  }
  friend Point<T> operator*(T scalar, const Point<T> &p) { return p * scalar; }
  bool operator==(const Point<T> &p) const {
    return (x == p.x) && (y == p.y) && (z == p.z);
  }
  bool operator<(const Point<T> &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
  friend std::ostream &operator<<(std::ostream &os, const Point<T> &p) {
    if (p.z)
      os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    else
      os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};
