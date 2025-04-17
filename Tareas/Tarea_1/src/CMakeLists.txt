add_library(geometria STATIC
  Punto.cpp
  Vector.cpp
  Poligono.cpp
)

add_executable(main main.cpp)
target_link_libraries(main geometria)

