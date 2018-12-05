#include "orezavani.h"

     int Orezavani::Input = 0;
     Orezavani::Orezavani(/* args */)
     {
     }

     Orezavani::~Orezavani()
     {
     }
     void Orezavani::Behavior()
     {
          Vazeni *tmp = new Vazeni;
          Seize(orezavani);
          if(Input == 0)
          {
               Release(orezavani);
               std::cerr<<"Orezávání potřebuje oplatky"<<std::endl;
               return;
          }
          Wait(Utils::normalMinMax(5,9));
          Input--;
          Release(orezavani);
          tmp->InputOrezavani++;
          tmp->Activate();
     }
