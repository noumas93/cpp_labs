#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Component.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Circuit{
 public:
  Circuit();
  vector<Component*> nets;
  void push_back(Component* const net);
  void Simulation(int const iteration, double const time, int const lines);
  void clear(vector<Component*> net) const;
};
#endif
