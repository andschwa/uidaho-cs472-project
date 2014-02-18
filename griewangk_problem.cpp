/* Copyright 2014 Andrew Schwartzmeyer
 *
 * Source file for griewangk problem derived class
 */

#include <cmath>

#include "griewangk_problem.hpp"

parameter Griewangk::problem(const Individual & subject) const {
  parameter sum = 0;
  parameter product = 1;
  for (unsigned long i = 0; i < subject.size(); ++i) {
    sum += std::pow(subject[i], 2) / 4000.;
    // i from 1 to p
    product *= std::cos(subject[i] / std::sqrt(i + 1));
  }
  return 1 + sum - product;
}
