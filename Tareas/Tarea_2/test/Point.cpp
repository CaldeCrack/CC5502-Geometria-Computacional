#include "../src/Point.cpp"
#include <cmath>
#include <gtest/gtest.h>

using namespace std;

// Getter is being tested in every coordinate access done through testing

TEST(PointTest, DefaultConstructor) {
  Point<int> p;
  EXPECT_EQ(p[0], 0);
  EXPECT_EQ(p[1], 0);
  EXPECT_EQ(p[2], 0);
}

TEST(PointTest, Constructor2D) {
  Point<int> p(1, 2);
  EXPECT_EQ(p[0], 1);
  EXPECT_EQ(p[1], 2);
  EXPECT_EQ(p[2], 0);
}

TEST(PointTest, Constructor3D) {
  Point<int> p(1, -2, 3);
  EXPECT_EQ(p[0], 1);
  EXPECT_EQ(p[1], -2);
  EXPECT_EQ(p[2], 3);
}

TEST(PointTest, CopyConstructor) {
  Point<int> p1(5, 6, 7);
  Point<int> p2(p1);
  EXPECT_EQ(p2[0], 5);
  EXPECT_EQ(p2[1], 6);
  EXPECT_EQ(p2[2], 7);
}

TEST(PointTest, Distance) {
  Point<int> p1(1, 0, 3);
  Point<int> p2(4, 6, -1);
  EXPECT_DOUBLE_EQ(p1.dist(p2), std::sqrt(61));
}

TEST(PointTest, Addition) {
  Point<int> p1(1, 2, 3);
  Point<int> p2(4, 5, 6);
  Point<int> result = p1 + p2;
  EXPECT_EQ(result[0], 5);
  EXPECT_EQ(result[1], 7);
  EXPECT_EQ(result[2], 9);
}

TEST(PointTest, ScalarMultiplication) {
  Point<int> p(2, 3, 4);
  Point<int> resultLeft = 2 * p;
  Point<int> resultRight = p * 2;
  EXPECT_EQ(resultRight[0], 4);
  EXPECT_EQ(resultRight[1], 6);
  EXPECT_EQ(resultRight[2], 8);
  EXPECT_EQ(resultLeft[0], 4);
  EXPECT_EQ(resultLeft[1], 6);
  EXPECT_EQ(resultLeft[2], 8);
}

TEST(PointTest, Equality) {
  Point<int> p1(1, 2, 3);
  Point<int> p2(1, 2, 3);
  Point<int> p3(1, 2, 4);
  EXPECT_TRUE(p1 == p2);
  EXPECT_FALSE(p1 == p3);
}

// Compares x coordinate then y coordinate
TEST(PointTest, Comparison) {
  Point<int> p1(1, 2, 3);
  Point<int> p2(1, 2, 3);
  Point<int> p3(0, 2, 4);
  Point<int> p4(1, 1, -1);
  EXPECT_FALSE(p1 < p2);
  EXPECT_TRUE(p3 < p1);
  EXPECT_TRUE(p4 < p1);
}
