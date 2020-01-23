#include "Circuit.h"

Circuit::Circuit()
  :nets{}{}

void Circuit::push_back(Component* const net){
  nets.push_back(net);
}

void Circuit::Simulation(int const iteration, double const time, int const lines){

 for(Component* comp : nets){
    cout<<setw(12);
    cout<< comp->getName();
  }
  cout<<endl;
  for(Component* comp : nets){
    cout<<setw(6);
    cout<<"Volt";
    cout<<setw(6);
    cout<<"Curr";
  }
  cout<<endl;


  double count {0};
  for (int i=0; i<=iteration; i++){
    for (Component* comp : nets){
      comp->Simulation(time);
    }
    if(i == (count + (iteration/lines))){
    cout<<fixed;
    cout<<setprecision(2);
    for(Component* comp: nets){
     cout<<setw(6);
     cout<<comp->GetVolt();
	    cout<<setw(6);
	    cout<<comp->GetCurr();
    }
    cout<<endl;

      count += (iteration/lines); 
    }
  }
  cout<<endl;
  }
