#include "Polygon.cpp"

template <typename T> class CHEstrategies {
public:
  // 0: colineal | 1: CW | 2: CCW
  int orientation(Point<T> p, Point<T> q, Point<T> r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
      return 0;
    return (val > 0) ? 1 : 2;
  }

  Polygon<T> apply(Point<T> cloud[]);
};
