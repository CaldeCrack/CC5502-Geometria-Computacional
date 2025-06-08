#include "GiftWrappingAlgorithm.cpp"
#include "IncrementalAlgorithm.cpp"
#include "RandomCHPoints.cpp"
#include "RandomColinealPoints.cpp"
#include "RandomPoints.cpp"
#include <chrono>
#include <fstream>

using namespace std;

// - Variables globales
// Double
GiftWrappingAlgorithm<double> gift;
IncrementalAlgorithm<double> incremental;
RandomPoints<double> randomPoints;
RandomCHPoints<double> randomCHPoints;
RandomColinealPoints<double> randomColinealPoints;

// Integers
GiftWrappingAlgorithm<int> intGift;
IncrementalAlgorithm<int> intIncremental;
RandomColinealPoints<int> intRandomColinealPoints;

void experiment(int n, double k, std::ofstream &outfile) {
  // Variables iniciales
  double time;
  auto start = std::chrono::high_resolution_clock::now();
  auto end = std::chrono::high_resolution_clock::now();

  // - Puntos aleatorios
  Point<double> *points = randomPoints.generate(n, k);
  string pointsType = "default";
  if (k <= 0.03) { // Ejecutar solo para el primer k, el resto sería redundante
    // Gift Wrapping
    start = std::chrono::high_resolution_clock::now();
    Polygon<double> giftCH = gift.apply(points, n);
    end = std::chrono::high_resolution_clock::now();
    time = (double)std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
               .count();
    // Para este caso k = 0% en la cerradura convexa
    outfile << pointsType << ",gift wrap," << n << ',' << giftCH.length()
            << ",0," << time << '\n';

    // Incremental
    start = std::chrono::high_resolution_clock::now();
    Polygon<double> incrementalCH = incremental.apply(points, n);
    end = std::chrono::high_resolution_clock::now();
    time = (double)std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
               .count();
    // Para este caso k = 0% en la cerradura convexa
    outfile << pointsType << ",incremental," << n << ','
            << incrementalCH.length() << ",0," << time << '\n';
  }

  // - Puntos aleatorios con porcentaje k en la cerradura convexa
  points = randomCHPoints.generate(n, k);
  pointsType = "CC%";

  // Gift Wrapping
  start = std::chrono::high_resolution_clock::now();
  Polygon<double> giftCH = gift.apply(points, n);
  end = std::chrono::high_resolution_clock::now();
  time =
      (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  outfile << pointsType << ",gift wrap," << n << ',' << giftCH.length() << ','
          << k << ',' << time << '\n';

  // Incremental
  start = std::chrono::high_resolution_clock::now();
  Polygon<double> incrementalCH = incremental.apply(points, n);
  end = std::chrono::high_resolution_clock::now();
  time =
      (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  outfile << pointsType << ",incremental," << n << ',' << incrementalCH.length()
          << ',' << k << ',' << time << '\n';

  // - Puntos aleatorios colineales
  // Números enteros
  Point<int> *intPoints = intRandomColinealPoints.generate(n, k);
  pointsType = "colineal int";

  // Gift Wrapping
  start = std::chrono::high_resolution_clock::now();
  Polygon<int> intGiftCH = intGift.apply(intPoints, n);
  end = std::chrono::high_resolution_clock::now();
  time =
      (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  outfile << pointsType << ",gift wrap," << n << ',' << intGiftCH.length()
          << ',' << k << ',' << time << '\n';

  // Incremental
  start = std::chrono::high_resolution_clock::now();
  Polygon<int> intIncrementalCH = intIncremental.apply(intPoints, n);
  end = std::chrono::high_resolution_clock::now();
  time =
      (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  outfile << pointsType << ",incremental," << n << ','
          << intIncrementalCH.length() << ',' << k << ',' << time << '\n';

  // Números reales
  points = randomColinealPoints.generate(n, k);
  pointsType = "colineal double";

  // Gift Wrapping
  start = std::chrono::high_resolution_clock::now();
  giftCH = gift.apply(points, n);
  end = std::chrono::high_resolution_clock::now();
  time =
      (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  outfile << pointsType << ",gift wrap," << n << ',' << giftCH.length() << ','
          << k << ',' << time << '\n';

  // Incremental
  start = std::chrono::high_resolution_clock::now();
  incrementalCH = incremental.apply(points, n);
  end = std::chrono::high_resolution_clock::now();
  time =
      (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  outfile << pointsType << ",incremental," << n << ',' << incrementalCH.length()
          << ',' << k << ',' << time << '\n';
}

int main() {
  // CSV para guardar los tiempos
  std::ofstream outfile("experiment.csv");
  if (!outfile) {
    std::cerr << "Fallo en abrir experiment.csv para escritura.\n";
    return 1;
  }
  outfile << "Puntos,Algoritmo,Tamaño,Tamaño CC,CC%,Tiempo[μs]\n";

  // Experimentación
  std::cout << "- Ejecución actual:\n";
  for (int exp = 2; exp <= 5; ++exp)
    for (double k = 0.02; k <= 0.1; k += 0.02) {
      std::cout << "n: 10^" << exp << " | k: " << k << '\n';
      experiment((int)std::pow(10, exp), k, outfile);
    }
  outfile.close();
  return 0;
}
