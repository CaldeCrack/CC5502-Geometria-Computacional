#include "CHEstrategies.cpp"

template <typename T> class GiftWrappingAlgorithm : public CHEstrategies<T> {
public:
  Polygon<T> apply(Point<T> cloud[]) {
    int length = std::size(cloud);
    std::sort(std::begin(cloud), std::end(cloud));
    vector<Point<T>> upper, lower, convex_hull;

    // Lower Hull
    for (int i = 0; i < length; ++i) {
      int n = lower.size();
      while (n >= 2 && (orientation(lower[n - 2], lower[n - 1], cloud[i]) != 2))
        lower.pop_back();
      lower.push_back(cloud[i]);
    }

    // Upper Hull
    for (int i = length - 1; i >= 0; --i) {
      int n = upper.size();
      while (n >= 2 && (orientation(upper[n - 2], upper[n - 1], cloud[i]) != 2))
        upper.pop_back();
      upper.push_back(cloud[i]);
    }

    lower.pop_back();
    upper.pop_back();

    convex_hull.insert(convex_hull.end(), lower.begin(), lower.end());
    convex_hull.insert(convex_hull.end(), upper.begin(), upper.end());
    Polygon<T> out(convex_hull);
    return out;
  }
};
