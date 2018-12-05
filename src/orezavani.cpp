#include "orezavani.h"

     int Orezavani::Input = 0;
     int Orezavani::Sumtime = 0;
     Facility Orezavani::orezavani("Orezavani");
     Stat Orezavani::Fstat("Orezavani");
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
          double t = Time;
          if(Input == 0)
          {
               Release(orezavani);
               std::cerr<<"Orezávání potřebuje oplatky"<<std::endl;
               return;
          }
          Wait(Uniform(5,9));
          Input--;
          t = Time-t;
          Fstat(t);
          Sumtime += t;
          Release(orezavani);
          tmp->InputOrezavani++;
          tmp->Activate();
          std::cout<<"Oplatek orezany"<<std::endl;
     }
