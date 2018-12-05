#include "vazeni.h"

Facility Vazeni::F = Facility("Vazeni");

Vazeni::Vazeni(/* args */)
{
}

Vazeni::~Vazeni()
{
}

void Vazeni::Behavior()
{
     Seize(F);
     if (InputSpekani == 0 && InputOrezavani == 0){
          std::cerr << "ziadny vstup - vazeni" << std::endl;
          Release(F);
          return;
     }
     if (InputSpekani < 8 || InputOrezavani < 8){
          std::cerr << "nedostatocny vstup vstup - vazeni" << std::endl;
          Release(F);
          return;
     }
     if (InputSpekani > 8 && InputOrezavani > 8)
     {
          d = Uniform(0, 99);
          if (d < 50.0)
          {
               Fspekani = true;
               InputSpekani -= 8;
          }
          else
               InputOrezavani -= 8;
     }
     else
     {
          if (InputSpekani > 0)
          {
               Fspekani = true;
               InputSpekani -= 8;
          }
          else
               InputOrezavani -= 8;
     }
     Wait(Utils::normalMinMax(5, 17));
     Release(F);

     d = Uniform(0, 99);
     if (d < 0.3)
     {
          if (Fspekani)
               InputSpekani += 7;
          else
               InputOrezavani += 7;
     }
     else
     {
          Baleni::Input += 1;
          (new Baleni)->Activate();
     }
}