#include "baleni.h"

int Baleni::Input = 0;
Facility Baleni::F("Baleni");

Baleni::Baleni(/* args */)
{
}

Baleni::~Baleni()
{
}

void Baleni::Behavior(){
     Seize(F);
     if(Input == 0){
          std::cerr << "ziadny vstup - baleni" << std::endl;
          Release(F);
          return;
     }
     Wait(Utils::normalMinMax(7, 13));
     Input--;
     std::cout << "balicek zabaleny" << std::endl;
     Release(F);
}