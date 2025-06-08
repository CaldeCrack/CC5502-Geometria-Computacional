#include "CHEstrategies.cpp"

template <typename T> class GiftWrappingAlgorithm : public CHEstrategies<T> {
public:
  Polygon<T> apply(Point<T> cloud[], int length) {
    vector<Point<T>> points;
    int l = 0;

    // Hallar punto más a la izquierda
    for (int i = 1; i < length; ++i)
      if (cloud[i][1] < cloud[l][1])
        l = i;

    // Moverse CCW hasta volver al inicio
    int p = l, q;
    do {
      q = (p + 1) % length;
      for (int i = 0; i < length; ++i) {
        if (i == p)
          continue;

        if (CHEstrategies<T>::orient(cloud[p], cloud[i], cloud[q]) == CCW)
          q = i;
      }

      points.push_back(cloud[q]);
      p = q;
    } while (p != l);

    Polygon<T> out(points);
    return out;
  }
};
