#include "spekani.h"

Facility Spekani::F("Spekani");
int Spekani::Input = 0;
Stat Spekani::Fstat("Spekani");
Histogram Spekani::Fhist("Spekani", 0, 60*60*24,  Globals::TTL/(60*60*24));
double Spekani::Sumtime = 0;

Spekani::Spekani(/* args */)
{
}

Spekani::~Spekani()
{
}

void Spekani::Behavior()
{
     const int PLOTYNKY = 8;
     Seize(F);
     if(Spekani::Input < 2){
          Release(F);
          return;
     }
     Fhist(Time);
     double t = Time;
     Wait(45/PLOTYNKY);
     Spekani::Input -= 2;
     Vazeni::InputSpekani += 1;
     t = Time - t;
     Fstat(t);
     Sumtime += t;
     Release(F);
     (new Vazeni())->Activate();
}