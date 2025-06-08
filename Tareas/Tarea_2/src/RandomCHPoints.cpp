#include "GeneratePoints.cpp"
#include <algorithm>
#include <random>

template <typename T> class RandomCHPoints : public GeneratePoints<T> {
private:
  void circlePoints(Point<T> *points, int n, T r, std::mt19937 &gen) {
    if constexpr (std::is_floating_point<T>::value) {
      std::uniform_real_distribution<T> dist_ang(0, 2 * M_PI);
      for (int i = 0; i < n; ++i) {
        T ang = dist_ang(gen);
        points[i] = Point<T>(r * std::cos(ang), r * std::sin(ang));
      }
    } else {
      std::uniform_int_distribution<T> dist_ang(0, 2 * M_PI);
      for (int i = 0; i < n; ++i) {
        T ang = dist_ang(gen);
        points[i] = Point<T>(r * std::cos(ang), r * std::sin(ang));
      }
    }
  }

  void innerCirclePoints(Point<T> *points, int offset, int n, T radius,
                         std::mt19937 &gen) {
    if constexpr (std::is_floating_point<T>::value) {
      std::uniform_real_distribution<T> dist_ang(0, 2 * M_PI);
      std::uniform_real_distribution<T> dist_r(0, 1);
      for (int i = 0; i < n; ++i) {
        T ang = dist_ang(gen);
        T r = radius * std::sqrt(dist_r(gen));
        points[offset + i] = Point<T>(r * std::cos(ang), r * std::sin(ang));
      }
    } else {
      std::uniform_int_distribution<T> dist_ang(0, 2 * M_PI);
      std::uniform_int_distribution<T> dist_r(0, 1);
      for (int i = 0; i < n; ++i) {
        T ang = dist_ang(gen);
        T r = radius * std::sqrt(dist_r(gen));
        points[offset + i] = Point<T>(r * std::cos(ang), r * std::sin(ang));
      }
    }
  }

public:
  Point<T> *generate(int n, double k, T lower = (T)-500.0, T upper = (T)500.0) {
    int n_hull = static_cast<int>(std::round(k * n));
    int n_inner = n - n_hull;
    Point<T> *points = new Point<T>[n];

    std::random_device rd;
    std::mt19937 gen(rd());

    T r = (upper - lower) / 2;

    circlePoints(points, n_hull, r, gen);
    innerCirclePoints(points, n_hull, n_inner, r * 0.98, gen);

    std::shuffle(points, points + n, gen);
    return points;
  }
};
