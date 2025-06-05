add_subdirectory(extern)
set(TEST_SOURCES
  Point.cpp
  Vector.cpp
  Polygon.cpp
)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE GTest::gtest_main geometria)

include(GoogleTest)
gtest_discover_tests(tests)

