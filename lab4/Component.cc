#include "Component.h"
using namespace std;

Component::Component(string const name,  Connection* const p1, Connection* const n1)
  :name{name}, p{p1}, n{n1}{
}

void Component::Simulation(double time){
}

double Component::GetVolt() const {
  return abs(p->voltage - n->voltage);
}

double Component::GetCurr() const{
}

Component::~Component() {}

string Component::getName() const {
  return name;
}

////////*****BATTERY****\\\\\\\\\\


Battery::Battery(string const name, double const volt, Connection* const p1, Connection* const n1): Component(name, p1, n1), volt{volt}{
}

void Battery::Simulation (double const time){
  p->voltage = volt;
  n->voltage = 0;
  }
 Battery::~Battery() {}



////////*****RESISTOR****\\\\\\\\\\

Resistor::Resistor(string const name, double const ohm, Connection* const p1, Connection* const n1): Component(name, p1, n1), ohm{ohm}{
}

void Resistor::Simulation(double const time){
    double newVolt{(GetVolt() / ohm) * (time)};
    
    if(p->voltage > n->voltage){
    p->voltage -=  newVolt;
    n->voltage +=  newVolt;
    }
    else {
      p->voltage +=  newVolt;
      n->voltage -=  newVolt;
      }
}
double Resistor::GetCurr() const {
    return (GetVolt() / ohm);
}

Resistor::~Resistor() {}

////////*****CAPACITOR****\\\\\\\\\\


Capacitor::Capacitor(string name, double const capacy1, Connection* const p1, Connection* const n1): Component(name, p1, n1), capacy{capacy1}, storage{}{
}

void Capacitor::Simulation(double time){
  double newVolt{(GetVolt() - storage) * capacy * (time)};
  int direction{((p->voltage <= n->voltage) ? 1 : -1)};
  p->voltage += direction * newVolt;
  n->voltage -= direction * newVolt;
  storage += newVolt;
}

Capacitor::~Capacitor() {}
double Capacitor::GetCurrent() const {
    return (capacy * (GetVolt() - storage));
}
