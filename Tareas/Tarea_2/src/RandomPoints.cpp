#include "GeneratePoints.cpp"
#include <random>

template <typename T> class RandomPoints : public GeneratePoints<T> {
public:
  Point<T> *generate(int n, double k, T min_val, T max_val) {
    Point<T> *points = new Point<T>[n];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dist(min_val, max_val);

    for (int i = 0; i < n; ++i) {
      T x = dist(gen);
      T y = dist(gen);
      points[i] = Point<T>(x, y);
    }

    return points;
  }
};
