#pragma once
#include "Point.cpp"

template <typename T> class GeneratePoints {
public:
  Point<T> *generate(int n, double k, T lower = (T)-500.0, T upper = (T)500.0);
};
