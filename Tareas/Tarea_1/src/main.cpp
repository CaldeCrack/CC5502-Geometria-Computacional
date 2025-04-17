#include "Poligono.cpp"

using namespace std;

int main() {
  Punto<double> p1(1.1, 2.2);
  Punto<double> p2(4.4, 5.5);

  cout << "--- Puntos ---\n";
  cout << "Point A: " << p1 << "\n";
  cout << "Point B: " << p2 << "\n";
  cout << "Distance: " << p1.dist(p2) << "\n";
  cout << "Sum: " << p1 + p2 << "\n";
  cout << "Scalar product (x2) of B: " << 2 * p2 << "\n";

  Vector<double> v1(p1);
  Vector<double> v2(p2);

  cout << "\n--- Vectores ---\n";
  cout << "Vector A: " << v1 << "\n";
  cout << "Vector B: " << v2 << "\n";
  cout << "Dot product: " << v1.dot_product(v2) << "\n";
  cout << "Cross product: " << v1.cross_product(v2) << "\n";
  cout << "Sum: " << v1 + v2 << "\n";
  cout << "Scalar product (x3) of A: " << 3 * v1 << "\n";

  cout << "\n--- Polígonos ---\n";

  vector<Punto<double>> vertices = {
      Punto<double>(0.9, 3.3), Punto<double>(1.7, 5.4),
      Punto<double>(3.1, 7.2), Punto<double>(5.2, 8.8),
      Punto<double>(4.5, 5.9), Punto<double>(6.7, 4.5),
      Punto<double>(7.3, 2.9), Punto<double>(5.8, 1.2),
      Punto<double>(2.1, 1.5)};
  Poligono<double> poly(vertices);

  cout << "Polígono: " << poly << "\n";
  cout << "Cantidad de vértices: " << poly.length() << "\n";
  cout << "Tercer vértice: " << poly[2] << "\n";
  cout << "¿Es CCW?: " << boolalpha << poly.CCW() << "\n";
  cout << "Área: " << poly.area() << "\n";

  poly.CW2CCW();

  cout << "\nPolígono pasó a sentido CCW\n";
  cout << "Polígono: " << poly << "\n";
  cout << "¿Es CCW?: " << boolalpha << poly.CCW() << "\n";
  cout << "Área: " << poly.area() << "\n";

  return 0;
}
