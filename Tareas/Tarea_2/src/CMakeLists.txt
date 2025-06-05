add_library(geometria STATIC
  Point.cpp
  Vector.cpp
  Polygon.cpp
)

add_executable(main main.cpp)
target_link_libraries(main geometria)

