/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file main_sllpolynomial
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 11 april 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 4 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */
#include <iostream>

#include "sllpolynomial.h"

using namespace std;

int main() {
  vector_t<double> v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  cout << "v1= " << v1;
  cout << "v2= " << v2;
  cout << "v3= " << v3;
  cout << endl;

  // Fase II
  SllPolynomial sllp1(v1), sllp2(v2), sllp3(v3);
  cout << "sllp1= " << sllp1;
  cout << "sllp2= " << sllp2;
  cout << "sllp3= " << sllp3;
  cout << endl;

  // Fase III
  double x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  cout << "sllp1(" << x1 << ")= " << sllp1.Eval(x1) << endl;
  cout << "sllp1(" << x2 << ")= " << sllp1.Eval(x2) << endl;
  cout << "sllp1(" << x3 << ")= " << sllp1.Eval(x3) << endl;
  cout << "sllp2(" << x1 << ")= " << sllp2.Eval(x1) << endl;
  cout << "sllp2(" << x2 << ")= " << sllp2.Eval(x2) << endl;
  cout << "sllp2(" << x3 << ")= " << sllp2.Eval(x3) << endl;
  cout << "sllp3(" << x1 << ")= " << sllp3.Eval(x1) << endl;
  cout << "sllp3(" << x2 << ")= " << sllp3.Eval(x2) << endl;
  cout << "sllp3(" << x3 << ")= " << sllp3.Eval(x3) << endl;
  cout << endl;

  cout << "sllp1 == sllp1? " << (sllp1.IsEqual(sllp1) ? "true" : "false")
       << endl;
  cout << "sllp2 == sllp2? " << (sllp2.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp3? " << (sllp3.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp1 == sllp2? " << (sllp1.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << "sllp2 == sllp1? " << (sllp2.IsEqual(sllp1) ? "true" : "false")
       << endl;
  cout << "sllp1 == sllp3? " << (sllp1.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp1? " << (sllp3.IsEqual(sllp1) ? "true" : "false")
       << endl;
  cout << "sllp2 == sllp3? " << (sllp2.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp2? " << (sllp3.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << endl;

  // Fase IV
  SllPolynomial sllpsum12, sllpsum23;
  sllp1.Sum(sllp2, sllpsum12);
  cout << "sllp1 + sllp2= " << sllpsum12;
  sllp2.Sum(sllp3, sllpsum23);
  cout << "sllp2 + sllp3= " << sllpsum23;

  cout << "Modificación: " << std::endl;
  SllPolynomial sllpscalar;
  double scalar = 1;
  sllp1.Scalar(sllpscalar,scalar);
  std::cout << "Polinomio Escalar: " << sllpscalar << std::endl;

  return 0;
}
