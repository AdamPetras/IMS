#include "vazeni.h"

int Vazeni::InputSpekani = 0;
int Vazeni::InputOrezavani = 0;
Facility Vazeni::F("Vazeni");
Stat Vazeni::Fstat("Vazeni");
double Vazeni::Sumtime = 0;

Vazeni::Vazeni(/* args */)
{
}

Vazeni::~Vazeni()
{
}

void Vazeni::Behavior()
{
     Seize(F);
     if (Vazeni::InputSpekani == 0 && Vazeni::InputOrezavani == 0)
     {
          Release(F);
          return;
     }
     if (Vazeni::InputSpekani < 8 && Vazeni::InputOrezavani < 8)
     {
          Release(F);
          return;
     }
     double t = Time;
     if (Vazeni::InputSpekani >= 8 && Vazeni::InputOrezavani >= 8)
     {
          d = Uniform(0, 99);
          if (d < 50.0)
          {
               Fspekani = true;
               Vazeni::InputSpekani -= 8;
          }
          else
               Vazeni::InputOrezavani -= 8;
     }
     else
     {
          if (Vazeni::InputSpekani >= 8)
          {
               Fspekani = true;
               Vazeni::InputSpekani -= 8;
          }
          else
               Vazeni::InputOrezavani -= 8;
     }
     Wait(Uniform(5, 17));

     d = Uniform(0, 99);
     if (d < 0.3)
     {
          if (Fspekani)
               Vazeni::InputSpekani += 7;
          else
               Vazeni::InputOrezavani += 7;
     }
     else
     {
          Baleni::Input += 1;
          (new Baleni)->Activate();
     }
     t = Time - t;
     Fstat(t);
     Sumtime += t;
     Release(F);
}