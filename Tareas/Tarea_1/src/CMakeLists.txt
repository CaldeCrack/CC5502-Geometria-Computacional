add_library(punto STATIC Punto.cpp)
add_library(vector STATIC Vector.cpp)

add_executable(main main.cpp)
target_link_libraries(main punto vector)

