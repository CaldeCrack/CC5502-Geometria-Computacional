#include "CHEstrategies.cpp"

template <typename T> class GiftWrappingAlgorithm : public CHEstrategies<T> {
public:
  // // 0: colineal | 1: CW | 2: CCW
  // int orientation(Point<T> p, Point<T> q, Point<T> r) {
  //   int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  //   if (val == 0)
  //     return 0;
  //   return (val > 0) ? 1 : 2;
  // }

  Polygon<T> apply(Point<T> cloud[]) {
    int length = std::size(cloud), l = 0;
    vector<Point<T>> points;

    for (int i = 1; i < length; ++i)
      if (cloud[i].y < cloud[l].y ||
          (cloud[i].y == cloud[l].y && cloud[i].x < cloud[l].x))
        l = i;

    int p = l, q;
    points.push_back(cloud[p]);
    do {
      q = (p + 1) % length;
      for (int i = 0; i < length; ++i)
        if (orientation(cloud[p], cloud[i], cloud[q]) == 2)
          q = i;

      points.push_back(cloud[q]);
      p = q;
    } while (p != l);

    Polygon<T> out(points);
    return out;
  };
};
