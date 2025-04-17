#include "../src/Punto.cpp"
#include <cmath>
#include <gtest/gtest.h>

using namespace std;

// Getter is being tested in every coordinate access done through testing

TEST(PuntoTest, DefaultConstructor) {
  Punto<int> p;
  EXPECT_EQ(p[0], 0);
  EXPECT_EQ(p[1], 0);
  EXPECT_EQ(p[2], 0);
}

TEST(PuntoTest, Constructor2D) {
  Punto<int> p(1, 2);
  EXPECT_EQ(p[0], 1);
  EXPECT_EQ(p[1], 2);
  EXPECT_EQ(p[2], 0);
}

TEST(PuntoTest, Constructor3D) {
  Punto<int> p(1, -2, 3);
  EXPECT_EQ(p[0], 1);
  EXPECT_EQ(p[1], -2);
  EXPECT_EQ(p[2], 3);
}

TEST(PuntoTest, CopyConstructor) {
  Punto<int> p1(5, 6, 7);
  Punto<int> p2(p1);
  EXPECT_EQ(p2[0], 5);
  EXPECT_EQ(p2[1], 6);
  EXPECT_EQ(p2[2], 7);
}

TEST(PuntoTest, Distance) {
  Punto<int> p1(1, 0, 3);
  Punto<int> p2(4, 6, -1);
  EXPECT_DOUBLE_EQ(p1.dist(p2), std::sqrt(61));
}

TEST(PuntoTest, Addition) {
  Punto<int> p1(1, 2, 3);
  Punto<int> p2(4, 5, 6);
  Punto<int> result = p1 + p2;
  EXPECT_EQ(result[0], 5);
  EXPECT_EQ(result[1], 7);
  EXPECT_EQ(result[2], 9);
}

TEST(PuntoTest, ScalarMultiplication) {
  Punto<int> p(2, 3, 4);
  Punto<int> resultLeft = 2 * p;
  Punto<int> resultRight = p * 2;
  EXPECT_EQ(resultRight[0], 4);
  EXPECT_EQ(resultRight[1], 6);
  EXPECT_EQ(resultRight[2], 8);
  EXPECT_EQ(resultLeft[0], 4);
  EXPECT_EQ(resultLeft[1], 6);
  EXPECT_EQ(resultLeft[2], 8);
}

TEST(PuntoTest, Equality) {
  Punto<int> p1(1, 2, 3);
  Punto<int> p2(1, 2, 3);
  Punto<int> p3(1, 2, 4);
  EXPECT_TRUE(p1 == p2);
  EXPECT_FALSE(p1 == p3);
}
