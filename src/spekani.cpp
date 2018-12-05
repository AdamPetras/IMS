#include "spekani.h"

Facility Spekani::F("Spekani");
int Spekani::Input = 0;

Spekani::Spekani(/* args */)
{
}

Spekani::~Spekani()
{
}

void Spekani::Behavior(){
     Seize(F);
     Wait(45);
     Vazeni::InputSpekani++;
     Release(F);
     (new Vazeni())->Activate();
}