#include <cmath>
#include <iostream>

template <typename T> class Punto {
private:
  T x = 0, y = 0, z = 0;

public:
  // Constructors
  Punto() : x(0), y(0), z(0) {}
  Punto(T x, T y) : x(x), y(y) {}
  Punto(T x, T y, T z) : x(x), y(y), z(z) {}
  Punto(const Punto<T> &p) : x(p.x), y(p.y), z(p.z) {}

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
  double dist(const Punto<T> &p) {
    double dx = static_cast<double>(x - p.x);
    double dy = static_cast<double>(y - p.y);
    double dz = static_cast<double>(z - p.z);
    return std::sqrt(dx * dx + dy * dy + dz * dz);
  }

  // Overload operators
  Punto<T> operator+(const Punto<T> &p) {
    return Punto(x + p.x, y + p.y, z + p.z);
  }
  Punto<T> operator*(T scalar) const {
    return Punto(scalar * x, scalar * y, scalar * z);
  }
  friend Punto<T> operator*(T scalar, const Punto<T> &p) { return p * scalar; }
  bool operator==(const Punto<T> &p) const {
    return (x == p.x) && (y == p.y) && (z == p.z);
  }
  friend std::ostream &operator<<(std::ostream &os, const Punto<T> &p) {
    if (p.z)
      os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    else
      os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};
