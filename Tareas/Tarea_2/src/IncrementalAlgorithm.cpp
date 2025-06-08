#include "CHEstrategies.cpp"

template <typename T> class IncrementalAlgorithm : public CHEstrategies<T> {
public:
  Polygon<T> apply(Point<T> cloud[], int length) {
    std::sort(cloud, cloud + length);
    vector<Point<T>> upper, lower, convex_hull;

    // Lower Hull
    for (int i = 0; i < length; ++i) {
      int n = lower.size();
      while (n >= 2 && (CHEstrategies<T>::orient(lower[n - 2], lower[n - 1],
                                                 cloud[i]) != CCW)) {
        lower.pop_back();
        n--;
      }
      lower.push_back(cloud[i]);
    }

    // Upper Hull
    for (int i = length - 1; i >= 0; --i) {
      int n = upper.size();
      while (n >= 2 && (CHEstrategies<T>::orient(upper[n - 2], upper[n - 1],
                                                 cloud[i]) != CCW)) {
        upper.pop_back();
        n--;
      }
      upper.push_back(cloud[i]);
    }

    // Combinar resultados
    upper.pop_back();
    lower.pop_back();

    convex_hull.insert(convex_hull.end(), upper.begin(), upper.end());
    convex_hull.insert(convex_hull.end(), lower.begin(), lower.end());
    Polygon<T> out(convex_hull);
    return out;
  }
};
