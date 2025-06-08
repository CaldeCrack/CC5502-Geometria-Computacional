#include "GeneratePoints.cpp"
#include <algorithm>
#include <random>

template <typename T> class RandomPoints : public GeneratePoints<T> {
public:
  Point<T> *generate(int n, double k, T lower = (T)-500.0, T upper = (T)500.0) {
    Point<T> *points = new Point<T>[n];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dist(lower, upper);

    if constexpr (std::is_floating_point<T>::value) { // xd
      std::uniform_real_distribution<T> dist(lower, upper);
      for (int i = 0; i < n; ++i) {
        T x = dist(gen);
        T y = dist(gen);
        points[i] = Point<T>(x, y);
      }
    } else {
      std::uniform_int_distribution<T> dist(lower, upper);
      for (int i = 0; i < n; ++i) {
        T x = dist(gen);
        T y = dist(gen);
        points[i] = Point<T>(x, y);
      }
    }

    std::shuffle(points, points + n, gen);
    return points;
  }
};
