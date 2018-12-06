#include "sypani.h"

Facility Sypani::F("Sypani");
Stat Sypani::Fstat("Sypani");
double Sypani::Sumtime = 0;
bool Sypani::IsRunning = false;

Sypani::Sypani(/* args */)
{
}

Sypani::~Sypani()
{
}

void Sypani::Behavior(){
     Seize(F);
     IsRunning = true;
     double t = Time;
     if (Vlhceni::Output < 2){
          Release(F);
          IsRunning = false;
          return;
     }
     Vlhceni::Output -= 2;
     Wait(Uniform(4, 15));
     Spekani::Input++;
     t = Time - t;
     Fstat(t);
     Sumtime += t;
     (new Sypani())->Activate();
     Release(F);
     (new Spekani())->Activate();
}