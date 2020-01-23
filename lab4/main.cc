#include <iostream>
#include "Circuit.h"
#include "Connection.h"

void run(int const iteration, int const lines, double const time, double const volt) {
  Connection p, r124, r23, n;
  Circuit circ{};

  circ.push_back(new Battery ("Bat", volt, &p, &n));
  circ.push_back(new Resistor ("R1", 6.0, &p, &r124));
  circ.push_back(new Resistor ("R2", 4.0, &r124, &r23));
  circ.push_back(new Resistor ("R3", 8.0, &r23, &n));
  circ.push_back(new Resistor ("R4", 12.0, &r124, &n));

  circ.Simulation(iteration, time, lines);
}

void run1(int const iteration, int  const lines, double const time, double const volt) {
  Connection l, p, r, n;
  Circuit circ{};
  circ.push_back(new Battery("Bat", volt, &p, &n));
  circ.push_back(new Resistor("R1", 150.0, &p, &l));
  circ.push_back(new Resistor("R2", 50.0, &p, &r));
  circ.push_back(new Resistor("R3", 100.0, &l, &r));
  circ.push_back(new Resistor("R4", 300.0, &l, &n));
  circ.push_back(new Resistor("R5", 250.0, &r, &n));
    
  circ.Simulation(iteration, time, lines);
}

void run2(int const iteration, int const lines, double const time, double const volt) {
  Circuit circ{};
  Connection p, n, l, r;
  circ.push_back(new Battery("Bat", volt, &p, &n));
  circ.push_back(new Resistor("R1", 150.0, &p, &l));
  circ.push_back(new Resistor("R2", 50.0, &p, &r));
  circ.push_back(new Capacitor("C3", 1.0, &l, &r));
  circ.push_back(new Resistor("R4", 300.0, &l, &n));
  circ.push_back(new Capacitor("C5", 0.75, &r, &n));
  circ.Simulation(iteration, time, lines);
}

int main(int argc,char** argv)

{
  try{
    double iteration = stoi(argv[1]);
    double lines = stoi(argv[2]);
    double time = stod(argv[3]);
    double volt = stod(argv[4]);
    run(iteration, lines, time, volt);
    run1(iteration, lines, time, volt);
    run2(iteration, lines, time, volt);
  }
  catch (...){
    cout << "Error! You must  enter: ./a.out iterations(int) lines(int) timestep(double) battery volt (double)" <<endl;
  } }
