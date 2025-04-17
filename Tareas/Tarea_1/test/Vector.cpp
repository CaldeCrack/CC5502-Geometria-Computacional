#include "../src/Vector.cpp"
#include <gtest/gtest.h>

using namespace std;

TEST(VectorTest, ConstructorFromCoordinates) {
  Vector<int> v(3, 4);
  EXPECT_EQ(v, Vector<int>(3, 4));
}

TEST(VectorTest, ConstructorFromPoint) {
  Punto<int> p(1, 2, 3);
  Vector<int> v(p);
  EXPECT_FALSE(v == Vector<int>(1, 2));
}

TEST(VectorTest, CopyConstructor) {
  Vector<int> v1(2, 3);
  Vector<int> v2(v1);
  EXPECT_EQ(v1, v2);
}

TEST(VectorTest, Magnitude) {
  Vector<int> v(Punto<int>(2, 3, 6));
  EXPECT_DOUBLE_EQ(v.magnitude(), std::sqrt(49.0));
}

TEST(VectorTest, DotProduct) {
  Vector<int> v1(Punto<int>(1, 2, 3));
  Vector<int> v2(Punto<int>(4, -5, 6));
  int result = v1.dot_product(v2);
  EXPECT_EQ(result, 12);
}

TEST(VectorTest, CrossProduct) {
  Vector<int> v1(Punto<int>(1, 0, 0));
  Vector<int> v2(Punto<int>(0, 1, 0));
  Vector<int> cross = v1.cross_product(v2);
  Vector<int> expected(Punto<int>(0, 0, 1));
  EXPECT_EQ(cross, expected);
}

TEST(VectorTest, Addition) {
  Vector<int> v1(Punto<int>(1, 2, 3));
  Vector<int> v2(Punto<int>(4, 5, 6));
  Vector<int> sum = v1 + v2;
  Vector<int> expected(Punto<int>(5, 7, 9));
  EXPECT_EQ(sum, expected);
}

TEST(VectorTest, Equality) {
  Vector<int> v1(Punto<int>(1, 2, 3));
  Vector<int> v2(Punto<int>(1, 2, 3));
  Vector<int> v3(Punto<int>(3, 2, 1));
  EXPECT_TRUE(v1 == v2);
  EXPECT_FALSE(v1 == v3);
}

TEST(VectorTest, ScalarMultiplication) {
  Vector<int> v(Punto<int>(1, 2, 3));
  Vector<int> scaled1 = v * 2;
  Vector<int> scaled2 = 2 * v;
  Vector<int> expected(Punto<int>(2, 4, 6));
  EXPECT_EQ(scaled1, expected);
  EXPECT_EQ(scaled2, expected);
}
