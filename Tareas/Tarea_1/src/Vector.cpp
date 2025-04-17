#include "Punto.cpp"

template <typename T> class Vector {
private:
  Punto<T> origin;
  Punto<T> c;

public:
  // Constructors
  Vector(T x, T y) : c(Punto<T>(x, y)) {}
  Vector(const Punto<T> &p) : c(Punto<T>(p[0], p[1], p[2])) {}
  Vector(const Vector<T> &v) : c(v.c) {}

  // Vector operations
  double magnitude() { return c.dist(origin); }
  T dot_product(const Vector<T> &v) {
    return (c[0] * v.c[0]) + (c[1] * v.c[1]) + (c[2] * v.c[2]);
  }
  Vector<T> cross_product(const Vector<T> &v) {
    return Vector(Punto(c[1] * v.c[2] - c[2] * v.c[1],
                        c[2] * v.c[0] - c[0] * v.c[2],
                        c[0] * v.c[1] - c[1] * v.c[0]));
  }

  // Overload operators
  Vector<T> operator+(const Vector<T> &v) { return Vector(c + v.c); }
  bool operator==(const Vector<T> &v) const { return c == v.c; }
  Vector<T> operator*(T scalar) const { return Vector(scalar * c); }
  friend Vector<T> operator*(T scalar, const Vector<T> &v) {
    return v * scalar;
  }
  friend std::ostream &operator<<(std::ostream &os, const Vector<T> &v) {
    os << v.c;
    return os;
  }
};
