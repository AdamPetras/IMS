#include "baleni.h"

int Baleni::Input = 0;

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

     Release(F);
}