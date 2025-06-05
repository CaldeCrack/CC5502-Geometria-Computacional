#include "../src/Polygon.cpp"
#include <gtest/gtest.h>

using namespace std;

template <typename T>
std::vector<Point<T>> squareCW = {Point<T>(0, 0), Point<T>(0, 2),
                                  Point<T>(2, 2), Point<T>(2, 0)};

TEST(PolygonTest, ConstructorAndIndex) {
  Polygon<int> poly(squareCW<int>);
  EXPECT_EQ(poly[0], Point<int>(0, 0));
  EXPECT_EQ(poly[1], Point<int>(0, 2));
  EXPECT_EQ(poly[2], Point<int>(2, 2));
  EXPECT_EQ(poly[3], Point<int>(2, 0));
}

TEST(PolygonTest, Length) {
  Polygon<int> poly(squareCW<int>);
  EXPECT_EQ(poly.length(), 4);
}

TEST(PolygonTest, Area) {
  Polygon<int> poly(squareCW<int>);
  EXPECT_DOUBLE_EQ(poly.area2(), -8.0);
  EXPECT_DOUBLE_EQ(poly.area(), -4.0);
}

TEST(PolygonTest, CCWDetection) {
  Polygon<int> poly(squareCW<int>);
  EXPECT_FALSE(poly.CCW());
}

TEST(PolygonTest, CW2CCW) {
  Polygon<int> poly(squareCW<int>);
  EXPECT_FALSE(poly.CCW());

  poly.CW2CCW();
  EXPECT_TRUE(poly.CCW());

  EXPECT_DOUBLE_EQ(poly.area2(), 8.0);
}
