#ifndef COMPONENT_H
#define COMPONENT_H
#include "Connection.h"
#include <string>
#include <iostream>
#include <iomanip>

class Component{

 protected:
  Connection* p;
  Connection* n;
  std::string name;
 public:
  
  Component(std::string const name, Connection* const p1, Connection* const n1);
  virtual ~Component(); //fixed added a virtual destructors
  virtual void Simulation(double const  time);
  double GetVolt() const;
  virtual double GetCurr() const;
  std::string getName() const;
  
};


class Battery: public Component {
 public:
  double volt{};
  Battery(std::string const name, double const volt, Connection* const p1, Connection* const n1);
  ~Battery();
  void Simulation(double const time);
 
};


class Resistor : public Component{
 public:
  double ohm;
  Resistor(std::string const name, double const ohm, Connection* const p1, Connection* const n1);
  ~Resistor();
  void Simulation(double const time);
  double GetCurr() const;
  
};


class Capacitor : public Component{
 public:
  double storage;
  double capacy;
  Capacitor(std::string name, double const capacy, Connection* const p1, Connection* const n1);
  ~Capacitor();
  void Simulation(double time);
  double GetCurrent() const ;
  
};


#endif
