#include "auto_spekani.h"

Facility AutoSpekani::F("Auto_spekani");

AutoSpekani::AutoSpekani(/* args */)
{
     Priority = 1;
}

AutoSpekani::~AutoSpekani()
{
}

void AutoSpekani::Behavior()
{
     Seize(F);
     if (Vlhceni::Output < 2){
          Release(F);
          std::cerr << "Nedostatocna kapacita pre auto_spekani" << std::endl;
          return;
     }
     Vlhceni::Output -= 2;
     Wait(45);
     Vazeni::InputSpekani++;

     d = Uniform(0, 100);
     if (d < 0.00372){
          // treba opravit stroj
          (new AutoSpekani)->Activate(Time + Utils::normalMinMax(5*60, 60*60));
     }else
          (new AutoSpekani)->Activate();
     std::cout << "Autospekani hotovo" << std::endl;
     Release(F);

}
