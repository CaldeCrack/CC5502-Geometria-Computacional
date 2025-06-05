#include "GeneratePoints.cpp"
#include <algorithm>
#include <random>

template <typename T> class RandomCHPoints : public GeneratePoints<T> {
private:
  void circlePoints(Point<T> *points, int n, T cx, T cy, T r,
                    std::mt19937 &gen) {
    std::uniform_real_distribution<T> dist_ang(0, 2 * M_PI);
    for (int i = 0; i < n; ++i) {
      T ang = dist_ang(gen);
      points[i] = Point<T>(cx + r * std::cos(ang), cy + r * std::sin(ang));
    }
  }

  void innerCirclePoints(Point<T> *points, int offset, int n, T cx, T cy,
                         T radius, std::mt19937 &gen) {
    std::uniform_real_distribution<T> dist_ang(0, 2 * M_PI);
    std::uniform_real_distribution<T> dist_r(0, 1);
    for (int i = 0; i < n; ++i) {
      T ang = dist_ang(gen);
      T r = radius * std::sqrt(dist_r(gen));
      points[offset + i] =
          Point<T>(cx + r * std::cos(ang), cy + r * std::sin(ang));
    }
  }

public:
  Point<T> *generate(int n, double k, T min_val, T max_val) {
    if (k < 0.0 || k > 1.0)
      k = 0.2;

    int n_hull = static_cast<int>(std::round(k * n));
    int n_inner = n - n_hull;
    Point<T> *points = new Point<T>[n];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dist_pos(min_val, max_val);

    T cx = dist_pos(gen);
    T cy = dist_pos(gen);
    T r = (max_val - min_val) / 4;

    circlePoints(points, n_hull, cx, cy, r, gen);
    innerCirclePoints(points, n_hull, n_inner, cx, cy, r * 0.95, gen);

    std::shuffle(points, points + n, gen);
    return points;
  }
};
