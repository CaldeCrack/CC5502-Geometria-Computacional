#include "GeneratePoints.cpp"
#include <algorithm>
#include <random>

template <typename T> class RandomColinealPoints : public GeneratePoints<T> {
private:
  void rectanglePoints(Point<T> *points, int n, T lower, T upper,
                       std::mt19937 &gen) {
    if constexpr (std::is_floating_point<T>::value) {
      std::uniform_real_distribution<T> dist_x(lower, upper);
      std::uniform_real_distribution<T> dist_y(lower, upper);

      for (int i = 0; i < n; ++i) {
        int side = i % 4;
        switch (side) {
        case 0:
          points[i] = Point<T>(dist_x(gen), upper);
          break;
        case 1:
          points[i] = Point<T>(dist_x(gen), lower);
          break;
        case 2:
          points[i] = Point<T>(lower, dist_y(gen));
          break;
        case 3:
          points[i] = Point<T>(upper, dist_y(gen));
          break;
        }
      }
    } else {
      std::uniform_int_distribution<T> dist_x(lower, upper);
      std::uniform_int_distribution<T> dist_y(lower, upper);

      for (int i = 0; i < n; ++i) {
        int side = i % 4;
        switch (side) {
        case 0:
          points[i] = Point<T>(dist_x(gen), upper);
          break;
        case 1:
          points[i] = Point<T>(dist_x(gen), lower);
          break;
        case 2:
          points[i] = Point<T>(lower, dist_y(gen));
          break;
        case 3:
          points[i] = Point<T>(upper, dist_y(gen));
          break;
        }
      }
    }
  }

  void innerRectanglePoints(Point<T> *points, int offset, int n, T lower,
                            T upper, std::mt19937 &gen) {
    if constexpr (std::is_floating_point<T>::value) {
      std::uniform_real_distribution<T> dist_x(lower, upper);
      std::uniform_real_distribution<T> dist_y(lower, upper);

      for (int i = 0; i < n; ++i)
        points[offset + i] = Point<T>(dist_x(gen), dist_y(gen));
    } else {
      std::uniform_int_distribution<T> dist_x(lower + 1, upper - 1);
      std::uniform_int_distribution<T> dist_y(lower + 1, upper - 1);

      for (int i = 0; i < n; ++i)
        points[offset + i] = Point<T>(dist_x(gen), dist_y(gen));
    }
  }

public:
  Point<T> *generate(int n, double k, T lower = (T)-500.0, T upper = (T)500.0) {
    int n_hull = static_cast<int>(std::round(k * n));
    int n_inner = n - n_hull;

    Point<T> *points = new Point<T>[n];

    std::random_device rd;
    std::mt19937 gen(rd());

    rectanglePoints(points, n_hull, lower, upper, gen);
    innerRectanglePoints(points, n_hull, n_inner, lower, upper, gen);

    std::shuffle(points, points + n, gen);
    return points;
  }
};
