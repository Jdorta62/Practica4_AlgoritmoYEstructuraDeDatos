/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file sllpolynomial.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 11 april 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 4 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);
  void Scalar(SllPolynomial&, const double scalar);
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
/**
 * @brief constructor de la clase SllPolynomial.
 */
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  SllPolyNode* node;
  for (int i = v.get_size(); i > 0; --i) {
    int real_pos = i-1;
    if (IsNotZero(v.get_val(real_pos),eps)) {
      pair_double_t pair(v.get_val(real_pos), real_pos);
      node = new SllPolyNode;
      node->set_data(pair);
      push_front(node);
    }
  }
}

/**
 * @brief método que permite escribir en pantalla objetos de la clase SllPolynomial.
 */
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
/**
 * @brief método que permite evaluar un polinomio dandole un valor determinado a la x.
 */
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  SllPolyNode* aux = get_head();
  while (aux != NULL) {
    pair_double_t temp_pair(aux->get_data());
    result = result + ((temp_pair.get_val())*(pow(x,temp_pair.get_inx())));
    aux = aux->get_next();
  }
  return result;
}

/**
 * @brief método que permite la comprobar si dos polinomios implementados en listas enlazadas son iguales.
 */
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol, const double eps) const {
  bool differents = false;
  SllPolyNode* aux1 = get_head();
  SllPolyNode* aux2 = sllpol.get_head();
  unsigned int size_list1{0};
  unsigned int size_list2{0};
  while (aux1 != NULL) {
    ++size_list1;
    aux1 = aux1->get_next();
  }
  while (aux2 != NULL) {
    ++size_list2;
    aux2 = aux2->get_next();
  }
  if (size_list1 != size_list2) {
    differents = true;
  } else {
    aux1 = get_head();
    aux2 = sllpol.get_head();
    while ((aux1 != NULL) && (differents == false)) {
      pair_double_t pair1 (aux1->get_data());
      pair_double_t pair2 (aux2->get_data());

      if (pair1.get_val() != pair2.get_val()) differents = true;
      
      if (pair1.get_inx() != pair2.get_inx()) differents = true;
      
      aux1 = aux1->get_next();
      aux2 = aux2->get_next();
    }
  }
  return !differents;
} 
/**
 * @brief método que permite la suma de 2 listas con polinomios.
 * @param sllpol 2do sumando (el primero es el que invoca el método).
 * @param sllpolsum objeto de la clase SllPolynomial que va almacenar el resultado de la suma.
 */
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum, const double eps) {

/** 
 * Bloque #1
 * Se declaran nodos auxiliares, y enteros sin signo. Los nodos auxiliares recorrerán la lista
 * y las variables enteras contabilizarán el tamaño de la lista.
 */
 
  SllPolyNode* aux1 = get_head();
  SllPolyNode* aux2 = sllpol.get_head();
  unsigned int size_list1{1};
  unsigned int size_list2{1};

  while (aux1 != NULL) {
    ++size_list1;
    aux1 = aux1->get_next();
  }
  
  while (aux2 != NULL) {
    ++size_list2;
    aux2 = aux2->get_next();
  }
  
/** 
 * Bloque #2
 * Se declaran 3 vectores que almacenaran el contenido de las listas 1, 2 y resultante respectivamente.
 * Con los contadores del bloque 1, se determinan el tamaño de los vectores.
 */
  vector_t<pair_double_t> vector1;
  vector_t<pair_double_t> vector2;
  vector_t<double> vector_result;

  if (size_list1 <= size_list2) {
    vector1.resize(size_list2);
    vector2.resize(size_list2);
  } else {
    vector1.resize(size_list1);
    vector2.resize(size_list1); 
  }
  
/**
 * Bloque #3
 * En este bloque se pasan los pares de la lista a los vectores.
 */
  int index{0};
  aux1 = get_head();
  aux2 = sllpol.get_head();
  while (aux1 != NULL || aux2 != NULL) {
    if (aux1 != NULL) {
      pair_double_t pair1{aux1->get_data()};
      vector1[index] = pair1;
      aux1 = aux1->get_next();
    }
    if (aux2 != NULL) {
      pair_double_t pair2{aux2->get_data()};
      vector2[index] = pair2;
      aux2 = aux2->get_next();
    }
    ++index;
  }
  
/**
 * Bloque #4
 * En este bloque se da el tamaño al vector que almacenará el resultado de la suma. El tamaño del vector
 * viene dado por el mayor grado del polinomio
 */
  pair_double_t temp_pair(vector1[index -1]);
  pair_double_t temp_pair2(vector2[index-1]);
  int size1 = temp_pair.get_inx()+1;
  int size2 = temp_pair2.get_inx()+1;
  size1 < size2 ? vector_result.resize(size2) : vector_result.resize(size1);
  
/**
 * Bloque #5
 * En este bucle se suman los coeficientes de los polinomio (pair_result.get_val()) y se almacenan en el vector resultante.
 */
  for (unsigned int i{0}; i < vector_result.get_size(); ++i) {
    pair_double_t pair_result (vector_result[i],i);
    for (unsigned int j{0}; j < vector1.get_size(); ++j)  { 
      pair_double_t pair1 = vector1[j];
      pair_double_t pair2 = vector2[j];
      if (pair1.get_inx() == i) {
        pair_result.set(pair_result.get_val()+pair1.get_val(), i);
      }
      if (pair2.get_inx() == i) {
        pair_result.set(pair_result.get_val()+pair2.get_val(), i);
      }
    }
    vector_result[i] = pair_result.get_val();
  }
 
/**
 * Bloque #6
 * Aquí se construye la lista a apartir del vector que contiene los coeficientes. El grado viene dado por la posición que
 * ocupa dentro del vector.
 */
  SllPolyNode* node;
  for (int i = vector_result.get_size(); i > 0; --i) {
    int real_pos = i-1;
    if (IsNotZero(vector_result.get_val(real_pos),eps)) {
      pair_double_t pair(vector_result.get_val(real_pos), real_pos);
      node = new SllPolyNode;
      node->set_data(pair);
      sllpolsum.push_front(node);
    }
  }

}

/**
 * @brief modicfiación
 */
void SllPolynomial::Scalar(SllPolynomial& sllpscalar, const double scalar) {
  SllPolyNode* aux = get_head();
  SllPolyNode* node;
  SllPolyNode* node_temp;
  bool primero = true;
  while (aux != NULL) {
      pair_double_t temp_pair{aux->get_data()};
      double coeficiente = temp_pair.get_val();
      coeficiente = scalar * coeficiente;
      int indice = temp_pair.get_inx();
      temp_pair.set(coeficiente,indice);
      node = new SllPolyNode;
      node->set_data(temp_pair);
      if (primero == true ) {
        sllpscalar.push_front(node);
        primero = false;
      } else {
        sllpscalar.insert_after(node_temp, node);
      }
      node_temp = node;
      aux = aux->get_next();
    }
}

#endif  // SLLPOLYNOMIAL_H_
