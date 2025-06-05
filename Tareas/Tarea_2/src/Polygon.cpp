#include "Vector.cpp"
#include <algorithm>
#include <vector>

using namespace std;

template <typename T> class Polygon {
private:
  vector<Point<T>> points;

public:
  // Constructors
  Polygon(vector<Point<T>> &v) {
    points.insert(points.end(), v.begin(), v.end());
  }

  // Polygon operations
  int length() const { return points.size(); }
  double area2() {
    double area_2 = 0;
    int n = this->length();
    for (int i = 0; i < n; i++)
      area_2 += points[i][0] * points[(i + 1) % n][1] -
                points[i][1] * points[(i + 1) % n][0];
    return area_2;
  }
  double area() { return this->area2() / 2; }
  bool CCW() { return this->area2() > 0; }
  void CW2CCW() {
    if (!this->CCW())
      reverse(points.begin(), points.end());
  }

  // Overload operators
  const Point<T> &operator[](int i) const { return points[i]; }
  friend std::ostream &operator<<(std::ostream &os, const Polygon<T> &p) {
    os << "[";
    int n = p.length();
    for (int i = 0; i < n; i++) {
      os << p[i];
      if (i < n - 1)
        os << ", ";
    }
    os << "]";
    return os;
  }
};
