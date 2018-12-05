#include "baleni.h"

int Baleni::Input = 0;
Facility Baleni::F("Baleni");
Stat Baleni::Fstat("Baleni");
double Baleni::Sumtime = 0;

Baleni::Baleni(/* args */)
{
}

Baleni::~Baleni()
{
}

void Baleni::Behavior(){
     Seize(F);
     double t = Time;
     if(Input == 0){
          std::cerr << "ziadny vstup baleni" << std::endl;
          Release(F);
          return;
     }
     Wait(Uniform(7, 13));
     Input--;
     std::cout << "balicek zabaleny" << std::endl;
     t = Time - t;
     Fstat(t);
     Sumtime += t;
     Release(F);
}