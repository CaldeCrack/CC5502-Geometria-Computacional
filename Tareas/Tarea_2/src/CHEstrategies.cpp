#pragma once
#include "Polygon.cpp"

enum orientation {
  COLINEAL,
  CW,
  CCW,
};

template <typename T> class CHEstrategies {
public:
  orientation orient(Point<T> p, Point<T> q, Point<T> r) {
    T val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);

    if (!val)
      return COLINEAL;
    return (val > 0) ? CW : CCW;
  }

  Polygon<T> apply(Point<T> cloud[], int length);
};
