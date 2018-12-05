#include "sypani.h"

Facility Sypani::F("Sypani");
Stat Sypani::Fstat("Sypani");
double Sypani::Sumtime = 0;

Sypani::Sypani(/* args */)
{
}

Sypani::~Sypani()
{
}

void Sypani::Behavior(){
     Seize(F);
     double t = Time;
     if (Vlhceni::Output < 2){
          Release(F);
          std::cerr << "Nedostatocna kapacita pre sypani: " << Vlhceni::Output << std::endl;
          return;
     }
     Vlhceni::Output -= 2;
     Wait(Uniform(4, 15));
     Spekani::Input++;
     std::cout << ">>>>>> Sypani hotovo" << std::endl;
     (new Sypani())->Activate();
     t = Time - t;
     Fstat(t);
     Sumtime += t;
     Release(F);
     (new Spekani())->Activate();
}