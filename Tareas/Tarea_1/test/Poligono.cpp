#include "../src/Poligono.cpp"
#include <gtest/gtest.h>

using namespace std;

template <typename T>
std::vector<Punto<T>> squareCW = {Punto<T>(0, 0), Punto<T>(0, 2),
                                  Punto<T>(2, 2), Punto<T>(2, 0)};

TEST(PoligonoTest, ConstructorAndIndex) {
  Poligono<int> poly(squareCW<int>);
  EXPECT_EQ(poly[0], Punto<int>(0, 0));
  EXPECT_EQ(poly[1], Punto<int>(0, 2));
  EXPECT_EQ(poly[2], Punto<int>(2, 2));
  EXPECT_EQ(poly[3], Punto<int>(2, 0));
}

TEST(PoligonoTest, Length) {
  Poligono<int> poly(squareCW<int>);
  EXPECT_EQ(poly.length(), 4);
}

TEST(PoligonoTest, Area) {
  Poligono<int> poly(squareCW<int>);
  EXPECT_DOUBLE_EQ(poly.area2(), -8.0);
  EXPECT_DOUBLE_EQ(poly.area(), -4.0);
}

TEST(PoligonoTest, CCWDetection) {
  Poligono<int> poly(squareCW<int>);
  EXPECT_FALSE(poly.CCW());
}

TEST(PoligonoTest, CW2CCW) {
  Poligono<int> poly(squareCW<int>);
  EXPECT_FALSE(poly.CCW());

  poly.CW2CCW();
  EXPECT_TRUE(poly.CCW());

  EXPECT_DOUBLE_EQ(poly.area2(), 8.0);
}
